package main

import (
	"fmt"
	"sort"
	"strconv"
)

func minimumAbsoluteDifference(arr []int32) int32 {
	sort.Slice(arr, func(i, j int) bool {
		return arr[i] > arr[j]
	})

	ret := arr[0] - arr[1]
	for i := 1; i < len(arr)-1; i++ {
		tmp := arr[i] - arr[i+1]
		if ret > tmp {
			ret = tmp
		}
	}

	return ret
}

func main() {
	fmt.Println(strconv.Itoa(int(minimumAbsoluteDifference([]int32{-59, -36, -13, 1, -53, -92, -2, -96, -54, 75}))))
}
