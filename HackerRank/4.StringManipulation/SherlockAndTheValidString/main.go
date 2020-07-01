package main

import (
	"fmt"
	"sort"
)

//같은 회수로 나오면 유효한 문자열
//단 한 문자만 고쳐서 가능하면 됨.
func isValid(s string) string {
	if len(s) < 3 {
		return "YES"
	}

	cMap := make(map[byte]int)
	for i := 0; i < len(s); i++ {
		cMap[s[i]]++
	}
	cSlice := make([]int, 0, len(cMap))
	for _, value := range cMap {
		cSlice = append(cSlice, value)
	}
	sort.Sort(sort.IntSlice(cSlice))

	var num int = cSlice[0]
	var bChance bool = true
	if cSlice[0] != cSlice[1] {
		if cSlice[0] != 1 {
			return "NO"
		}
		num = cSlice[1]
		bChance = false
	}
	for i := 2; i < len(cSlice); i++ {
		if num == cSlice[i] {
			continue
		}
		if bChance == false {
			return "NO"
		}
		bChance = false
		if num+1 != cSlice[i] {
			return "NO"
		}
	}
	return "YES"
}

func main() {
	fmt.Println(isValid("aabbcd"))            //n
	fmt.Println(isValid("abcdefghhgfedecba")) //yes
	fmt.Println(isValid("aaaabbcc"))          //n
	fmt.Println(isValid("aabbccddeefghi"))    //n
}
