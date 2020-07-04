package main

import (
	"fmt"
	"strconv"
)

// Complete the separateNumbers function below.
func separateNumbers(s string) {
	maxNumLength := len(s) / 2
	for startLen := 1; startLen <= maxNumLength; startLen++ {
		length := startLen
		if length > 1 {
			if checkZero, _ := strconv.Atoi(s[0:1]); checkZero == 0 {
				continue
			}
		}
		start, _ := strconv.Atoi(s[0:length])
		number1 := start
		j := length
		if len(strconv.Itoa(number1+1)) != length {
			length = length + 1
		}

		for ; j+length <= len(s); j = j + length {
			if length > 1 {
				if checkZero, _ := strconv.Atoi(s[j : j+1]); checkZero == 0 {
					break
				}
			}
			number2, _ := strconv.Atoi(s[j : j+length])
			if number1+1 != number2 {
				break
			}
			number1 = number2
			if len(strconv.Itoa(number1+1)) != length {
				length = length + 1
				j--
			}
		}

		if j >= len(s) {
			fmt.Print("YES ")
			fmt.Println(start)
			return
		}
	}

	fmt.Println("NO")
	return
}

func main() {
	separateNumbers("1234")
	separateNumbers("91011")
	separateNumbers("99100")
	separateNumbers("101103")
	separateNumbers("010203")
	separateNumbers("13")
	separateNumbers("1")
	separateNumbers("429496729542949672964294967297")
	separateNumbers("429496729542949672964294967296")
	separateNumbers("429496729542949672964294967287")
	separateNumbers("429496729542949672964294967197")
	separateNumbers("42949672954294967296429496729")
	separateNumbers("4294967295429496729642949672")
	separateNumbers("429496729500000000000000000001")
	separateNumbers("42949672950123456789")
	separateNumbers("4294967295000010020030000456789")
	separateNumbers("4294967295000102003004005")
}
