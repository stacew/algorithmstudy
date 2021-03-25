#pragma once
#if 0

중위식->후위식
- 숫자는 바로 붙이고, 연산자를 Stack으로 관리!
- 복잡한 괄호 처리에 대해서 여기서 처리를 다 해야 한다.

후위식->계산 :
-숫자를 스택에 넣고, 연산자가 올 떄 마다 계산

괄호 및 + , -, % unparsing 가능한 postfix 생성.

leetcode 224. Basic Calculator 호환됨.

#endif

class token {
private:
	bool bOperator;
	double num;
	char op;
public:
	static token SetOp(char _op) {
		token ret;
		ret.op = _op;
		ret.num = 0;
		ret.bOperator = true;
		return ret;
	}
	static token SetNum(double _num) {
		token ret;
		ret.num = _num;
		ret.op = 0;
		ret.bOperator = false;
		return ret;
	}
	double GetNum() { return num; }
	char GetOp() { return op; }
	bool isOp() { return bOperator; }
};


class Solution {
public:
	double calculate(string s) {
		vector<token> postFix;
		infixToPostFix(s, postFix);
		return postFixToCalcNumber(postFix);
	}
private:
	// string s(inFix) -> postFix
	void infixToPostFix(const string& s, vector<token>& postFix) {
		// init 
		unordered_map<char, double> opMap;

		opMap['('] = -10;	//연산자 우선 순위로 pop할 때, map []에 조건문 하나 빼려고 추가함. (find로 하면 end 비교를 또 해야하기 때문에..)
							//어차피 우선 순위의 의미도 있고, 넣는게 확실히 좋은듯..?

		opMap['+'] = 0;// 낮을 수록 Stack 밑을 지킨다. (postFix 뒷쪽에 붙여야하는 연산자기 때문에)
		opMap['-'] = 0;
		opMap['*'] = 1;
		opMap['/'] = 1;

		//단항 연산자
		opMap['N'] = 10;
		opMap['P'] = 10;
		opMap['%'] = 10;

		auto fParsingNumber = [](const string& s, size_t& ref_i) {
			double num = 0;
			for (; ref_i < s.size(); ref_i++) {
				if ((s[ref_i] >= '0' && s[ref_i] <= '9') == false)
					break;
				num *= 10;
				num += s[ref_i] - '0';
			}
			ref_i--; //
			return num;
		};

		bool bPrevNumber = false;
		double leftParenCount = 0;
		stack < token > stk;
		for (size_t i = 0; i < s.size(); i++) {

			// clip
			if (s[i] == ' ')
				continue;

			// number
			if (s[i] >= '0' && s[i] <= '9') {
				postFix.push_back(token::SetNum(fParsingNumber(s, i)));
				bPrevNumber = true;
				continue;
			}

			// % bPrevNumber가 true 필수. 아니면 throw
			if (s[i] == '%') {
				if (bPrevNumber) {
					stk.push(token::SetOp('%'));
				}
				else {
					;//remove ( or throw )
				}
				continue;
			}

			// +, -, *, /, 단항 +, 단항 -, 단항%
			auto item = opMap.find(s[i]);
			if (item != opMap.end() && item->second >= 0) {

				//+, - 까지는 단항 연산자 처리
				if (bPrevNumber == false) {
					if (s[i] == '-') { stk.push(token::SetOp('N')); }
					else if (s[i] == '+') { stk.push(token::SetOp('P')); }
					else { ; }//remove ( or throw )

					continue;
				}

				//우선순위가 높은 연산자를 postfix 뒤에 붙여준다.( 같은 연산자도 빨리 들어온게 우선 순위가 높아서 뽑아서 뒤에 붙여준다. )
				while (stk.empty() == false && opMap[stk.top().GetOp()] >= opMap[s[i]]) {
					postFix.push_back(stk.top());
					stk.pop();
				}

				stk.push(token::SetOp(s[i]));
				bPrevNumber = false;
				continue;
			}

			// (
			if (s[i] == '(') {
				leftParenCount++;
				stk.push(token::SetOp('('));
				continue;
			}

			// )
			if (s[i] == ')') {
				if (leftParenCount <= 0) {
					continue;//remove ( or throw )
				}

				while (stk.top().GetOp() != '(') { // ( 가 나오기 전까지 연산자를 후위로 옮긴다.
					postFix.push_back(stk.top());
					stk.pop();
				}

				postFix.push_back(stk.top()); //계산에서는 skip 하지만, 추후 unparsing을 하기 위해 괄호 정보 삽입
				stk.pop(); // ( 를 제거

				leftParenCount--;
				continue;
			}

			// exception
			;//remove ( or throw )
		}

		//마지막 stack 처리
		while (stk.empty() == false) {
			postFix.push_back(stk.top());
			stk.pop();
		}
	}

	// PostFix -> CalcNumber
	double postFixToCalcNumber(vector<token>& postFix) {

		auto fCalc = [](double num1, double num2, char op) {
			if (op == '+')
				return num1 + num2;
			else if (op == '-')
				return num1 - num2;
			else if (op == '*')
				return num1 * num2;
			else//if (op == '/')
				return num1 / num2;
		};

		stack<double> stk;
		for (auto& tok : postFix) {

			if (tok.isOp() == false) { //숫자는 스택 삽입
				stk.push(tok.GetNum());
				continue;
			}

			if (tok.GetOp() == '(' || tok.GetOp() == 'P') //괄호 및 의미 없는 + 단항연산자는 계산에서는 제외, unparsing에서만 사용
				continue;

			if (tok.GetOp() == '%') {
				stk.top() *= 0.01;
				continue;
			}

			if (tok.GetOp() == 'N') {
				stk.top() *= -1;
				continue;
			}

			//일반 연산자
			double num2 = stk.top();
			stk.pop();
			double num1 = stk.top();
			stk.pop();
			stk.push(fCalc(num1, num2, tok.GetOp()));
		}

		return stk.top();
	}
};


void func() {
	unordered_map<string, double> tester;
#if 1
	tester["2*3*-5"] = -30;
	tester["-2*-3*-5"] = -30;
	tester["----2*++3*5"] = 30;
	tester["-2*3 +5"] = -1;
	tester["-2*3 +5000%"] = 44;
	tester["1+(2)"] = 3;
	tester["1+((((2))))"] = 3;
	tester["1 - ( 2 * ( 1 - 2 ) )"] = 3;
	tester["1 - ( 2 - ( 1 - 2 ) )"] = -2;
	tester["1 - ( 2 - ( 1 - 2 ) ) + 10"] = 8;
	tester["1 * ( 2 * ( 1 - 2 ) ) * 10"] = -20;
	tester["- 2 + 3 * 5 - ( 2 * 3 * ( 1 + 2 ) ) + 10"] = 5;
	tester["-2 + 3 * 5 - ( 2 + 3 - ( 1 - 2 ) ) + 10"] = 17;
	tester["-2 + 3 * 5 - (2 * -3 * (1 + 2)) + 10"] = 41;
	tester["1-(3-2+1)"] = -1;
	tester["- (4 + 5)"] = -9;
	tester["- (3 + (4 + 5))"] = -12;
	tester["12312%-1313"] = -1189.88;
	tester["-2*5+3*2*2212+23"] = 13285;
	tester["-1-2*5+3"] = -8;
	tester["1*(2-(2+4-1-2*(5)+3/2*2212+23))+12312%-1313"] = -4523.88;
	tester["1*(2-(2+4-1-2*(5)+3/2*2212+23))"] = -3334;
	tester["(2+4-1-2*(5)+3*2*2212+23)"] = 13290;
#endif

	cout << "-------- unit test Start --------" << endl;
	Solution sol;
	for (const auto item : tester) {
		double ret = sol.calculate(item.first);
		if (item.second != ret)
			cout << "False : " << item.first << " = " << item.second << ", ( myReturn : " << ret << " )" << endl;
	}
	cout << "-------- unit test End --------" << endl;
}