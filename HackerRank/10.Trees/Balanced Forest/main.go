package main

import (
	"fmt"
	"math"
)

func debugPrintln(s string) {
	fmt.Println(s)
}

type node struct {
	value      int64
	edge       []int32
	checkDfs   bool
	checkSolve bool
}

func dfsSumTree(tree []node, a int32) int64 {
	if tree[a].checkDfs {
		return 0
	}
	tree[a].checkDfs = true

	for _, value := range tree[a].edge {
		tree[a].value = tree[a].value + dfsSumTree(tree, value)
	}

	return tree[a].value
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
	tree := make([]node, lenC)
	for i := 0; i < lenC; i++ {
		tree[i].value = int64(c[i])
	}
	c = nil

	for i := 0; i < lenEdges; i++ {
		tree[edges[i][0]].edge = append(tree[edges[i][0]].edge, edges[i][1])
		tree[edges[i][1]].edge = append(tree[edges[i][1]].edge, edges[i][0])
	}

	debugPrintln("0")
	var min = dfsSumTree(tree, 0)
	debugPrintln("1")
	/////////////////////////////
	/////////////////////////////

	debugPrintln("2")
	//8. 결과
	if min == math.MaxInt32 {
		return -1
	}
	return int32(min)
}

func main() {
	// //2
	// fmt.Println(balancedForest([]int32{1, 2, 2, 1, 1}, [][]int32{
	// 	{1, 2},
	// 	{1, 3},
	// 	{3, 5},
	// 	{1, 4}}))

	//10
	fmt.Println(balancedForest([]int32{1, 1, 1, 18, 10, 11, 5, 6}, [][]int32{
		{1, 2},
		{1, 4},
		{2, 3},
		{1, 8},
		{8, 7},
		{7, 6},
		{5, 7}}))

	// //13
	// fmt.Println(balancedForest([]int32{12, 7, 11, 17, 20, 10}, [][]int32{
	// 	{1, 2},
	// 	{2, 3},
	// 	{4, 5},
	// 	{6, 5},
	// 	{1, 4}}))
}

// func main() {
// 	// 1357940809
// 	// 397705399909
// 	// 439044899265
// 	// 104805614260
// 	// -1
// 	file, _ := os.Open("test.txt")
// 	defer file.Close()

// 	reader := bufio.NewReaderSize(file, 1024*1024)
// 	q, _ := strconv.ParseInt(readLine(reader), 10, 64)

// 	for qItr := 0; qItr < int(q); qItr++ {

// 		nTemp, _ := strconv.ParseInt(readLine(reader), 10, 64)
// 		n := int32(nTemp)

// 		cTemp := strings.Split(readLine(reader), " ")

// 		var c []int32
// 		for i := 0; i < int(n); i++ {
// 			cItemTemp, _ := strconv.ParseInt(cTemp[i], 10, 64)
// 			cItem := int32(cItemTemp)
// 			c = append(c, cItem)
// 		}

// 		var edges [][]int32
// 		for i := 0; i < int(n)-1; i++ {

// 			edgesRowTemp := strings.Split(readLine(reader), " ")

// 			var edgesRow []int32
// 			for _, edgesRowItem := range edgesRowTemp {
// 				edgesItemTemp, _ := strconv.ParseInt(edgesRowItem, 10, 64)
// 				edgesItem := int32(edgesItemTemp)
// 				edgesRow = append(edgesRow, edgesItem)
// 			}

// 			if len(edgesRow) != 2 {
// 				panic("Bad input")
// 			}

// 			edges = append(edges, edgesRow)
// 		}

// 		result := balancedForest(c, edges)

// 		fmt.Println(result)
// 	}
// }

// func readLine(reader *bufio.Reader) string {
// 	str, _, err := reader.ReadLine()
// 	if err == io.EOF {
// 		return ""
// 	}

// 	return strings.TrimRight(string(str), "\r\n")
// }
