package main

import (
	"fmt"
)

// Complete the countingValleys function below.
func countingValleys(n int32, s string) int32 {
	var valleyCount int32 = 0
	var level int32 = 0
	for i := 0; i < len(s); i++ {
		if level == 0 && s[i] == 'D' {
			valleyCount++
		}

		if s[i] == 'D' {
			level++
		} else {
			level--
		}
	}
	return valleyCount
}

func main() {
	fmt.Println(countingValleys(8, "UDDDUDUU"))
	//_/\      _ //1
	//   \    /
	//    \/\/
	fmt.Println(countingValleys(8, "DDUUUUDD"))
	//      /\
	//_    /  \_
	// \  /
	//  \/
	fmt.Println(countingValleys(8, "DDUUDDUDUUUD"))
	//_          /\_ //2 해수면에서 내려간 회수 구하기??........;
	// \  /\    /
	//  \/  \/\/

	fmt.Println(countingValleys(8, "DDUDDUUDUU"))
	//_          _ //1
	// \        /
	//  \/\  /\/
	//     \/

}
