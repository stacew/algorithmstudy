package main

import (
	"fmt"
)

func twoSum(nums []int, target int) []int {
	hash := make(map[int]int) //num, index
	for i := 0; i < len(nums); i++ {
		s := target - nums[i]
		index, ok := hash[s]
		if ok {
			return []int{index, i}
		}

		hash[nums[i]] = i
	}
	return []int{}
}

func main() {
	fmt.Println(twoSum([]int{2, 7, 11, 15}, 9))
	fmt.Println(twoSum([]int{0, 4, 3, 0}, 0))
	fmt.Println(twoSum([]int{-1, -2, -3, -4, 5}, 3))
}
