package main

import (
	"fmt"
)

// Complete the pangrams function below.
func pangrams(s string) string {
	m := make(map[byte]int)
	for i := 0; i < len(s); i++ {
		if s[i] >= 'a' && s[i] <= 'z' {
			m[s[i]-'a']++
		} else if s[i] >= 'A' && s[i] <= 'Z' {
			m[s[i]-'A']++
		}
	}

	if len(m) == 26 {
		return "pangram"
	}

	return "not pangram"
}

func main() {
	fmt.Println(pangrams("We promptly judged antique ivory buckles for the next prize"))
	fmt.Println(pangrams("We promptly judged antique ivory buckles for the prize"))
}
