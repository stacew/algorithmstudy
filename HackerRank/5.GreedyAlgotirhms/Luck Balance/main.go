package main

import (
	"fmt"
	"sort"
	"strconv"
)

//3번째 대회에서 이기고, 다른 5번의 대회에서 모두 지는 행운 최대값 구하기.
//k번 이상 질수 없음.
//L 행운양 , T 중요도
//중요한 것 중 5번까지 질수 있다. => 최소 + 5
//중요하지 않으면 질거다 => 0은 다 질거니까 더하기
// 13 1 //지자
// 10 1
// 9 1
// 8 1
// 13 1 //지자
// 12 1 //지자
// 18 1//지자
// 13 1 //지자

func luckBalance(k int32, contests [][]int32) int32 {
	sort.Slice(contests, func(i, j int) bool {
		if contests[i][1] != contests[j][1] { //0을 앞으로
			return contests[i][1] < contests[j][1]
		}
		return contests[i][0] > contests[j][0] //큰걸 앞으로
	})

	var total int32
	for i := 0; i < len(contests); i++ {
		if contests[i][1] == 0 {
			total = total + contests[i][0]
		} else if k > 0 {
			total = total + contests[i][0]
			k--
		} else {
			total = total - contests[i][0]
		}
	}
	return total
}

func main() {
	fmt.Println(strconv.Itoa(int(luckBalance(3, [][]int32{
		{5, 1}, {2, 1}, {1, 1}, {8, 1}, {10, 0}, {5, 0}})))) //29
}
