package main

import "fmt"

func isIsomorphic(s string, t string) bool {
	cnt := len(s)
	sMap := make(map[byte]int)
	tMap := make(map[byte]int)

	for i := 0; i < cnt; i++ {
		sVal := 0
		tVal := 0
		if value, ok := sMap[s[i]]; ok {
			sVal = value
		} else {
			sVal = len(sMap)
			sMap[s[i]] = sVal
		}

		if value, ok := tMap[t[i]]; ok {
			tVal = value
		} else {
			tVal = len(tMap)
			tMap[t[i]] = tVal
		}

		if sVal != tVal {
			return false
		}
	}

	return true
}

func main() {
	fmt.Print(isIsomorphic("eggag", "addbd"))
}
