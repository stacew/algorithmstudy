package main

import (
	"fmt"
)

// Complete the gemstones function below.
func gemstones(arr []string) int32 {
	var mineral [26]int
	for i := 0; i < len(arr); i++ {
		m := make(map[byte]int)
		for j := 0; j < len(arr[i]); j++ {
			m[arr[i][j]]++
		}

		for key := range m {
			mineral[int(key-'a')]++
		}
	}

	count := 0
	for i := 0; i < 26; i++ {
		if mineral[i] == len(arr) {
			count++
		}
	}
	return int32(count)
}

func main() {
	fmt.Println(gemstones([]string{
		"basdfj",
		"asdlkjfdjsa",
		"bnafvfnsd",
		"oafhdlasd"}))

}
