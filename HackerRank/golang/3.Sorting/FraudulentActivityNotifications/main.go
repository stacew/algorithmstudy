package main

import (
	"fmt"
)

var arr [201]int

func initArr() {
	for i := 0; i < 201; i++ {
		arr[i] = 0
	}
}
func getMidEven(length int) float32 {
	lCnt := length / 2
	rCnt := length/2 + 1
	l := 0
	r := 0
	for i := 0; i < 201; i++ {
		lCnt = lCnt - arr[i]
		rCnt = rCnt - arr[i]
		if l == 0 && lCnt <= 0 {
			l = i
		}
		if rCnt <= 0 {
			r = i
			break
		}
	}
	return float32(l+r) / 2
}
func getMid(length int) int {
	cnt := length / 2
	i := 0
	for ; i < 201; i++ {
		cnt = cnt - arr[i]
		if cnt < 0 {
			break
		}
	}
	return i
}
func activityNotifications(expenditure []int32, d int32) int32 {
	initArr()
	ex := make([]int, 0, len(expenditure))
	for i := 0; i < len(expenditure); i++ {
		ex = append(ex, int(expenditure[i]))
	}
	dd := int(d)
	for i := 0; i < dd-1; i++ {
		arr[ex[i]]++
	}
	var ret int32 = 0
	for i := dd; i < len(ex); i++ {
		arr[ex[i-1]]++
		if dd%2 == 0 {
			if ex[i] >= int(getMidEven(dd)*2) {
				ret++
			}
		} else if ex[i] >= getMid(dd)*2 {
			ret++
		}
		arr[ex[i-dd]]--
	}
	return ret
}

func main() {
	fmt.Println(activityNotifications([]int32{2, 3, 4, 2, 3, 6, 8, 4, 5}, 5)) //2
	fmt.Println(activityNotifications([]int32{1, 2, 3, 4, 4}, 4))             //0
	fmt.Println(activityNotifications([]int32{10, 20, 30, 40, 50}, 3))        //1
	fmt.Println(activityNotifications([]int32{2, 3, 4, 2, 3, 6, 8, 4, 5}, 5)) //2
}
