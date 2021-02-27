package main

import (
	"fmt"
	"strconv"
)

func checkString(s1, s2 string, map1 map[byte]int) bool {
	if s1 == s2 {
		return true
	} else if len(s1) != len(s2) {
		return false
	}
	map2 := make(map[byte]int)
	for i := 0; i < len(s2); i++ {
		map2[s2[i]]++
	}
	if len(map1) != len(map2) {
		return false
	}
	for key, count1 := range map1 {
		if count2 := map2[key]; count1 != count2 {
			return false
		}
	}
	return true
}
func sherlockAndAnagrams(s string) int32 {
	sLen := len(s)
	count := 0
	for i := 1; i < sLen; i++ {
		for j := 0; j+i < sLen; j++ {
			text1 := s[j : j+i]
			map1 := make(map[byte]int) // T-T 1/2
			for i := 0; i < len(text1); i++ {
				map1[text1[i]]++
			}
			for k := j + 1; k+i <= sLen; k++ {
				if checkString(text1, s[k:k+i], map1) {
					count++
				}
			}
		}
	}
	return int32(count)
}

func main() {
	//fmt.Println(strconv.Itoa(int(sherlockAndAnagrams("abba")))) //4
	//a,a b,b ab,ba abb, bba
	fmt.Println(strconv.Itoa(int(sherlockAndAnagrams("ifailuhkqq")))) //3
	fmt.Println(strconv.Itoa(int(sherlockAndAnagrams("abcd"))))       //0
	fmt.Println(strconv.Itoa(int(sherlockAndAnagrams("kkkk"))))       //10
	//0,1 0,2 0,3 1,2 1,3 2,3
	//01,12 01,23 12,23
	//012, 123
	fmt.Println(strconv.Itoa(int(sherlockAndAnagrams("cdcd")))) //5
	fmt.Println(strconv.Itoa(int(sherlockAndAnagrams("bcgdehhbcefeeadchgaheddegbiihehcbbdffiiiifgibhfbchffcaiabbbcceabehhiffggghbafabbaaebgediafabafdicdhg"))))
	//1305
	fmt.Println(strconv.Itoa(int(sherlockAndAnagrams("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"))))
	//166650
}
