package main

import "fmt"

func marsExploration(s string) int32 {
	var ret int32 = 0
	for i := 0; i < len(s); i++ {
		if i%3 == 1 {
			if s[i] != 'O' {
				ret++
			}
			continue
		}

		if s[i] != 'S' {
			ret++
		}
	}
	return ret
}

func main() {
	fmt.Println(marsExploration("SOSSPSSQSSOR"))
}
