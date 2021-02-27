package main

import "fmt"

func icecreamParlor(m int32, arr []int32) []int32 {
	nm := make(map[int32]int)
	for i := 0; i < len(arr); i++ {
		nm[arr[i]]++
	}
	var oneKey int32
	for key := range nm {
		if m > key {
			if value, ok := nm[m-key]; ok {
				if m-key == key && value == 1 {
					continue
				}
				oneKey = key
				break
			}
		}
	}

	twoKey := m - oneKey
	slice := make([]int32, 0)
	for i := 0; i < len(arr); i++ {
		if arr[i] == oneKey || arr[i] == twoKey {
			slice = append(slice, int32(i+1))
			if len(slice) == 2 {
				break
			}
		}

	}
	if slice[0] > slice[1] {
		slice[0], slice[1] = slice[1], slice[0]
	}
	return slice
}

func main() {
	fmt.Println(icecreamParlor(8, []int32{4, 3, 2, 5, 7}))   //2,4
	fmt.Println(icecreamParlor(4, []int32{1, 4, 5, 3, 2}))   //1,4
	fmt.Println(icecreamParlor(4, []int32{2, 2, 4, 3}))      //1,2
	fmt.Println(icecreamParlor(12, []int32{7, 2, 5, 4, 11})) //1,3
	fmt.Println(icecreamParlor(5, []int32{1, 2, 3, 5, 6}))   //2,3
}
