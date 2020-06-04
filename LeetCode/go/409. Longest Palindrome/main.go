package main

import "fmt"

func longestPalindrome(s string) int {
	lenth := len(s)
	countMap := make(map[byte]int)
	for i := 0; i < lenth; i++ {
		countMap[s[i]]++
	}

	bExistOdd := false
	ret := 0
	for _, count := range countMap {
		if count%2 == 1 {
			bExistOdd = true
			count--
		}
		ret += count
	}

	if bExistOdd {
		ret++
	}
	return ret
}

func main() {
	fmt.Println(longestPalindrome("aaabbb")) //-> baaab
}
