package main

import (
	"fmt"
	"strconv"
)

type direction int32

const (
	none direction = iota
	left
	right
	top
	bottom
)

type qData struct {
	x, y int32
	d    direction
	c    int32
}

type myQueue struct {
	slice []*qData
}

func (m *myQueue) push(x, y int32, d direction, counter int32) {
	qData := &qData{x: x, y: y, d: d, c: counter}
	m.slice = append(m.slice, qData)
}

func (m *myQueue) pop() (*qData, bool) {
	if len(m.slice) == 0 {
		return &qData{}, false
	}

	data := m.slice[0]
	m.slice = m.slice[1:]
	return data, true
}

// func process(x, y, counter int32, q *myQueue, d direction, grid []string, record [][]int32) bool {
// 	size := int32(len(grid))
// 	if x < 0 || y < 0 || x >= size || y >= size || grid[x][y] == 'X' {
// 		return false
// 	}

// 	prev := record[x][y]
// 	if prev

// 	record[x][y] = counter

// 	dx := x
// 	dy := y
// 	switch d {
// 	case left:
// 		for dx-1 >= 0 {
// 			dx = dx - 1
// 			if process(dx, y, counter, q, d, grid, record) == false {
// 				break
// 			}
// 		}
// 	case right:
// 		for dx+1 < size {
// 			dx = dx + 1
// 			if process(dx, y, counter, q, d, grid, record) == false {
// 				break
// 			}
// 		}
// 	case top:
// 		for dy-1 >= 0 {
// 			dy = dy - 1
// 			if process(x, dy, counter, q, d, grid, record) == false {
// 				break
// 			}
// 		}
// 	case bottom:
// 		for dy+1 < size {
// 			dy = dy + 1
// 			if process(x, dy, counter, q, d, grid, record) == false {
// 				break
// 			}
// 		}
// 	default: //none, first
// 		q.push(x-1, y, left, counter)
// 		q.push(x+1, y, right, counter)
// 		q.push(x, y-1, top, counter)
// 		q.push(x, y+1, bottom, counter)
// 	}

// 	if prev != 0 {
// 		return true
// 	}
// 	q.push(x-1, y, left, counter+1)
// 	q.push(x+1, y, right, counter+1)
// 	q.push(x, y-1, top, counter+1)
// 	q.push(x, y+1, bottom, counter+1)
// 	return true
// }

func process(x, y, counter int32, q *myQueue, d direction, grid []string, record [][]int32) bool {
	size := int32(len(grid))
	if x < 0 || y < 0 || x >= size || y >= size || grid[x][y] == 'X' {
		return false
	}
	if record[x][y] != 0 && record[x][y] < counter {
		return false
	}
	record[x][y] = counter
	switch d {
	case left:
		q.push(x-1, y, left, counter)
		q.push(x, y-1, top, counter+1)
		q.push(x, y+1, bottom, counter+1)
	case right:
		q.push(x+1, y, right, counter)
		q.push(x, y-1, top, counter+1)
		q.push(x, y+1, bottom, counter+1)
	case top:
		q.push(x-1, y, left, counter+1)
		q.push(x+1, y, right, counter+1)
		q.push(x, y-1, top, counter)
	case bottom:
		q.push(x-1, y, left, counter+1)
		q.push(x+1, y, right, counter+1)
		q.push(x, y+1, bottom, counter)
	default: //none, first
		q.push(x-1, y, left, counter)
		q.push(x+1, y, right, counter)
		q.push(x, y-1, top, counter)
		q.push(x, y+1, bottom, counter)
	}
	return true
}

func minimumMoves(grid []string, x, y, gx, gy int32) int32 {
	n := len(grid)
	record := make([][]int32, n)
	for i := 0; i < n; i++ {
		record[i] = make([]int32, n)
	}

	var q myQueue
	process(x, y, int32(1), &q, none, grid, record)
	testCount := 0
	for true {
		data, ok := q.pop()
		if !ok {
			break
		}
		process(data.x, data.y, data.c, &q, data.d, grid, record)
		testCount++
	}
	fmt.Println("testCount : ", strconv.Itoa(testCount))
	return record[gx][gy]
}

func main() {
	fmt.Println(strconv.Itoa(int(minimumMoves([]string{
		"X...",
		"...X",
		".X..",
		"...."}, 0, 1, 3, 2))))

	// fmt.Println(strconv.Itoa(int(minimumMoves([]string{
	// 	".....",
	// 	"...X.",
	// 	"..X..",
	// 	".X...",
	// 	"....."}, 0, 0, 3, 3))))

	// fmt.Println(strconv.Itoa(int(minimumMoves([]string{
	// 	"...",
	// 	".X.",
	// 	".X."}, 2, 0, 2, 2))))
	// fmt.Println(strconv.Itoa(int(minimumMoves([]string{
	// 	"...X......XX.X...........XX....X.XX.....",
	// 	".X..............X...XX..X...X........X.X",
	// 	"......X....X....X.........X...........X.",
	// 	".X.X.X..X........X.....X.X...X.....X..X.",
	// 	"....X.X.X...X..........X..........X.....",
	// 	"..X......X....X....X...X....X.X.X....XX.",
	// 	"...X....X.......X..XXX.......X.X.....X..",
	// 	"...X.X.........X.X....X...X.........X...",
	// 	"XXXX..X......X.XX......X.X......XX.X..XX",
	// 	".X........X....X.X......X..X....XX....X.",
	// 	"...X.X..X.X.....X...X....X..X....X......",
	// 	"....XX.X.....X.XX.X...X.X.....X.X.......",
	// 	".X.X.X..............X.....XX..X.........",
	// 	"..X...............X......X........XX...X",
	// 	".X......X...X.XXXX.....XX...........X..X",
	// 	"...X....XX....X...XX.X..X..X..X.....X..X",
	// 	"...X...X." /*28*/ + "X.....X.....X.....XXXX.........", //16
	// 	"X.....XX..X.............X.XX.X.XXX......",
	// 	".....X.X..X..........X.X..X...X.X......X",
	// 	"...X.....X..X.............X......X..X..X",
	// 	"........X.....................X....X.X..",
	// 	"..........X.....XXX...XX.X..............",
	// 	"........X..X..........X.XXXX..X.........",
	// 	"..X..X...X.......XX...X.....X...XXX..X..",
	// 	".X.......X..............X....X...X....X.",
	// 	".................X.....X......X.....X...",
	// 	".......X.X.XX..X.XXX.X.....X..........X.",
	// 	"X..X......X..............X..X.X.......X.",
	// 	"X........X.....X.....X....XX.......XX...",
	// 	"X.....X.................X.....X..X...XXX",
	// 	"XXX..X..X.X.XX..X....X.....XXX..X......X",
	// 	"..........X.....X.....XX................",
	// 	"..X.........X..X.........X...X.....X....",
	// 	".X.X....X...XX....X...............X.....",
	// 	".X....X....XX.XX........X..X." /*28*/ + "...........", //34
	// 	"X...X.X................XX......X..X.....",
	// 	"..X.X.......X.X..X.....XX.........X..X..",
	// 	"........................X..X.XX..X......",
	// 	"........X..X.X.....X.....X......X.......",
	// 	".X..X....X.X......XX...................."}, 34, 28, 16, 8))))

	fmt.Println(strconv.Itoa(int(minimumMoves([]string{
		".X..X.X..X..X.......XX..XX....X.X...X........X.....XX.X.X...X.X...X..X",
		"...X.....XX.........XX......X.X.......X......X..XX.X..X..X.....X.X....",
		"............X.......X........X..X.X......X.......X...X.X.....X.X...X..",
		".........X....XX.X.X.X......X..X......X.....X.........X..X.......XX...",
		".....X.......X.X.....XX.....X.XXX.........X.....X.X....XX......XX.....",
		"..X....X..........................X...X.........XX.....X..............",
		"......X.......X...XX.....X.X....X.......X.............X........X.X....",
		"...X.X.XX.XX...X............XX...X.....X..X..X....X.........X.........",
		"X.XX........X..........XX..X.X..X.XX.XXX..X........X..X.....XX......X.",
		"......X..XXX.......X..XX.XX...........X.....XX..X..X.X......X.X...X...",
		"X........X.X....X..X..................XX......X..X.......X.....X..X...",
		"...X......X....XX.......X.....X...........X..X....X.....XXX...X...X.X.",
		"......X..X....X.XXX.X.....X..X....XX.....X....X.....X...X...........X.",
		"....X..X.X...XX..X.X.X..X.....X......X..X......X.X.X.X......X......X..",
		"..X..............X...X.........X........X...........X..X.X......X....X",
		".X....X..X......X.........X.....XX....XX............XX..X...X...X.....",
		"...........X....X.X...XX...X......X...............X....XX..........X..",
		".X..X..XX..X...X.....XX...XX...........X.....X..XXX.........XX..X....X",
		".XX........XX.XX..........XX............X.........X.XXXX.X.X.........X",
		".....X........X......X.............X.......X............X....X...X..X.",
		"X..X.X..X...........XX..X.....X......X...XXX........XX...........X....",
		"..X....X.XX.X.....X..X..X...........X......X..........X.....X.......X.",
		"..........X.X...X.....X....XX.XX.......XX...X.............XXX..X..X..X",
		"X.....X....XX...X.X...X.X.X..X.X..X....X..X..XXX...X...........X.X.X..",
		"...XX.X....X...X.....XX...X.....X..XXX.......XX......X....XX......X.XX",
		"X..X......X.....X......X.X...X............X.X..........X.X.X..X......X",
		"..X....X..X.X....XX....X.XXX..X.XX.....X........X..X...X...X.X......X.",
		".......X...............XX..........X...X......XX...X.X........X.......",
		"XXX....X.....X..X.....X.X.....XX..X.......X..X.....XX.......X..X.....X",
		".......X......X.......X..X.......X.........X...X.........X...X.....XXX",
		"...X..X....X....X.X..XX......X.......X............X...................",
		".X.....X............X...............X.....X.X...X...X.XXX..X....X..XXX",
		"..........X........X...........XX..........X..............X.....XX.X..",
		".X...............XX..X.X......................X..X...X......X.....X...",
		"XX..X.X..XXXX..X..........XX..XX..X.............X................XX...",
		"......X.XX..X...............X.X....X....X......X.....X..XX............",
		"..X.X..X..X......X..X................X......X...X......X.XX...X..X....",
		".........X............X......X......XX.X..................X.....X.....",
		"X..X....X...........X.....XX..X.......XXX.....XXX.......X....X.....X.X",
		"XX..............XXX....X.X......XX..........X....X.....X......X.......",
		".......X.XX.......X......X..XXX.............X.......XX.....X.XX.......",
		"..X.X.....XXX.X.......X.X.........X..X...X...X..X.....X.....XX.......X",
		"..XX........XX....X..XX..X...XXX.................X..X...........X.....",
		"...X........X..X.....X......X.X...XXX..X..XX.X..X...X........X.XXXX...",
		"...X.X....X.....X.X.......X..............X...X.X.XX...X...XX.X.......X",
		"......X...........X.......X.....XXXX...........X.X.XX......X...X......",
		"....X......X......XXX..XX.X.......X.............X.......X.........X..X",
		"..X..X..X......X.....X............XX....X..........X......X..X..X.X...",
		"X.........X..X..XX........X.X.X......................X.X....X.....X...",
		".....X.X...X.X..X...X...XX...X...X............X..............X...X....",
		"......................X....X...X....X.X..............XX.....X.........",
		".................X..X.....X.....XX......X.......X......X.........X.X..",
		"...........X..X...X.....X..X.............X............X..X..XX.X......",
		"X..........X.X..X..X..........X.XX.............X...X.XX........X......",
		"..XX.XX.....X.....X..X.....X.....X...X...........X..X..X....X.........",
		"..X.XX...X.X....X.X....X..X.X...X..X.........X..X.....................",
		"............X...................X....X.X......X.XX..X...X....X..XX.XX.",
		"...X..X.X....X..............X..X.....X.X.........X..........X.......X.",
		"..X...........................X......X.X...X........X.................",
		".........X..X...............X...........X..X.X......X.................",
		"..XX.............XX.X.........X....XX........X..X...X........X.....X..",
		".............X.X....X.X...X...X.....X...X.....X.....X..X......X......X",
		".....X....X.X.X...XXX...X.X.X.X...X...X.X.....X..X...........X.X.X...X",
		"...XX.X...XX......X..........X.......XX..X.......X...X..X.X......X....",
		".......X.......X....................X..........XX.....XXXX..X.X.......",
		".....X...XX...X........X..X...X.X...X..........X...X.........X........",
		"XXX..XX.....X...................X.....X.X.......X.X.X..X..............",
		"....X.........X.....X.X...XX.....XX......X..........XX..X.XXX...X.X...",
		"..X...............X.XX.......X....X......X......X.X.X.......X.......X.",
		"..X.X.......XXX..X....X...X....X.....X.X......X..X......X............."}, 2, 42, 68, 12))))
}

// " X  X X  X  X       XX  XX    X X   X        X     XX X X   X X   X  X",
// "   X     XX         XX      X X       X      X  XX X  X  X     X X    ",
// "            X       X        X  X X      X11     X   X X     X X   X  ",
// "         X    XX X X X      X  X      X    2X         X  X       XX   ",
// "     X       X X     XX     X XXX         X2    X X    XX      XX     ",
// "  X    X                          X   X    2    XX     X              ",
// "      X       X   XX     X X    X       X  2          X        X X    ",
// "   X X XX XX   X            XX   X     X  X2 X    X         X         ",
// "X XX        X          XX  X X  X XX XXX  X2       X  X     XX      X ",
// "      X  XXX       X  XX XX           X    2XX  X  X X      X X   X   ",
// "X        X X    X  X                  XX   2  X  X       X     X  X   ",
// "   X      X    XX       X     X           X2 X    X     XXX   X   X X ",
// "      X  X    X XXX X     X  X    XX     X 2  X     X   X           X ",
// "    X  X X   XX  X X X  X     X      X  X  2   X X X X      X      X  ",
// "  X              X @ X         X        X  2        X  X X      X    X",
// " X    X  X      X  @      X     XX    XX   2        XX  X   X   X     ",
// "           X    X X@  XX   X      X   333332      X    XX          X  ",
// " X  X  XX  X   X   @ XX   XX          4X   2 X  XXX         XX  X    X",
// " XX        XX XX   @      XX          4 X  2      X XXXX X X         X",
// "     X        X    @ X             X  4    X            X    X   X  X ",
// "X  X X  X          @XX  X     X  6   X4  XXX        XX           X    ",
// "  X    X XX X     X@ X  X           X 4    X          X     X       X ",
// "          X X   X  @  X    XX XX      4XX   X             XXX  X  X  X",
// "X     X    XX   X X@  X X X  X X  X   4X  X  XXX   X           X X X  ",
// "   XX X    X   X   @ XX   X     X  XXX4      XX      X    XX      X XX",
// "X  X      X     X  @   X X   X        4   X X          X X X  X      X",
// "  X    X  X X    XX@   X XXX  X XX    4X        X  X   X   X X      X ",
// "       X           @   XX          X  4X      XX   X X        X       ",
// "XXX    X     X  X  @  X X     XX  X   4   X  X     XX       X  X     X",
// "       X      X    @  X  X       X    4    X   X         X   X     XXX",
// "   X  X    X @@ X X@ XX      X       X4           X                   ",
// " X     X     @@    @X               X 4   X X   X   X XXX  X    X  XXX",
// "          X  @@    X           XX     45555X              X     XX X  ",
// " X           @@  XX  X X0             @   6   X  X   X      X     X   ",
// "XX  X X  XXXX@@X          XX  XX  X   @   6     X                XX   ",
// "      X XX  X@@             X X    X  @ X 6    X     X  XX            ",
// "  X X  X  X  @@  X  X                X@   6 X   X      X XX   X  X    ",
// "         X   @@       X      X      XX@X  6               X     X     ",
// "X  X    X    @@     X     XX  X       XXX 6   XXX       X    X     X X",
// "XX           @@ XXX    X X      XX    @   6 X    X     X      X       ",
// "       X XX  @@   X      X  XXX       @   6 X       XX     X XX       ",
// "  X X     XXX X       X X         X  X@  X6 @X  X     X     XX       X",
// "  XX        XX    X  XX  X   XXX@    777776      X  X           X     ",
// "   X        X  X     X      X X   XXX8@X  XX X  X   X        X XXXX   ",
// "   X X    X     X X       X@    @    8@  X@@@X X XX   X   XX X       X",
// "      X           X       X     XXXX 8@   @@@  X X XX      X   X      ",
// "    X      X      XXX  XX X       X  8@   @@@   X       X         X  X",
// "  X  X  X      X     X            XX 8@ X @@@      X      X  X  X X   ",
// "X         X  X @XX        X X X      8@   @@@        X X    X     X   ",
// "     X X   X X @X   X   XX @@X   X   8@   @@@ X              X   X    ",
// "       @       @      X    X   X    X8X   @@@        XX     X         ",
// "       @       @ X  X     X     XX   8@ X @@@   X      X         X X  ",
// "       @   X  X@  X     X  X 999999998@  X@@@         X  X  XX X      ",
// "X      @   X X @X  X         0X XX   8@   @@@  X   X XX        X      ",
// "  XX XX@    X  @  X@ X     X 0   X   X@   @@@    X  X  X    X         ",
// "  X XX @ X X   @X X@   X  X X0  X@ X  @   @@@X  X                     ",
// "       @    X  @11111111111110  X@   X@X  @@@ X XX  X   X    X  XX XX ",
// "   X  X@X    X @2  @        X  X @   X@X  @@@    X          X       X ",
// "  X    @       @2  @          X  @   X@X  @X        X                 ",
// "       @ X  X  @2  @        X    @    @ X @X X      X                 ",
// "  XX   @       @2XX@X         X  @ XX @   @  X  X   X        X     X  ",
// "       @     X X2@ @X X   X   X  @  X @ X @   X     X  X      X      X",
// "     X @  X X X 2@XXX @ X X X X  @X   X X @   X  X           X X X   X",
// "   XX X@  XX    2@X   @      X   @   XX  X@      X   X  X X      X    ",
// "       X   @   X2@    @          @  X     @    XX     XXXX  X X       ",
// "     X @@XX@  X 2@    @X  X   X X@  X     @    X   X         X        ",
// "XXX  XX@@  @X   2@    @         X@    X X @     X X X  X              ",
// "    X  @@  @  X 2@  X X   XX     XX      X@         XX  X XXX   X X   ",
// "  X    @@  @33332@X XX       X    X      X@     X X X       X       X ",
// "  X X       XXX  X    X   X    X     X X  @   X  X      X             "}, 2, 42, 68, 12))))

// "...X......XX.X...........XX....X.XX.....",
// ".X..............X...XX..X...X........X.X",
// "......X....X....X.........X...........X.",
// ".X.X.X..X........X.....X.X...X.....X..X.",
// "....X.X.X...X..........X..........X.....",
// "..X......X....X....X...X....X.X.X....XX.",
// "...X....X.......X..XXX.......X.X.....X..",
// "...X.X.........X.X....X...X.........X...",
// "XXXX..X......X.XX......X.X......XX.X..XX",
// ".X........X....X.X......X..X....XX....X.",
// "...X.X..X.X.....X...X....X..X....X......",
// "....XX.X.....X.XX.X...X.X.....X.X.......",
// ".X.X.X..............X.....XX..X.........",
// "..X...............X......X........XX...X",
// ".X......X...X.XXXX.....XX...........X..X",
// "...X....XX....X...XX.X..X..X..X.....X..X",
// "...X...X9X.....X.....X.....XXXX.........",//16
// "X.....XX9.X.............X.XX.X.XXX......",
// ".....X.X9.X..........X.X..X...X.X......X",
// "...X...78X..X.............X......X..X..X",
// ".......7X.....................X....X.X..",
// ".......7..X.....XXX...XX.X..............",
// ".......7X..X..........X.XXXX..X.........",
// "..X..X.7.X.......XX...X.....X...XXX..X..",
// ".X.....7.X6666666666665.X....X...X....X.",
// ".......6587......X....5X......X.....X...",
// ".......X5X.XX..X.XXX.X5....X..........X.",
// "X..X....5.X...........5..X..X.X.......X.",
// "X.......5X.....X.....X5...XX.......XX...",
// "X.....X44444444444443.5.X.....X..X...XXX",
// "XXX..X..X.X.XX..X...3X443..XXX..X......X",
// "..........X.....X...3.XX22221...........",
// "..X.........X..X....3....X..1X.....X....",
// ".X.X....X...XX....X2222222221.....X.....",
// ".X....X....XX.XX........X..X1...........", //34
// "X...X.X................XX...1..X..X.....",
// "..X.X.......X.X..X.....XX...1.....X..X..",
// "........................X..X.XX..X......",
// "........X..X.X.....X.....X......X.......",
// ".X..X....X.X......XX...................."}, 34, 28, 16, 8))))

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
