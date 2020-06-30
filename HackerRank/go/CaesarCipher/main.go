package main

import (
	"fmt"
)

func caesarCipher(s string, k int32) string {
	var ret string
	for i := 0; i < len(s); i++ {
		if s[i] >= 'a' && s[i] <= 'z' {
			ret = ret + string('a'+((int32(s[i])+k-'a')%26))
		} else if s[i] >= 'A' && s[i] <= 'Z' {
			ret = ret + string('A'+((int32(s[i])+k-'A')%26))
		} else {
			ret = ret + string(s[i])
		}
	}
	return ret
}
func main() {
	result := caesarCipher("asdsadasdasd", 1)
	fmt.Println(result)

}
