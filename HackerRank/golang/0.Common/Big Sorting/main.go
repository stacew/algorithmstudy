package main

import (
	"fmt"
	"sort"
)

// Complete the bigSorting function below.
func bigSorting(unsorted []string) []string {

	sort.Slice(unsorted, func(i, j int) bool {
		if len(unsorted[i]) != len(unsorted[j]) {
			return len(unsorted[i]) < len(unsorted[j])
		}

		for c := 0; c < len(unsorted[i]); c++ {
			if unsorted[i][c] != unsorted[j][c] {
				return unsorted[i][c] < unsorted[j][c]
			}
		}
		return false
	})

	return unsorted
}

func main() {
	fmt.Println(bigSorting([]string{
		"2",
		"100",
		"12303479849857341718340192371",
		"3084193741082937",
		"3084193741082938",
		"111",
		"200"}))
}
