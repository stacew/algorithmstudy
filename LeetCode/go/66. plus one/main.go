package main

import "fmt"

func plusOne(digits []int) []int {
	length := len(digits)
	digits[length-1]++
	for digits[length-1] > 9 {
		digits[length-1] = 0
		if length == 1 {
			digits = append([]int{1}, digits...)
			break
		}
		digits[length-2]++
		length--
	}
	return digits
}

func main() {
	fmt.Print(plusOne([]int{9, 9, 9}))
}
