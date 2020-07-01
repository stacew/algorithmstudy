package main

import (
	"fmt"
	"strconv"
)

// Complete the makeAnagram function below.
func makeAnagram(a string, b string) int32 {
	aMap := make(map[byte]int)
	bMap := make(map[byte]int)
	for i := 0; i < len(a); i++ {
		aMap[a[i]]++
	}
	for i := 0; i < len(b); i++ {
		bMap[b[i]]++
	}
	var total int = 0
	for key1, value1 := range aMap {
		for key2, value2 := range bMap {
			if key1 == key2 {
				if value1 < value2 {
					total = total + value1
				} else {
					total = total + value2
				}
			}
		}
	}

	return int32(len(a) + len(b) - total*2)
}

func main() {
	fmt.Println(strconv.Itoa(int(makeAnagram("cde", "dcf")))) //2
	fmt.Println(strconv.Itoa(int(makeAnagram("abc", "cdc")))) //4
	fmt.Println(strconv.Itoa(int(makeAnagram("cde", "abc")))) //4
}
