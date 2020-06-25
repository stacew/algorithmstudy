package main

import (
	"fmt"
	"sort"
)

func gcd(min, max int) int {
	for min != 0 {
		temp := max % min
		max = min
		min = temp
	}
	return max
}

func lcm(a, b int) int {
	return a / gcd(a, b) * b
}

func nthMagicalNumber(N int, A int, B int) int {
	MODULO := 1000000007
	if A > B {
		A, B = B, A
	}

	nLCM := lcm(A, B)
	nCountLCM := nLCM/A + nLCM/B - 1
	nLoop := N / nCountLCM
	nProcessed := nLoop * nCountLCM
	nProcessedBase := nLoop * nLCM
	n := N - nProcessed
	if n == 0 {
		return nProcessedBase % MODULO
	}

	sliceTemp := make([]int, 0, n*2)
	for i := 1; i <= n; i++ {
		sliceTemp = append(sliceTemp, i*A, i*B)
	}

	sort.Sort(sort.IntSlice(sliceTemp))
	return (sliceTemp[n-1] + nProcessedBase) % MODULO
}

func main() {
	fmt.Println(nthMagicalNumber(123, 223, 334)) //16502
}
