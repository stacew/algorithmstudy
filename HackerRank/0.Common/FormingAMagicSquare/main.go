package main

import "fmt"

var test = [...][9]int32{ //앞에만 생략 or ... 가능
	{8, 1, 6, 3, 5, 7, 4, 9, 2},
	{6, 7, 2, 1, 5, 9, 8, 3, 4},
	{2, 9, 4, 7, 5, 3, 6, 1, 8},
	{4, 3, 8, 9, 5, 1, 2, 7, 6},
	{6, 1, 8, 7, 5, 3, 2, 9, 4},
	{2, 7, 6, 9, 5, 1, 4, 3, 8},
	{4, 9, 2, 3, 5, 7, 8, 1, 6},
	{8, 3, 4, 1, 5, 9, 6, 7, 2},
}

var arr = [8][9]int32{ //배열 초기화 시 위치
	{8, 1, 6, 3, 5, 7, 4, 9, 2},
	{6, 7, 2, 1, 5, 9, 8, 3, 4},
	{2, 9, 4, 7, 5, 3, 6, 1, 8},
	{4, 3, 8, 9, 5, 1, 2, 7, 6},
	{6, 1, 8, 7, 5, 3, 2, 9, 4},
	{2, 7, 6, 9, 5, 1, 4, 3, 8},
	{4, 9, 2, 3, 5, 7, 8, 1, 6},
	{8, 3, 4, 1, 5, 9, 6, 7, 2},
} //newline 이용하려면 slice, 배열 둘 다 앞에 ,가 추가되어야 함.

func abs(a int32) int32 {
	if a < 0 {
		return -a
	}
	return a
}

func formingMagicSquare(s [][]int32) int32 {
	var nMin int32 = 1000
	for aa := 0; aa < 8; aa++ {
		var nSum int32 = 0
		for i := 0; i < 3; i++ {
			for j := 0; j < 3; j++ {
				nSum = nSum + abs(arr[aa][i*3+j]-s[i][j])
			}
		}
		if nMin > nSum {
			nMin = nSum
		}
	}
	return nMin
}

func main() {
	fmt.Println(formingMagicSquare([][]int32{
		{4, 8, 2},
		{4, 5, 7},
		{6, 1, 6},
	}))
}
