package main

import (
	"fmt"
)

// Complete the sockMerchant function below.
func sockMerchant(n int32, ar []int32) int32 {
	netMap := make(map[int32]int32)
	for i := 0; i < len(ar); i++ {
		netMap[ar[i]]++
	}
	var ret int32
	for _, value := range netMap {
		ret = ret + value/2
	}
	return ret
}

func main() {
	fmt.Println(sockMerchant(0, []int32{10, 20, 20, 10, 10, 30, 50, 10, 20}))
}
