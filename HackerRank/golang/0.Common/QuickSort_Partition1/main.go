package main

import "fmt"

//해당 문제 sorting 방식 1회 결과
func quickSort(arr []int32) []int32 {
	p := 0

	var right []int32
	var left []int32
	for r := 1; r < len(arr); r++ {
		if arr[p] < arr[r] {
			right = append(right, arr[r])
		}
	}
	for l := 1; l < len(arr); l++ {
		if arr[l] < arr[p] {
			left = append(left, arr[l])
		}
	}

	left = append(left, arr[p])
	left = append(left, right...)

	return left
}

func main() {
	fmt.Println(quickSort([]int32{4, 5, 3, 7, 2}))
}
