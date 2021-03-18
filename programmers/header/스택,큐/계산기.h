#pragma once
#if 0
������->������
- ���ڴ� �ٷ� ���̰�, �����ڸ� Stack���� ����!
- ������ ��ȣ ó���� ���ؼ� ���⼭ ó���� �� �ؾ� �Ѵ�.

������->��� :
-���ڸ� ���ÿ� �ְ�, �����ڰ� �� �� ���� ���

TODO : �������� String���� UnParsing�Ϸ���% �� ���� �κ��̳� - �� ���������� ��� �ִ� �κп� ���ؼ� tokenȭ�� �ʿ��� �� ����.
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
	opMap['('] = -1; //�̰� �׳�.. ������ �켱 ������ pop�� ��, map []�� ���ǹ� �ϳ� ������ �߰���. (find�� �ϸ� end �񱳸� �� �ؾ��ϱ� ������..)
	opMap['+'] = 0;// ���� ���� Stack ���� ��Ų��. (postFix ���ʿ� �ٿ����ϴ� �����ڱ� ������)
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

			
			//�켱������ ���� �����ڸ� postfix �ڿ� �ٿ��ش�.( ���� �����ڵ� ���� ���°� �켱 ������ ���Ƽ� �̾Ƽ� �ڿ� �ٿ��ش�. )
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
				//��ȣ check�� �켱
				if (stk.top().GetOp() == '(') {
					stk.pop();
					break;
				}

				postFix.push_back(stk.top());
				stk.pop();
			}

			//��ȣ ������ �����ڸ� �߰� ó������� �Ѵ�.
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