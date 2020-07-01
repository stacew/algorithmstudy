package main

import "fmt"

func checkMagazine(magazine []string, note []string) {
	magMap := make(map[string]int)
	for i := 0; i < len(magazine); i++ {
		magMap[magazine[i]]++
	}
	noteMap := make(map[string]int)
	for i := 0; i < len(note); i++ {
		noteMap[note[i]]++
	}
	for i := 0; i < len(note); i++ {
		if magMap[note[i]] < noteMap[note[i]] {
			fmt.Println("No")
			return
		}
	}
	fmt.Println("Yes")
}

func main() {
	checkMagazine([]string{"give", "me", "one", "grand", "today", "night"},
		[]string{"give", "one", "grand", "today"})

	checkMagazine([]string{"two", "times", "three", "is", "not", "four"},
		[]string{"two", "times", "two", "is", "four"})
}
