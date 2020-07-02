package main

import "fmt"

func fibonacciBU(n int) int64 {
	var a, b int64
	a = 0
	b = 1
	var ret int64
	for i := 2; i <= n; i++ {
		ret = b + a
		a = b
		b = ret
	}
	return ret
}

func fibonacciTD(n int) int64 {
	if n == 0 {
		return 0
	} else if n == 1 {
		return 1
	}

	if dp[n] == 0 {
		dp[n] = fibonacciTD(n-1) + fibonacciTD(n-2)
	}

	return dp[n]
}

var dp [31]int64

func main() {
	n := 30
	fmt.Println(fibonacciTD(n))
	fmt.Println(fibonacciBU(n))
}
