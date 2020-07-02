package main

import (
	"fmt"
)

//n <10_5, x[i] < 10_7
func weightedUniformStrings(s string, queries []int32) []string {
	m := make(map[int]int)
	for i := 1; i <= 26; i++ {
		m[i] = 0
	}
	record := 0
	char := s[0]
	i := 1
	for ; i < len(s); i++ {
		if s[i] != char {
			if m[int(char-'a'+1)] < i-record {
				m[int(char-'a'+1)] = i - record
			}
			record = i
			char = s[i]
		}
	}
	if m[int(char-'a'+1)] < i-record {
		m[int(char-'a'+1)] = i - record
	}

	ret := make([]string, 0, len(queries))
	for i := 0; i < len(queries); i++ {
		bFind := false
		for key, value := range m {
			if int(queries[i])%key != 0 {
				continue
			}
			if int(queries[i])/key <= value {
				ret = append(ret, "Yes")
				bFind = true
				break
			}
		}
		if bFind == false {
			ret = append(ret, "No")
		}
	}
	return ret
}

func main() {
	//y n y y n
	fmt.Println(weightedUniformStrings("aaabbbbcccddd", []int32{9, 7, 8, 12, 5}))
	//y y y y n n
	fmt.Println(weightedUniformStrings("abccddde", []int32{1, 3, 12, 5, 9, 10}))
}
