package main

import (
	"fmt"
)

func arrayManipulation(n int32, queries [][]int32) int64 {
	array := make([]int32, n+2)
	for i := 0; i < len(queries); i++ {
		array[queries[i][0]] = array[queries[i][0]] + queries[i][2]
		array[queries[i][1]+1] = array[queries[i][1]+1] - queries[i][2]
	}

	var max int64
	var cur int64
	for i := 0; i < len(array); i++ {
		cur = cur + int64(array[i])
		if max < cur {
			max = cur
		}
	}

	return max
}

func main() {

	fmt.Println("Start")
	//8628
	fmt.Println(int(arrayManipulation(40, [][]int32{
		{29, 40, 787},
		{9, 26, 219},
		{21, 31, 214},
		{8, 22, 719},
		{15, 23, 102},
		{11, 24, 83},
		{14, 22, 321},
		{5, 22, 300},
		{11, 30, 832},
		{5, 25, 29},
		{16, 24, 577},
		{3, 10, 905},
		{15, 22, 335},
		{29, 35, 254},
		{9, 20, 20},
		{33, 34, 351},
		{30, 38, 564},
		{11, 31, 969},
		{3, 32, 11},
		{29, 35, 267},
		{4, 24, 531},
		{1, 38, 892},
		{12, 18, 825},
		{25, 32, 99},
		{3, 39, 107},
		{12, 37, 131},
		{3, 26, 640},
		{8, 39, 483},
		{8, 11, 194},
		{12, 37, 502},
	})))
}

// type data struct {
// 	a, b  int32
// 	value int64
// }

// func insertAt(slice []*data, at int, d *data) []*data {
// 	slice = append(slice, &data{})
// 	copy(slice[at+1:], slice[at:])
// 	slice[at] = d
// 	return slice
// }
// func arrayManipulation(n int32, queries [][]int32) int64 {
// 	sort.Slice(queries, func(a, b int) bool {
// 		return queries[a][0] < queries[b][0]
// 	})

// 	var slice []*data
// 	slice = append(slice, &data{a: queries[0][0], b: queries[0][1], value: int64(queries[0][2])})

// 	for i := 1; i < len(queries); i++ {
// 		a := queries[i][0]
// 		b := queries[i][1]
// 		value := int64(queries[i][2])

// 		index := len(slice) - 1
// 		if slice[index].b < a { // 뒤에 독립 처리되는 경우
// 			slice = append(slice, &data{a: a, b: b, value: value})
// 			continue
// 		} else if slice[index].b < b { //뒤가 잘리는 경우
// 			slice = append(slice, &data{a: slice[index].b + 1, b: b, value: value})
// 			b = slice[index].b
// 		}

// 		for i := index; i >= 0; i-- {
// 			if slice[i].b < a {
// 				break
// 			}

// 			if slice[i].a <= b {
// 				backupA := a
// 				a = slice[i].a
// 				leftB := slice[i].a - 1
// 				if slice[i].a == a && slice[i].b == b {
// 					slice[i].value = slice[i].value + value
// 				} else if slice[i].a == a && b < slice[i].b {
// 					//back
// 					slice = insertAt(slice, i+1, &data{a: b + 1, b: slice[i].b, value: slice[i].value})
// 					//front
// 					slice[i].b = b
// 					slice[i].value = slice[i].value + value
// 				} else if slice[i].a < a && slice[i].b == b {
// 					//front
// 					slice[i].b = a - 1
// 					//back
// 					slice = insertAt(slice, i+1, &data{a: a, b: b, value: slice[i].value + value})
// 				} else { // if slice[i].a < a && b < slice[i].b{
// 					back := slice[i].b
// 					//front
// 					slice[i].b = a - 1
// 					//mid
// 					slice = insertAt(slice, i+1, &data{a: a, b: b, value: slice[i].value + value})
// 					//back
// 					slice = insertAt(slice, i+2, &data{a: b + 1, b: back, value: slice[i].value})
// 				}
// 				a = backupA
// 				b = leftB
// 				continue
// 			}
// 		}
// 	}
// 	var max int64
// 	for i := 0; i < len(slice); i++ {
// 		if max < slice[i].value {
// 			max = slice[i].value
// 		}
// 	}
// 	return max
// }
