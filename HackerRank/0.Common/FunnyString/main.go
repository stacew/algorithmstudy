package main

import "fmt"

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

// Complete the funnyString function below.
func funnyString(s string) string {
	slice := make([]int, 0)
	for i := 1; i < len(s); i++ {
		slice = append(slice, abs(int(s[i])-int(s[i-1])))
	}

	for i := 0; i < len(slice)/2; i++ {
		if slice[i] != slice[len(slice)-1-i] {
			return "Not Funny"
		}
	}
	return "Funny"
}

func main() {
	fmt.Println(funnyString("ovyvzvptyvpvpxyztlrztsrztztqvrxtxuxq"))
	fmt.Println(funnyString("holtm"))
	fmt.Println(funnyString("uvzxrumuztyqyvpnji"))
	fmt.Println(funnyString("tmruzxzuwoskqysxztuvosuyrswrnmtxvzsrqwytzrxpltrwusxupw"))
	fmt.Println(funnyString("wxstwxuzuyuvyzrsxysxyuvyqxuxyskqwsyqumqrvopvowqumnvrxpwqpwsrnvrztxrxpvuxunvyzvupvupowvyzvzuzwvsrwv"))
	fmt.Println(funnyString("yrzxrxskrtlpwpmtpxvowrxrpxq"))
	fmt.Println(funnyString("pryumtuntmovpwvowslj"))
	fmt.Println(funnyString("nosklrxrtyuxtmnurzsryuxtywqwqpxts"))
	fmt.Println(funnyString("fmpszyvqwxrtvpuwqszvyvotmsxsxuvzyvpwzrpmuxqwtswvytytzsnuxuyrpvtysqoutzurqxury"))
	fmt.Println(funnyString("jkmsxzwrxzy"))
}
