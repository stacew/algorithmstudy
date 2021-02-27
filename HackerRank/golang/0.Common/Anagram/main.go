package main

import (
	"fmt"
)

// Complete the anagram function below.
func anagram(s string) int32 {
	if len(s)%2 == 1 {
		return -1
	}
	half := len(s) / 2

	m1 := make(map[byte]int)
	m2 := make(map[byte]int)
	for i := 0; i < half; i++ {
		m1[s[i]]++
	}
	for i := half; i < len(s); i++ {
		m2[s[i]]++
	}
	for key, value := range m1 {
		m2[key] = m2[key] - value
	}

	var ret int
	for _, value := range m2 {
		if value > 0 {
			ret = ret + value
		}
	}
	return int32(ret)
}

func main() {
	fmt.Println(anagram("aaabbb"))
	fmt.Println(anagram("ab"))
	fmt.Println(anagram("abc"))
	fmt.Println(anagram("mnop"))
	fmt.Println(anagram("xyyx"))
	fmt.Println(anagram("xaxbbbxx"))
}
