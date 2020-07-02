package main

import (
	"fmt"
)

// Complete the hackerrankInString function below.
func hackerrankInString(s string) string {
	answer := "hackerrank"
	count := len(answer)
	answerIndex := 0
	for i := 0; i < len(s); i++ {
		if s[i] == answer[answerIndex] {
			answerIndex++
			if answerIndex == count {
				return "YES"
			}
		}
	}
	return "NO"
}

func main() {
	fmt.Println(hackerrankInString("hhaacckkekraraannk"))
	fmt.Println(hackerrankInString("rhbaasdndfsdskgbfefdbrsdfhuyatrjtcrtyytktjjt"))

}
