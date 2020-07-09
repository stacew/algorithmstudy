package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
	"sort"
	"strconv"
	"strings"
)

func debugPrint(s string) {
	fmt.Print(s)
}
func debugPrintln(s string) {
	fmt.Println(s)
}

type node struct {
	value    int64
	childMap map[int32]bool
}

func addChild(nodeArr []node, m1, m2 map[int32][]int32, used []bool, p, c int32) {
	if used[p] && used[c] {
		return
	} else if used[c] {
		p, c = c, p
	}
	nodeArr[p].childMap[c] = true
	used[c] = true

	if m1[c] != nil {
		for i := 0; i < len(m1[c]); i++ {
			addChild(nodeArr, m1, m2, used, c, m1[c][i])
		}
	}
	if m2[c] != nil {
		for i := 0; i < len(m2[c]); i++ {
			addChild(nodeArr, m1, m2, used, c, m2[c][i])
		}
	}
}
func sumSubtree(nodeArr []node, a int32) int64 {
	for key := range nodeArr[a].childMap {
		nodeArr[a].value = nodeArr[a].value + sumSubtree(nodeArr, key)
	}
	return nodeArr[a].value
}
func makeParent(nodeArr []node, pmm map[int32]map[int32]bool, p int32) {
	pmm[p] = make(map[int32]bool, len(nodeArr[p].childMap))
	for kChild := range nodeArr[p].childMap {
		pmm[p][kChild] = true
		makeParent(nodeArr, pmm, kChild)
	}
}
func makeIndex(nodeArr []node, index *[]int32, p int32) {
	*index = append(*index, p)
	for kChild := range nodeArr[p].childMap {
		makeIndex(nodeArr, index, kChild)
	}
}

func getDiffIs2Equal(a, b, c int64) int32 {
	if a == b {
		return int32(a - c)
	} else if b == c {
		return int32(b - a)
	}
	return -1
}

func isSubTree(pmm map[int32]map[int32]bool, a, b int32) bool {
	if pmm[a][b] {
		return true
	}
	return false
}
func sum3(nodeArr []node, pmm map[int32]map[int32]bool, a, b, c int32) int64 {
	var ret int64
	if isSubTree(pmm, b, c) {
		ret = nodeArr[a].value - nodeArr[b].value + nodeArr[c].value
	} else if isSubTree(pmm, c, b) {
		ret = nodeArr[a].value - nodeArr[c].value + nodeArr[b].value
	} else {
		ret = nodeArr[a].value - nodeArr[b].value - nodeArr[c].value
	}
	return ret
}
func sum2(nodeArr []node, pmm map[int32]map[int32]bool, b, c int32) int64 {
	var ret int64
	if isSubTree(pmm, b, c) {
		ret = nodeArr[b].value - nodeArr[c].value
	} else {
		ret = nodeArr[b].value
	}
	return ret
}

func balancedForest(c []int32, edges [][]int32) int32 {
	//0. 준비, 인덱스화
	lenC := len(c)
	lenEdges := len(edges)
	for i := 0; i < lenEdges; i++ {
		edges[i][0] = edges[i][0] - 1
		edges[i][1] = edges[i][1] - 1
	}
	//트리 정보 생성
	nodeArr := make([]node, lenC)
	for i := 0; i < lenC; i++ {
		nodeArr[i].value = int64(c[i])
		nodeArr[i].childMap = make(map[int32]bool)
	}
	c = nil
	debugPrint("1")
	//1. 무조건 0을 루트로 쓰기 위해 정렬
	for i := 0; i < lenEdges; i++ {
		if edges[i][0] > edges[i][1] {
			edges[i][0], edges[i][1] = edges[i][1], edges[i][0]
		}
	}

	debugPrint("2")
	//2. 무조건 0을 루트로 쓰기 위해 정렬2
	sort.Slice(edges, func(a, b int) bool { //오름차순
		return edges[a][0] < edges[b][0]
	})

	debugPrint("3")
	//3. 엣지 방향 조정을 위해 맵 2개 처리
	m1 := make(map[int32][]int32)
	m2 := make(map[int32][]int32)
	for i := 0; i < lenEdges; i++ {
		m1[edges[i][0]] = append(m1[edges[i][0]], edges[i][1])
		m2[edges[i][1]] = append(m2[edges[i][1]], edges[i][0])
	}
	edges = nil //하위도 nil해야되나..?? 나중에 Check

	debugPrint("4")
	//4. 트리 정보 생성
	used := make([]bool, lenC) //자식 노드는 또 자식으로 되지 않도록..
	used[0] = true
	for i := 0; i < len(m1[0]); i++ {
		addChild(nodeArr, m1, m2, used, 0, m1[0][i])
	}
	for i := 0; i < len(m2[0]); i++ {
		addChild(nodeArr, m1, m2, used, 0, m2[0][i])
	}
	m1 = nil
	m2 = nil

	debugPrint("5")
	//5. 하위트리 계산
	sumSubtree(nodeArr, 0)

	debugPrint("6")
	//6. 부모 정보맵 생성 -> todo 깊은 차원.. 처리 메모리.
	pmm := make(map[int32]map[int32]bool)
	makeParent(nodeArr, pmm, 0)

	debugPrint("7")
	//7. 순서대로 진행하기 위한 인덱스 정보
	index := make([]int32, 0, lenC)
	makeIndex(nodeArr, &index, 0)

	debugPrint("8")
	//8. 계산
	var min int32 = math.MaxInt32
	for i := 1; i < lenC; i++ {
		a := nodeArr[index[0]].value - nodeArr[index[i]].value
		b := nodeArr[index[i]].value
		if a == b {
			continue
		}
		for j := i + 1; j < lenC; j++ {
			aFix := a
			bFix := b
			c := nodeArr[index[j]].value
			if a > b {
				if isSubTree(pmm, index[i], index[j]) {
					continue
				}
				aFix = a - c
			} else { // b < a
				if isSubTree(pmm, index[i], index[j]) == false {
					continue
				}
				bFix = b - c
			}

			temp := getDiffIs2Equal(aFix, bFix, c)
			if temp > 0 && temp < min {
				min = temp
			}
		}
	}

	debugPrintln("8")
	//8. 결과
	if min == math.MaxInt32 {
		return -1
	}
	return min
}

func main() {
	// 1357940809
	// 397705399909
	// 439044899265
	// 104805614260
	// -1
	file, _ := os.Open("test.txt")
	defer file.Close()

	reader := bufio.NewReaderSize(file, 1024*1024)
	q, _ := strconv.ParseInt(readLine(reader), 10, 64)

	for qItr := 0; qItr < int(q); qItr++ {

		nTemp, _ := strconv.ParseInt(readLine(reader), 10, 64)
		n := int32(nTemp)

		cTemp := strings.Split(readLine(reader), " ")

		var c []int32
		for i := 0; i < int(n); i++ {
			cItemTemp, _ := strconv.ParseInt(cTemp[i], 10, 64)
			cItem := int32(cItemTemp)
			c = append(c, cItem)
		}

		var edges [][]int32
		for i := 0; i < int(n)-1; i++ {

			edgesRowTemp := strings.Split(readLine(reader), " ")

			var edgesRow []int32
			for _, edgesRowItem := range edgesRowTemp {
				edgesItemTemp, _ := strconv.ParseInt(edgesRowItem, 10, 64)
				edgesItem := int32(edgesItemTemp)
				edgesRow = append(edgesRow, edgesItem)
			}

			if len(edgesRow) != 2 {
				panic("Bad input")
			}

			edges = append(edges, edgesRow)
		}

		result := balancedForest(c, edges)

		fmt.Println(result)
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

// func main() {
// 	// //2
// 	// fmt.Println(balancedForest([]int32{1, 2, 2, 1, 1}, [][]int32{
// 	// 	{1, 2},
// 	// 	{1, 3},
// 	// 	{3, 5},
// 	// 	{1, 4}}))
// 	//10
// 	fmt.Println(balancedForest([]int32{1, 1, 1, 18, 10, 11, 5, 6}, [][]int32{
// 		{1, 2},
// 		{1, 4},
// 		{2, 3},
// 		{1, 8},
// 		{8, 7},
// 		{7, 6},
// 		{5, 7}}))
// 	// //13
// 	// fmt.Println(balancedForest([]int32{12, 7, 11, 17, 20, 10}, [][]int32{
// 	// 	{1, 2},
// 	// 	{2, 3},
// 	// 	{4, 5},
// 	// 	{6, 5},
// 	// 	{1, 4}}))
// }
