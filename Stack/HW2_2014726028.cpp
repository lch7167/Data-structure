// homework2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴
#include <cstdlib>
#include <cstring>
#include <stack>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

const char SYMBOLS[] = {'*','/','+','-','(',')','{','}','[',']' };

//괄호 검사함수
bool is_balanced_parentheses(string s);
//infix 에서 postfix로 변환
vector<string> infix_to_postfix(vector<string> v);
//postfix식 계산
bool postfix_calculate(vector<string>v, double& result);
//계산//
bool calculate(double n1, double n2, char op, double& result);
//우선순위 배정
int order(string op);
//계산 최소 단위로 나누기
vector<string> string_to_tok(string strTarget);
//문자열 수정
string replaceAll(string str, const string& pattern, const string& replace);
//계산식을 읽고 그 식의 값을 구해 출력
bool read_and_evaluate();

int main() {
	while (read_and_evaluate());
	return 0;
}

bool read_and_evaluate()
{
	string input;
	double* answer = new double;
	cout << "Input :";
	cin >> input;
	vector<string> v;
	if (input == "EOI") // EOI 입력받으면 종료
		return false;
	if (!is_balanced_parentheses(input)) {
		cout << "error! : unbalanced parentheses" << endl;
	}
	else {
		v = string_to_tok(input);
		if (postfix_calculate(infix_to_postfix(v), *answer))
		{
			cout << fixed;
			cout.precision(3); //소수점 3째자리까지 출력
			cout << *answer << endl;
		}
		else
			cout << "error!: divided by zero" << endl;
	}
	return true;
}

bool is_balanced_parentheses(string s)
{
	stack<char> parentheses;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == SYMBOLS[4])
		{
			parentheses.push(SYMBOLS[4]);
		}
		else if (s[i] == SYMBOLS[5])
		{
			if (parentheses.empty())
			{
				cout << "error! : unbalanced parentheses" << endl;
			}
			else
			{
				parentheses.pop();
			}
		}
	}
	return parentheses.empty();
}

bool calculate(double n1, double n2, char oper, double& result)
{
	if (n2 == 0 && oper == '/') // 0으로 나누면
		return false;
	switch (oper)
	{
	case '+': result = n1 + n2;
		break;
	case '-': result = n1 - n2;
		break;
	case '*': result = n1 * n2;
		break;
	case '/': result = n1 / n2;
		break;
	}
	return true;
}

bool postfix_calculate(vector<string> v, double& result)
{
	stack<double> st;
	double n2;
	for (int i = 0; i < v.size(); i++)
	{
		if (order(v[i]) >= 1 && order(v[i]) <= 2 && !st.empty())
		{
			n2 = st.top();
			st.pop();
			double* temp = new double;
			bool is_not_error = calculate(st.top(), n2, v[i].c_str()[0], *temp);
			if (!is_not_error)
				return is_not_error;
			st.pop();
			st.push(*temp);
		}
		else
		{
			st.push(atof(v[i].c_str()));
		}
	}
	result = st.top();
	return true;
}

vector<string> infix_to_postfix(vector<string> v)
{
	stack<string> s;
	vector<string> answer;
	for (int i = 0; i < v.size(); i++)
	{
		if (order(v[i]) == 4) // '('이면
		{
			s.push(v[i]);
		}
		else if (order(v[i]) == 5) // ')'이면
		{
			while (!s.empty() && order(s.top()) != 4)
			{
				answer.push_back(s.top());
				s.pop();
			}
			s.pop();
		}
		else if (order(v[i]) == 6) // '{' 이면
		{
			s.push(v[i]);
		}
		else if (order(v[i]) == 7) // '}'이면
		{
			while (!s.empty() && order(s.top()) != 6)
			{
				answer.push_back(s.top());
				s.pop();
			}
			s.pop();
		}
		else if (order(v[i]) == 8) // '['이면
		{
			s.push(v[i]);
		}
		else if (order(v[i]) == 9) // ']'이면
		{
			while (!s.empty() && order(s.top()) != 8)
			{
				answer.push_back(s.top());
				s.pop();
			}
			s.pop();
		}
		else if (order(v[i]) == -1)
		{
			answer.push_back(v[i]);
		}
		else if (order(v[i]) >= 1 && order(v[i]) <= 2) // "+, -, *, /" 이면
		{
			if (!s.empty() && order(s.top()) != 4 && ((order(s.top()) < order(v[i])) || order(s.top()) == order(v[i])))
			{
				answer.push_back(s.top());
				s.pop();
			}
			s.push(v[i]);
		}
	}
	while (!s.empty())
	{
		answer.push_back(s.top());
		s.pop();
	}
	return answer;
}

int order(string oper)
{
	int o = 3;
	int i = 0;
	string symbols(SYMBOLS);
	i = symbols.find(oper.c_str()[0]);
	if (i == 0 || i == 1)o = 1;
	else if (i == 2 || i == 3)o = 2;
	else if (i >= 4)o = i;
	else o = -1;
	return o;
}
string replaceAll(string str, const string& pattern, const string& replace)
{
	string result = str;
	string::size_type pos = 0;
	string::size_type offset = 0;

	while ((pos = result.find(pattern, offset)) != string::npos)
	{
		result.replace(result.begin() + pos, result.begin() + pos + pattern.size(), replace);
		offset = pos + replace.size();
	}
	return result;
}

vector<string> string_to_tok(string strTarget)
{
	string token = "|";
	vector<string> answer;
	for (int i = 0; i < 10; i++)
	{
		strTarget = replaceAll(strTarget, string(1, SYMBOLS[i]), token + string(1, SYMBOLS[i]) + token);
	}
	stringstream ss(strTarget);
	string item;
	while (getline(ss, item, token.c_str()[0]))
	{
		if (item != "")
		{
			answer.push_back(item);
		}
	}
	return answer;
}


// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
