package main

import (
	"fmt"
	"sort"
)

func maximumToys(prices []int32, k int32) int32 {
	prices2 := make([]int, 0, len(prices))
	for _, price := range prices {
		prices2 = append(prices2, int(price))
	}
	sort.Sort(sort.IntSlice(prices2))

	var ret int32 = 0
	for i := 0; i < len(prices2); i++ {
		if k < int32(prices2[i]) {
			break
		}
		k = k - int32(prices2[i])
		ret++
	}
	return ret
}

func main() {
	// fmt.Println([]int32{1, 12, 5, 111, 200, 1000, 10}, 50)
	fmt.Println(maximumToys([]int32{1, 12, 5, 111, 200, 1000, 10}, 50))
}
