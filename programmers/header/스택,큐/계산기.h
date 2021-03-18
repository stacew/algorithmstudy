#pragma once
#if 0
중위식->후위식
- 숫자는 바로 붙이고, 연산자를 Stack으로 관리!
- 복잡한 괄호 처리에 대해서 여기서 처리를 다 해야 한다.

후위식->계산 :
-숫자를 스택에 넣고, 연산자가 올 떄 마다 계산

TODO : 후위식을 String으로 UnParsing하려면% 에 대한 부분이나 - 를 연속적으로 들고 있는 부분에 대해서 token화가 필요할 것 같다.
#endif
class token {
private:
	bool bOperator;
	double num;
	char op;
public:
	void SetOp(char _op) {
		op = _op;
		num = 0;
		bOperator = true;
	}
	void SetNum(double _num) {
		num = _num;
		op = 0;
		bOperator = false;
	}
	double GetNum() { return num; }
	char GetOp() { return op; }
	bool isOp() { return bOperator; }
};


// string s(inFix) -> postFix
void infixToPostFix(const string& s, vector<token>& postFix) {
	// init 
	unordered_map<char, double> opMap;
	opMap['('] = -1; //이건 그냥.. 연산자 우선 순위로 pop할 때, map []에 조건문 하나 빼려고 추가함. (find로 하면 end 비교를 또 해야하기 때문에..)
	opMap['+'] = 0;// 낮을 수록 Stack 밑을 지킨다. (postFix 뒷쪽에 붙여야하는 연산자기 때문에)
	opMap['-'] = 0;
	opMap['*'] = 1;
	opMap['/'] = 1;

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

	char prevOp = '+';
	bool bMinus = false;
	bool bPrevNumber = false;
	double leftParenCount = 0;
	stack < token > stk;
	token temp;
	for (size_t i = 0; i < s.size(); i++) {

		// clip
		if (s[i] == ' ')
			continue;

		// number
		if (s[i] >= '0' && s[i] <= '9') {
			double minus = bMinus ? -1 : 1;
			temp.SetNum(minus * fParsingNumber(s, i));
			postFix.push_back(temp);
			bPrevNumber = true;
			bMinus = false;
			continue;
		}

		// %
		if (bPrevNumber && s[i] == '%') {
			size_t lastIndex = postFix.size() - 1;
			postFix.at(lastIndex).SetNum((postFix.at(lastIndex).GetNum() * 0.01));
			continue;
		}

		// +, -, *, /
		auto item = opMap.find(s[i]);
		if (item != opMap.end() && item->second >= 0) {
			if (bPrevNumber == false) {
				if (s[i] == '-') {
					bMinus = !bMinus;
				}
				else {
					;//remove ( or throw )
				}
				continue;
			}

			
			//우선순위가 높은 연산자를 postfix 뒤에 붙여준다.( 같은 연산자도 빨리 들어온게 우선 순위가 높아서 뽑아서 뒤에 붙여준다. )
			if (stk.empty() == false && opMap[stk.top().GetOp()] >= opMap[s[i]]) {
				postFix.push_back(stk.top());
				stk.pop();
			}

			temp.SetOp(s[i]);
			stk.push(temp);
			bPrevNumber = false;
			continue;
		}

		// (
		if (s[i] == '(') {
			leftParenCount++;
			temp.SetOp('(');
			stk.push(temp);
			continue;
		}

		// )
		if (s[i] == ')') {
			if (leftParenCount <= 0) {
				continue;//remove ( or throw )
			}

			while (true) {
				//괄호 check가 우선
				if (stk.top().GetOp() == '(') {
					stk.pop();
					break;
				}

				postFix.push_back(stk.top());
				stk.pop();
			}

			//괄호 직전의 연산자를 추가 처리해줘야 한다.
			if (stk.empty() == false && stk.top().GetOp() != '(') {
				postFix.push_back(stk.top());
				stk.pop();
			}

			leftParenCount--;
			continue;
		}

		// exception
		;//remove ( or throw )
	}

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
		if (tok.isOp() == false) {
			stk.push(tok.GetNum());
		}
		else {
			double num2 = stk.top();
			stk.pop();
			double num1 = stk.top();
			stk.pop();
			stk.push(fCalc(num1, num2, tok.GetOp()));
		}
	}

	return stk.top();
}



void solution() {
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
	tester["1*(2-(2+4-1-2*(5)+3/2*2212+23))+12312%-1313"] = -4523.88;
#endif

	cout << "-------- unit test Start --------" << endl;
	for (const auto item : tester) {
		vector<token> postFix;
		infixToPostFix(item.first, postFix);
		double ret = postFixToCalcNumber(postFix);
		if (item.second != ret)
			cout << "False : " << item.first << ", != " << ret << endl;
	}
	cout << "-------- unit test End --------" << endl;
}