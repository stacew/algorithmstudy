package main

import "fmt"

var dp [][]int
var str string

func myMax(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

func initDP(sLen int) {
	dp = make([][]int, sLen)
	for i := 0; i < sLen; i++ {
		dp[i] = make([]int, sLen)
		for j := 0; j < sLen; j++ {
			dp[i][j] = -1
		}
	}
}
func topDownProcess(a, b int) int {
	if dp[a][b] != -1 {
		return dp[a][b]
	} else if a == b {
		return 1
	} else if b < a {
		return 0
	}

	if str[a] != str[b] {
		dp[a+1][b] = topDownProcess(a+1, b)
		dp[a][b-1] = topDownProcess(a, b-1)
		return myMax(dp[a+1][b], dp[a][b-1])
	}

	dp[a+1][b-1] = topDownProcess(a+1, b-1)
	return 2 + dp[a+1][b-1]
}

func longestPalindromeSubseq(s string) int {
	str = s
	if len(s) == 0 {
		return 0
	}
	initDP(len(s))
	return topDownProcess(0, len(s)-1)
}

func main() {
	fmt.Println(longestPalindromeSubseq("abca"))                      //3
	fmt.Println(longestPalindromeSubseq("aaaaaabbbcbbb"))             //7
	fmt.Println(longestPalindromeSubseq(""))                          //0
	fmt.Println(longestPalindromeSubseq("aaaaaabbbczxafvxcvbbb"))     //11
	fmt.Println(longestPalindromeSubseq("aaaaaabbbczxafvxcvbbbaaaa")) //19
	fmt.Println(longestPalindromeSubseq("euazbipzncptldueeuechubrcourfpftcebikrxhybkymimgvldiwqvkszfycvqyvtiwfckexmowcxztkfyzqovbtmzpxojfofbvwnncajvrvdbvjhcrameamcfmcoxryjukhpljwszknhiypvyskmsujkuggpztltpgoczafmfelahqwjbhxtjmebnymdyxoeodqmvkxittxjnlltmoobsgzdfhismogqfpfhvqnxeuosjqqalvwhsidgiavcatjjgeztrjuoixxxoznklcxolgpuktirmduxdywwlbikaqkqajzbsjvdgjcnbtfksqhquiwnwflkldgdrqrnwmshdpykicozfowmumzeuznolmgjlltypyufpzjpuvucmesnnrwppheizkapovoloneaxpfinaontwtdqsdvzmqlgkdxlbeguackbdkftzbnynmcejtwudocemcfnuzbttcoew"))
}
