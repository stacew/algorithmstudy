package main

import (
	"fmt"
)

func rotLeft(a []int32, d int32) []int32 {
	aLen := len(a)
	repeat := int(d) % aLen
	ret := make([]int32, aLen)
	for i := 0; i < aLen; i++ {
		ret[(i+aLen-repeat)%aLen] = a[i]
	}
	return ret
}
func main() {
	fmt.Println(rotLeft([]int32{1, 2, 3, 4, 5}, 4))
}
