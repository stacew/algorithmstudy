package main

import "fmt"

type myStack struct {
	stack []byte
}

func (m *myStack) push(s byte) {
	m.stack = append(m.stack, s)
}
func (m *myStack) pop() (byte, bool) {
	if len(m.stack) == 0 {
		return '-', false
	}
	ret := m.stack[len(m.stack)-1]
	m.stack = m.stack[:len(m.stack)-1]
	return ret, true
}

func isBalanced(s string) string {
	if len(s)%2 == 1 {
		return "NO"
	}
	var stack myStack
	for i := 0; i < len(s); i++ {
		if checkPush(s[i]) {
			stack.push(s[i])
			continue
		}
		c, exist := stack.pop()
		if exist == false {
			return "NO"
		}
		if checkBracket(c, s[i]) == false {
			return "NO"
		}
	}

	if _, exist := stack.pop(); exist {
		return "NO"
	}
	return "YES"
}

func checkPush(a byte) bool {
	if a == '{' || a == '[' || a == '(' {
		return true
	}
	return false
}
func checkBracket(a, b byte) bool {
	if a == '{' && b == '}' {
		return true
	} else if a == '[' && b == ']' {
		return true
	} else if a == '(' && b == ')' {
		return true
	}
	return false
}

func main() {
	fmt.Println(isBalanced("{[()]}"))         //y
	fmt.Println(isBalanced("{[(])}"))         //n
	fmt.Println(isBalanced("{{[[(())]]}}"))   //y
	fmt.Println(isBalanced("{(([])[])[]}"))   //y
	fmt.Println(isBalanced("{(([])[])[]]}"))  //n
	fmt.Println(isBalanced("{(([])[])[]}[]")) //y
}
