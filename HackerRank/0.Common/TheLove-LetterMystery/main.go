package main

import (
	"fmt"
)

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}
func theLoveLetterMystery(s string) int32 {
	count := 0
	for i := 0; i < len(s)/2; i++ {
		count = count + abs(int(int(s[len(s)-1-i])-int(s[i])))
	}
	return int32(count)
}

func main() {
	fmt.Println(theLoveLetterMystery("abc"))
	fmt.Println(theLoveLetterMystery("abcba"))
	fmt.Println(theLoveLetterMystery("abcd"))
	fmt.Println(theLoveLetterMystery("cba"))
}
