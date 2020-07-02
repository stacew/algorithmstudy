package main

import (
	"fmt"
	"strconv"
)

func myMax(a, b int32) int32 {
	if a > b {
		return a
	}
	return b
}

func maxSubsetSum(arr []int32) int32 {
	var dp [100000]int32
	dp[0] = arr[0]
	dp[1] = myMax(arr[1], arr[0])
	for i := 2; i < len(arr); i++ {
		dp[i] = myMax(arr[i], myMax(arr[i]+dp[i-2], dp[i-1]))
	}
	return dp[len(arr)-1]
}

func main() {
	fmt.Println(strconv.Itoa(int(maxSubsetSum([]int32{3, 5, -7, 8, 10})))) //15 (5, 10)
	fmt.Println(strconv.Itoa(int(maxSubsetSum([]int32{3, 7, 4, 6, 5}))))   //13 (7, 6)
	fmt.Println(strconv.Itoa(int(maxSubsetSum([]int32{2, 1, 5, 8, 4}))))   //11 (2, 5, 4)
	fmt.Println(strconv.Itoa(int(maxSubsetSum([]int32{1, 2, 3, 4, 5}))))   //9  (1, 3, 5)
}

// func topDown(dp map[int]map[int]int32, arr []int32, pos int) int32 {
//    if pos >= len(arr)-2 {
//       return arr[pos]
//    }

//    if _, ok := dp[pos]; !ok {
//       dp[pos] = make(map[int]int32, 100000)
//    }

//    var ret int32 = -20000
//    for i := pos + 2; i < len(arr); i++ {
//       if _, ok := dp[pos][i]; !ok {
//          dp[pos][i] = arr[pos] + topDown(dp, arr, i)
//       }
//       ret = myMax(ret, dp[pos][i])
//    }
//    return ret
// }

// func maxSubsetSum(arr []int32) int32 {
//    dp := make(map[int]map[int]int32, 100000)
//    var ret int32 = -20000
//    for i := 0; i < len(arr)-2; i++ {
//       ret = myMax(ret, topDown(dp, arr, i))
//    }
//    return ret
// }
