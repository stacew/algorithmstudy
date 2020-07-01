package main

import "fmt"

func twoStrings(s1 string, s2 string) string {
	map1 := make(map[byte]bool)
	map2 := make(map[byte]bool)
	for i:=0 ; i< len(s1); i++ {
		map1[s1[i]] = true
	}
	for i:=0 ; i< len(s2); i++ {
		map2[s2[i]] = true
	}
	for i := 0; i < 26; i++{
		if map1[byte('a'+i)] == true && map2[byte('a'+i)]{
			return "YES"
		}
	}
	return "NO"
}

func main() {
	fmt.Println(twoStrings("wouldyoulikefries", "abcabcabcabcabcabc"))
	fmt.Println(twoStrings("hackerrankcommunity", "cdecdecdecde"))
	fmt.Println(twoStrings("jackandjill", "wentupthehill"))
	fmt.Println(twoStrings("writetoyourparents", "fghmqzldbc"))
}
