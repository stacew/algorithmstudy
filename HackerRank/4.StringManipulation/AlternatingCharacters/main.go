package main

import (
	"fmt"
	"strconv"
)

// Complete the alternatingCharacters function below.
func alternatingCharacters(s string) int32 {
	var c byte = 'z'
	var count int32 = 0
	for i := 0; i < len(s); i++ {
		if c == s[i] {
			count++
		}
		c = s[i]
	}
	return count
}

func main() {
	fmt.Println(strconv.Itoa(int(alternatingCharacters("AAAA"))))
	fmt.Println(strconv.Itoa(int(alternatingCharacters("BBBBB"))))
	fmt.Println(strconv.Itoa(int(alternatingCharacters("ABABABAB"))))
	fmt.Println(strconv.Itoa(int(alternatingCharacters("BABABA"))))
	fmt.Println(strconv.Itoa(int(alternatingCharacters("AAABBB"))))
}
