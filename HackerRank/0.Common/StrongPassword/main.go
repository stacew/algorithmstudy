package main

import "fmt"

//6자리, 숫자, 소문자, 대문자, 특문  !@#$%^&*()-+
func minimumNumber(n int32, password string) int32 {
	digit := false
	low := false
	up := false
	special := false
	for i := 0; i < len(password); i++ {
		p := password[i]
		if p >= '0' && p <= '9' {
			digit = true
		} else if p >= 'a' && p <= 'z' {
			low = true
		} else if p >= 'A' && p <= 'Z' {
			up = true
		} else if special == false && p == '!' || p == '@' || p == '#' || p == '$' || p == '%' || p == '^' || p == '&' || p == '*' || p == '(' || p == ')' || p == '-' || p == '+' {
			special = true
		}
	}

	var need int32 = 0
	if !digit {
		need++
	}
	if !low {
		need++
	}
	if !up {
		need++
	}
	if !special {
		need++
	}

	var ret int32 = 6 - n
	if ret < need {
		return need
	}
	return ret
}

func main() {
	fmt.Println(minimumNumber(11, "#HackerRank"))
}
