package main

import "fmt"

func replaceAtIndex(in string, r rune, i int) string {
	out := []rune(in)
	out[i] = r
	return string(out)
}

func beautifulBinaryString(b string) int32 {
	count := 0
	for i := 1; i < len(b)-1; i++ {
		if b[i-1] == '0' && b[i] == '1' && b[i+1] == '0' {
			count++
			b = replaceAtIndex(b, '1', i+1)
		}
	}

	return int32(count)
}

func main() {
	fmt.Println(beautifulBinaryString("010011101110101010100010110100100110110100011100111110101001011001110111110000101011011111011001111100011101"))
}
