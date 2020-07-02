package main

import (
	"fmt"
	"strconv"
)

// Complete the whatFlavors function below.
func whatFlavors(cost []int32, money int32) {
	costMap := make(map[int32]int32, 50000)
	for i := 0; i < len(cost); i++ {
		costMap[cost[i]]++
	}

	var cost1 int32
	var cost2 int32
	for i := 0; i < len(cost); i++ {
		if count, ok := costMap[money-cost[i]]; ok {
			if money/2 == cost[i] && count == 1 {
				continue
			}
			cost1 = money - cost[i]
			cost2 = cost[i]
			break
		}
	}

	for i := 0; i < len(cost); i++ {
		if cost[i] != cost1 && cost[i] != cost2 {
			continue
		}
		j := i + 1
		for ; j < len(cost); j++ {
			if cost[j] == cost1 || cost[j] == cost2 {
				break
			}
		}
		fmt.Println(strconv.Itoa(i+1), strconv.Itoa(j+1))
		break
	}
}

func main() {
	whatFlavors([]int32{4, 3, 2, 5, 7}, 8)   //2,4
	whatFlavors([]int32{1, 4, 5, 3, 2}, 4)   //1,4
	whatFlavors([]int32{2, 2, 4, 3}, 4)      //1,2
	whatFlavors([]int32{7, 2, 5, 4, 11}, 12) //1,3
	whatFlavors([]int32{1, 2, 3, 5, 6}, 5)   //2,3
}

// func whatFlavors(cost []int32, money int32) {
// 	costMap := make(map[int32]int32, 50000)
// 	for i := 0; i < len(cost); i++ {
// 		costMap[cost[i]]++
// 	}

// 	var cost1 int32
// 	var cost2 int32
// 	var ok bool
// 	for m := 1; m < int(money); m++ {
// 		if _, ok = costMap[int32(m)]; !ok {
// 			continue
// 		}
// 		costMap[int32(m)]--
// 		if _, ok := costMap[money-int32(m)]; !ok {
// 			continue
// 		}
// 		cost1 = int32(m)
// 		cost2 = money - int32(m)
// 	}

// 	for i := 0; i < len(cost); i++ {
// 		if cost[i] != cost1 && cost[i] != cost2 {
// 			continue
// 		}
// 		j := i + 1
// 		for ; j < len(cost); j++ {
// 			if cost[j] == cost1 || cost[j] == cost2 {
// 				break
// 			}
// 		}
// 		fmt.Println(strconv.Itoa(i+1), strconv.Itoa(j+1))
// 		break
// 	}
// }
