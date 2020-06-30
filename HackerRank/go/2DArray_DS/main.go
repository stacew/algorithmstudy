package main

func hourglassSum(arr [][]int32) int32 {
	m := len(arr)
	var retMax int32 = -63
	for i := 0; i < m-2; i++ {
		for j := 0; j < m-2; j++ {
			nTemp := arr[i][j] + arr[i][j+1] + arr[i][j+2] +
				arr[i+1][j+1] +
				arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2]
			if nTemp > retMax {
				retMax = nTemp
			}
		}
	}
	return retMax
}
