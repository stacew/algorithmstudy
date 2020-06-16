package main

import (
	"fmt"
	"math/rand"
	"sort"
	"time"
)

func basicQSort(slice []int) {
	if len(slice) <= 1 {
		return
	}
	pivotIndex := len(slice) - 1
	leftIndex := 0
	rightIndex := pivotIndex - 1
	for leftIndex <= rightIndex {
		if slice[leftIndex] < slice[pivotIndex] {
			leftIndex++
		} else if slice[pivotIndex] <= slice[rightIndex] {
			rightIndex--
		} else {
			slice[leftIndex], slice[rightIndex] = slice[rightIndex], slice[leftIndex]
			leftIndex++
			rightIndex--
		}
	}
	slice[pivotIndex], slice[leftIndex] = slice[leftIndex], slice[pivotIndex]
	basicQSort(slice[leftIndex+1:])
	basicQSort(slice[:leftIndex])
}
func basicMyQSort(slice []int) {
	if len(slice) <= 1 {
		return
	}
	pivotIndex := len(slice) - 1
	leftIndex := 0
	rightIndex := pivotIndex - 1
	for true {
		for leftIndex <= rightIndex && slice[leftIndex] < slice[pivotIndex] {
			leftIndex++
		}
		for leftIndex <= rightIndex && slice[pivotIndex] <= slice[rightIndex] {
			rightIndex--
		}
		if leftIndex > rightIndex {
			break
		}
		slice[leftIndex], slice[rightIndex] = slice[rightIndex], slice[leftIndex]
		leftIndex++
		rightIndex--
	}
	slice[pivotIndex], slice[leftIndex] = slice[leftIndex], slice[pivotIndex]
	basicMyQSort(slice[leftIndex+1:])
	basicMyQSort(slice[:leftIndex])
}

func midQSort(slice []int, startIndex, endIndex int) {
	if len(slice) <= 1 {
		return
	}

	leftIndex := startIndex
	rightIndex := endIndex
	midPivot := slice[(startIndex+endIndex)/2]
	for true {
		for leftIndex < endIndex && slice[leftIndex] < midPivot {
			leftIndex++
		}
		for startIndex < rightIndex && midPivot < slice[rightIndex] {
			rightIndex--
		}
		if leftIndex > rightIndex {
			break
		}
		slice[leftIndex], slice[rightIndex] = slice[rightIndex], slice[leftIndex]
		leftIndex++
		rightIndex--
	}

	if startIndex < rightIndex {
		midQSort(slice, startIndex, rightIndex)
	}
	if leftIndex < endIndex {
		midQSort(slice, leftIndex, endIndex)
	}
}
func motQSort(slice []int) {
	if len(slice) <= 1 {
		return
	}

	startIndex := 0
	endIndex := len(slice) - 1
	nMidIndex := (startIndex + endIndex) / 2

	nStart := slice[startIndex]
	nMidPivot := slice[nMidIndex]
	nEnd := slice[endIndex]
	if nStart > nMidPivot {
		slice[startIndex], slice[nMidIndex] = slice[nMidIndex], slice[startIndex]
		nStart, nMidPivot = nMidPivot, nStart
	}
	if nEnd < nMidPivot {
		slice[nMidIndex], slice[endIndex] = slice[endIndex], slice[nMidIndex]
		nMidPivot = nEnd
		if nStart > nMidPivot {
			slice[startIndex], slice[nMidIndex] = slice[nMidIndex], slice[startIndex]
			nMidPivot = nStart
		}
	}
	if endIndex-startIndex < 3 {
		return
	}

	slice[nMidIndex], slice[endIndex-1] = slice[endIndex-1], slice[nMidIndex]
	nLeftIndex := startIndex + 1
	nRightIndex := endIndex - 2
	for true {
		for nLeftIndex < endIndex && slice[nLeftIndex] < nMidPivot {
			nLeftIndex++
		}
		for startIndex < nRightIndex && nMidPivot < slice[nRightIndex] {
			nRightIndex--
		}
		if nLeftIndex > nRightIndex {
			break
		}
		slice[nLeftIndex], slice[nRightIndex] = slice[nRightIndex], slice[nLeftIndex]
		nLeftIndex++
		nRightIndex--
	}
	slice[nLeftIndex], slice[endIndex-1] = slice[endIndex-1], slice[nLeftIndex]
	motQSort(slice[:nLeftIndex])
	motQSort(slice[nLeftIndex+1:])
}
func motQSort2(slice []int, startIndex, endIndex int) {
	if startIndex >= endIndex {
		return
	}

	nMidIndex := (startIndex + endIndex) / 2

	nStart := slice[startIndex]
	nMidPivot := slice[nMidIndex]
	nEnd := slice[endIndex]
	if nStart > nMidPivot {
		slice[startIndex], slice[nMidIndex] = slice[nMidIndex], slice[startIndex]
		nStart, nMidPivot = nMidPivot, nStart
	}
	if nEnd < nMidPivot {
		slice[nMidIndex], slice[endIndex] = slice[endIndex], slice[nMidIndex]
		nMidPivot = nEnd
		if nStart > nMidPivot {
			slice[startIndex], slice[nMidIndex] = slice[nMidIndex], slice[startIndex]
			nMidPivot = nStart
		}
	}
	if endIndex-startIndex < 3 {
		return
	}

	slice[nMidIndex], slice[endIndex-1] = slice[endIndex-1], slice[nMidIndex]
	nLeftIndex := startIndex + 1
	nRightIndex := endIndex - 2
	for true {
		for nLeftIndex < endIndex && slice[nLeftIndex] < nMidPivot {
			nLeftIndex++
		}
		for startIndex < nRightIndex && nMidPivot < slice[nRightIndex] {
			nRightIndex--
		}
		if nLeftIndex > nRightIndex {
			break
		}
		slice[nLeftIndex], slice[nRightIndex] = slice[nRightIndex], slice[nLeftIndex]
		nLeftIndex++
		nRightIndex--
	}
	slice[nLeftIndex], slice[endIndex-1] = slice[endIndex-1], slice[nLeftIndex]
	motQSort2(slice, startIndex, nLeftIndex-1)
	motQSort2(slice, nLeftIndex+1, endIndex)
}

func checkData(leftSort, rightSort []int) bool {
	for i := 0; i < len(leftSort); i++ {
		if leftSort[i] != rightSort[i] {
			return false
		}
	}
	return true
}

func dataCopy(recv, send []int) {
	for i := range send {
		recv[i] = send[i]
	}
}

func initData(data []int) {
	for i := 0; i < len(data); i++ {
		data[i] = rand.Intn(100)
	}
}

func main() {
	sliceLen := 10000
	totalCount := 100
	baseData := make([]int, sliceLen)

	basicQSortData := make([]int, sliceLen)
	basicQSortTime := 0
	basicMyQSortData := make([]int, sliceLen)
	basicMyQSortTime := 0
	midQSortData := make([]int, sliceLen)
	midQSortTime := 0
	motQSortData := make([]int, sliceLen)
	motQSortTime := 0
	motQSort2Data := make([]int, sliceLen)
	motQSort2Time := 0
	goSort := make([]int, sliceLen)
	goSortTime := 0
	goReverseSort := make([]int, sliceLen)
	goReverseSortTime := 0

	remainCount := totalCount
	for remainCount > 0 {
		remainCount--

		initData(baseData)
		dataCopy(basicQSortData, baseData)
		dataCopy(basicMyQSortData, baseData)
		dataCopy(midQSortData, baseData)
		dataCopy(motQSortData, baseData)
		dataCopy(motQSort2Data, baseData)
		dataCopy(goSort, baseData)
		dataCopy(goReverseSort, baseData)

		startTime := time.Now()
		basicQSort(basicQSortData)
		basicQSort(basicQSortData)
		basicQSortTime = basicQSortTime + int(time.Since(startTime))

		startTime = time.Now()
		basicMyQSort(basicMyQSortData)
		basicMyQSort(basicMyQSortData)
		basicMyQSortTime = basicMyQSortTime + int(time.Since(startTime))

		startTime = time.Now()
		midQSort(midQSortData, 0, len(midQSortData)-1)
		midQSort(midQSortData, 0, len(midQSortData)-1)
		midQSortTime = midQSortTime + int(time.Since(startTime))

		startTime = time.Now()
		motQSort(motQSortData)
		motQSort(motQSortData)
		motQSortTime = motQSortTime + int(time.Since(startTime))

		startTime = time.Now()
		motQSort2(motQSort2Data, 0, len(motQSort2Data)-1)
		motQSort2(motQSort2Data, 0, len(motQSort2Data)-1)
		motQSort2Time = motQSort2Time + int(time.Since(startTime))

		startTime = time.Now()
		sort.Sort(sort.IntSlice(goSort))
		sort.Sort(sort.IntSlice(goSort))
		goSortTime = goSortTime + int(time.Since(startTime))

		startTime = time.Now()
		sort.Sort(sort.Reverse(sort.IntSlice(goReverseSort)))
		sort.Sort(sort.Reverse(sort.IntSlice(goReverseSort)))
		goReverseSortTime = goReverseSortTime + int(time.Since(startTime))

		check0 := checkData(basicQSortData, goSort)
		check1 := checkData(basicMyQSortData, goSort)
		check2 := checkData(midQSortData, goSort)
		check3 := checkData(motQSortData, goSort)
		check4 := checkData(motQSort2Data, goSort)
		if !check0 || !check1 || !check2 || !check3 || !check4 {
			fmt.Println("fail Base Data :", baseData)
			if !check0 {
				fmt.Println("fail basicQSortData")
			}
			if !check1 {
				fmt.Println("fail basicMyQSortData")
			}
			if !check2 {
				fmt.Println("fail midQSortData")
			}
			if !check3 {
				fmt.Println("fail motQSortData")
			}
			if !check4 {
				fmt.Println("fail motQSort2Data")
			}
			break
		}
	}

	fmt.Println("sliceLen :", sliceLen)
	fmt.Println("count :", totalCount-remainCount)
	fmt.Println("basicQSort____Time :", basicQSortTime)
	fmt.Println("basicMyQSort__Time :", basicMyQSortTime)
	fmt.Println("midQSort______Time :", midQSortTime)
	fmt.Println("motQSort______Time :", motQSortTime)
	fmt.Println("motQSort2_____Time :", motQSort2Time)
	fmt.Println("goSort________Time :", goSortTime)
	fmt.Println("goReverseSort_Time :", goReverseSortTime)
}
