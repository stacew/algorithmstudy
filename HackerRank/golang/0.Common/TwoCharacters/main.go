package main

import (
	"fmt"
)

func checkStr(a, b byte, s string) int32 {
	var prev byte = 'Z'
	var ret int32 = 0
	for i := 0; i < len(s); i++ {
		if s[i] != a && s[i] != b {
			continue
		}

		if prev == s[i] {
			return 0
		}
		prev = s[i]
		ret++
	}

	return ret
}

func alternate(s string) int32 {
	cMap := make(map[byte]bool)
	for i := 0; i < len(s); i++ {
		cMap[s[i]] = true
	}
	var retMax int32 = 0
	for key1 := range cMap {
		for key2 := range cMap {
			if key1 == key2 {
				continue
			}
			temp := checkStr(key1, key2, s)
			if temp > retMax {
				retMax = temp
			}
		}
	}
	return retMax
}

func main() {
	result := alternate("asdcbsdcagfsdbgdfanfghbsfdab")
	fmt.Println(result)
}
