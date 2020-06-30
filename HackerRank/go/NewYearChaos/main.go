package main

import (
	"fmt"
	"strconv"
)

func minimumBribes(q []int32) {
	//check
	for i := 0; i < len(q); i++ {
		if i+1+2 < int(q[i]) {
			fmt.Println("Too chaotic")
			return
		}
	}

	//process
	swapCount := 0
	for i := len(q) - 1; i > 0; i-- {
		if i >= 2 && int(q[i-2]) == i+1 {
			q[i-2], q[i-1] = q[i-1], q[i-2]
			swapCount = swapCount + 1
			i++
		} else if int(q[i-1]) == i+1 {
			q[i], q[i-1] = q[i-1], q[i]
			swapCount = swapCount + 1
		}
	}
	fmt.Println(strconv.Itoa(swapCount))
}

func main() {
	minimumBribes([]int32{2, 1, 5, 3, 4})
	minimumBribes([]int32{2, 5, 1, 3, 4})
	minimumBribes([]int32{1, 2, 5, 3, 7, 8, 6, 4})
	minimumBribes([]int32{1, 2, 5, 3, 7, 4, 6})
	// 1 2 5 3 7 4 6
	// 1 2 3 5 7 4 6 //1
	// 1 2 3 5 4 7 6 //2
	// 1 2 3 4 5 7 6 //3
	// 1 2 3 4 5 6 7 //4
}
