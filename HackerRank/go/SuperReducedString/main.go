package main

import "fmt"

func remove(s string) (string, bool) {
	for i := 0; i < len(s)-1; i++ {
		if s[i] == s[i+1] {
			return s[:i] + s[i+2:], true
		}
	}
	return s, false
}
func superReducedString(s string) string {
	removed := true
	for removed {
		s, removed = remove(s)
	}
	if len(s) == 0 {
		return "Empty String"
	}
	return s
}

func main() {
	fmt.Println(superReducedString("aa"))

}
