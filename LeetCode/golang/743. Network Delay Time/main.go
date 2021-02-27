package main

import "fmt"

var net [][]int
var ret []int

//set() 이 부분을 heap으로 pop, push처리하면 다익스트라 알고리즘이라고 한다.
//다익스트라 알고리즘은 전체적으로 퍼지면서 이동하고,
//목표를 향해 방향성을 갖고 더 빠르게 탐색하는 방식에는 에이스타 알고리즘이 있다고 한다.
func set(t, src int) {
	ret[src] = t
	nLen := len(net[src])
	for dst := 1; dst < nLen; dst++ {
		if net[src][dst] == -1 {
			continue
		}
		if ret[dst] != -1 && ret[dst] < net[src][dst]+t {
			continue
		}
		curTime := net[src][dst] + t
		ret[src] = curTime
		set(curTime, dst)
	}
}
func networkDelayTime(times [][]int, N int, K int) int {
	//init
	net = make([][]int, N+1)
	for i := 1; i <= N; i++ {
		net[i] = make([]int, N+1)
		for j := 1; j <= N; j++ {
			net[i][j] = -1
		}
	}
	//init set
	for _, time := range times {
		net[time[0]][time[1]] = time[2]
	}
	//init
	ret = make([]int, N+1)
	for i := 1; i <= N; i++ {
		ret[i] = -1
	}

	//set
	set(0, K)

	sumTime := 0
	for i := 1; i <= N; i++ {
		if ret[i] == -1 {
			return -1
		}
		sumTime += ret[i]
	}
	return sumTime
}

func main() {
	times := make([][]int, 0, 3)
	times = append(times, []int{2, 1, 1})
	times = append(times, []int{2, 3, 1})
	times = append(times, []int{3, 4, 1})
	fmt.Println(networkDelayTime(times, 4, 2)) //2
	// times = append(times, []int{2, 1, 1}) //source, target, time
	// times = append(times, []int{2, 3, 20})
	// times = append(times, []int{1, 3, 5})
	// times = append(times, []int{3, 4, 1})
	// fmt.Println(networkDelayTime(times, 4, 2)) //7
}
