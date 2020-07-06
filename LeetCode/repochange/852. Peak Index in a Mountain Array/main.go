package main

import "fmt"

func peakIndexInMountainArray(A []int) int {
	left := 0
	right := len(A) - 1
	index := 0
	var max int = A[0]

	for {
		if index+1 < len(A) && max < A[index+1] {
			left = index
		} else if index-1 >= 0 && A[index-1] > max {
			right = index
		} else {
			return index
		}
		index = (left + right) / 2
		max = A[index]
	}
}

func main() {

	fmt.Println(peakIndexInMountainArray([]int{18, 29, 38, 59, 98, 100, 99, 98, 90}))

}
