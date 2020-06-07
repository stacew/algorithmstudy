package main

import (
	"fmt"
	"sort"
)

//쿠키를 하나씩 줄 때 최대 만족 가능 수
func findContentChildren(g []int, s []int) int {
	ret := 0
	sort.Ints(g)
	sort.Ints(s)

	childRIndex := len(g) - 1
	for i := len(s) - 1; i >= 0; i-- { //cookie
		for ; childRIndex >= 0; childRIndex-- {
			if g[childRIndex] <= s[i] {
				childRIndex--
				ret++
				break
			}
		}
	}

	return ret
}

func main() {
	fmt.Println(findContentChildren([]int{1, 2, 3}, []int{3, 1, 1, 1}))
}
