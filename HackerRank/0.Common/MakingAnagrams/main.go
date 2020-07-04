package main

import (
	"fmt"
)

// Complete the makingAnagrams function below.
func makingAnagrams(s1 string, s2 string) int32 {
	m := make(map[byte]int)
	for i := 0; i < len(s1); i++ {
		m[s1[i]]++
	}

	for i := 0; i < len(s2); i++ {
		m[s2[i]]--
	}

	var ret int
	for _, value := range m {
		if value < 0 {
			ret = ret - value
		} else {
			ret = ret + value
		}
	}
	return int32(ret)
}

func main() {
	fmt.Println(makingAnagrams("cde", "abc"))

}
