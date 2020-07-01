package main

import (
	"fmt"
)

func jumpingOnClouds(c []int32) int32 {
	//1 or 2칸씩 전진 가능, 1은 밟으면 안 됨. 횟수 리턴
	//0에서 시작, 끝은 0
	var count int32 = 0
	for i := 0; i < len(c)-2; i++ {
		count++
		if c[i+2] == 0 { //2칸 가는 경우
			if i+2 == len(c)-1 {
				return count
			}
			i++
		}
	}
	return count + 1
}

func main() {
	fmt.Println(jumpingOnClouds([]int32{0, 0, 1, 0, 0, 1, 0})) //4
	fmt.Println(jumpingOnClouds([]int32{0, 0, 0, 0, 1, 0}))    //3
}
