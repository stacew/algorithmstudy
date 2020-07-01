package main

import (
	"fmt"
	"strconv"
)

// Complete the repeatedString function below.
//문자열 반복해서 문자 개수만큼의 경우. 'a' 개수 구하기
func repeatedString(s string, n int64) int64 {
	var aCount int64 = 0
	sLen := len(s)
	for i := 0; i < sLen; i++ {
		if s[i] == 'a' {
			aCount++
		}
	}

	repeatedCount := n / int64(sLen)
	modCount := n % int64(sLen)
	aCount = aCount * repeatedCount
	for i := 0; i < int(modCount); i++ {
		if s[i] == 'a' {
			aCount++
		}
	}
	return aCount
}

func main() {
	fmt.Println(strconv.Itoa(int(repeatedString("aba", 10))))
}
