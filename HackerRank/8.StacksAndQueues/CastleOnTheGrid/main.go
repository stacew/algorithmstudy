package main

import (
	"fmt"
	"strconv"
)

type myXY struct {
	x int32
	y int32
}
type myStack struct {
	stack []myXY
}

func (m *myStack) push(x, y int32) {
	var xy myXY
	xy.x = x
	xy.y = y
	m.stack = append(m.stack, xy)
}
func (m *myStack) pop() (myXY, bool) {
	var xy myXY
	if len(m.stack) == 0 {
		return xy, false
	}
	xy = m.stack[len(m.stack)-1]
	m.stack = m.stack[:len(m.stack)-1]
	return xy, true
}

func pushAndRecord(stack *myStack, record [][]int32, x, y, counter int32) bool {
	if record[x][y] != 0 {
		return false
	}
	(*stack).push(x, y)
	record[x][y] = counter
	return true
}

func minimumMoves(grid []string, x int32, y int32, gx int32, gy int32) int32 {
	size := int32(len(grid))
	var record [][]int32
	record = make([][]int32, size)
	for i := 0; i < int(size); i++ {
		record[i] = make([]int32, size)
	}

	var stack myStack
	pushAndRecord(&stack, record, x, y, 0)
	for {
		XY, ok := stack.pop()
		if !ok {
			break
		}
		x = XY.x
		y = XY.y
		counter := record[x][y] + 1
		//
		x = XY.x
		y = XY.y
		for x+1 < size && grid[x+1][y] == '.' {
			x = x + 1
			if pushAndRecord(&stack, record, x, y, counter) == false {
				break
			}
			if x >= gx {
				break
			}
		}
		if gx == x && gy == y {
			break
		}

		//
		x = XY.x
		y = XY.y
		for y+1 < size && grid[x][y+1] == '.' {
			y = y + 1
			if pushAndRecord(&stack, record, x, y, counter) == false {
				break
			}
			if y >= gy {
				break
			}
		}
		if gx == x && gy == y {
			break
		}

		//
		x = XY.x
		y = XY.y
		for x-1 >= 0 && grid[x-1][y] == '.' {
			x = x - 1
			if pushAndRecord(&stack, record, x, y, counter) == false {
				break
			}
			if x <= gx {
				break
			}
		}
		if gx == x && gy == y {
			break
		}
		//
		x = XY.x
		y = XY.y
		for y-1 >= 0 && grid[x][y-1] == '.' {
			y = y - 1
			if pushAndRecord(&stack, record, x, y, counter) == false {
				break
			}
			if y <= gy {
				break
			}
		}
		if gx == x && gy == y {
			break
		}
	}

	return record[gx][gy] - 1
}

func main() {
	fmt.Println(strconv.Itoa(int(minimumMoves([]string{
		".....",
		".....",
		".....",
		".....",
		"....."}, 0, 0, 2, 2)))) //2
	fmt.Println(strconv.Itoa(int(minimumMoves([]string{
		"..X..",
		"..X..",
		".....",
		".....",
		"....."}, 1, 1, 0, 4)))) //3

	fmt.Println(strconv.Itoa(int(minimumMoves([]string{
		"...",
		".X.",
		".X.",
	}, 2, 0, 2, 2)))) //3

	fmt.Println(strconv.Itoa(int(minimumMoves([]string{
		"...",
		".X.",
		".X.",
	}, 2, 0, 0, 2)))) //2
}

//A - Star?
// type myXY struct {
// 	x int32
// 	y int32
// }
// type myStack struct {
// 	stack []myXY
// }
// func (m *myStack) push(x, y int32) {
// 	var xy myXY
// 	xy.x = x
// 	xy.y = y
// 	m.stack = append(m.stack, xy)
// }
// func (m *myStack) pop() (myXY, bool) {
// 	var xy myXY
// 	if len(m.stack) == 0 {
// 		return xy, false
// 	}
// 	xy = m.stack[len(m.stack)-1]
// 	m.stack = m.stack[:len(m.stack)-1]
// 	return xy, true
// }
// func pushAndRecord(stack *myStack, record [][]int32, x, y int32) bool {
// 	if record[x][y] != 0 {
// 		return false
// 	}
// 	(*stack).push(x, y)
// 	record[x][y] = 1
// 	return true
// }

// pushAndRecord(&stack, record, x, y)
// for {
// 	XY, ok := stack.pop()
// 	if !ok {
// 		break
// 	}
// 	x = XY.x
// 	y = XY.y
// 	for x+1 < size && grid[x+1][y] == '.' {
// 		x = x + 1
// 		if pushAndRecord(&stack, record, x, y) == false {
// 			break
// 		}
// 		if x >= gx {
// 			break
// 		}
// 	}
// 	if gx == x && gy == y {
// 		break
// 	}
// 	x = XY.x
// 	y = XY.y
// 	for y+1 < size && grid[x][y+1] == '.' {
// 		y = y + 1
// 		if pushAndRecord(&stack, record, x, y) == false {
// 			break
// 		}
// 		if y >= gy {
// 			break
// 		}
// 	}
// 	if gx == x && gy == y {
// 		break
// 	}
// 	x = XY.x
// 	y = XY.y
// 	for x-1 >= 0 && grid[x-1][y] == '.' {
// 		x = x - 1
// 		if pushAndRecord(&stack, record, x, y) == false {
// 			break
// 		}
// 		if x <= gx {
// 			break
// 		}
// 	}
// 	if gx == x && gy == y {
// 		break
// 	}
// 	x = XY.x
// 	y = XY.y
// 	for y-1 >= 0 && grid[x][y-1] == '.' {
// 		y = y - 1
// 		if pushAndRecord(&stack, record, x, y) == false {
// 			break
// 		}
// 		if y <= gy {
// 			break
// 		}
// 	}
// 	if gx == x && gy == y {
// 		break
// 	}
// }
