package main

import "fmt"

// Complete the palindromeIndex function below.
func palindromeIndex(s string) int32 {
	m := make(map[byte]int)
	half := len(s) / 2
	for i := 0; i < half; i++ {
		m[s[i]]++
	}
	for i := half; i < len(s); i++ {
		m[s[i]]++
	}
	var c byte = '@'
	for key, value := range m {
		if value%2 != 0 {
			c = key
		}
	}
	if c == '@' {
		return -1
	}

	for i := 0; i < len(s); i++ {
		if s[len(s)-1-i] == c && s[i] != c {
			return int32(len(s) - 1 - i)
		}

		if s[i] == c && s[len(s)-1-i] != c {
			return int32(i)
		}
	}

	return -1
}

func main() {
	fmt.Println(palindromeIndex("hgygsvlfcwnswtuhmyaljkqlqjjqlqkjlaymhutwsnwcwflvsgygh"))
	fmt.Println(palindromeIndex("aaaaaba"))
	fmt.Println(palindromeIndex("abaaaaa"))
	fmt.Println(palindromeIndex("ababa"))
	fmt.Println(palindromeIndex("aaab"))
	fmt.Println(palindromeIndex("baa"))
	fmt.Println(palindromeIndex("aaa"))
	fmt.Println(palindromeIndex("abaaa"))
}
