package main

import (
	"fmt"
	"strconv"
)

func countSwaps(a []int32) {
	swapCount := 0
	aLen := len(a)
	for i := aLen - 1; i >= 0; i-- {
		for j := 0; j < i; j++ {
			if a[j] > a[j+1] {
				a[j], a[j+1] = a[j+1], a[j]
				swapCount++
			}
		}
	}

	fmt.Println("Array is sorted in " + strconv.Itoa(swapCount) + " swaps.")
	fmt.Println("First Element: " + strconv.Itoa(int(a[0])))
	fmt.Println("Last Element: " + strconv.Itoa(int(a[aLen-1])))
}

func main() {
	var a []int32
	a = append(a, 4, 3, 2, 1)
	countSwaps(a)
}
