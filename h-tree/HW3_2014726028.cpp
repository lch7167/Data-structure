//   2014726028_이찬호  //

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <string>


using namespace std;

void read(string input); // 입력받은 것을 힙으로 만들고 출력
void rotated(vector<char> heap, int rootindex); // rotated form 출력하기 위한 함수
void print1(vector<char> heap); 
void print2(vector<char> heap); // not-rotated form 출력하기 위한 함수
void print3(vector<char> heap); // h-tree form 출력하기 위한 함수//
int sequence(int n);
int X(int depth);
int Y(int depth);
int number(int depth, int totaldepth);
void hprint(int width, char d, char value, int x, int y, vector<vector<char>>& print);
void htree(vector<char> heap, int rIndex, char direction, int x, int y, vector<vector<char>>& print);

int main() 
{
	string input;
	getline(cin, input);
	read(input);

	return 0;
}

void read(string input)
{
	vector<char> heap;
	bool isInput = false;
	for (int i = 0; i < input.size(); i++)
	{
		char c = input[i];
		if (!isInput && c == 'S')
			isInput = true;
		else if (!isInput && c == 'L')
		{
			pop_heap(heap.begin(), heap.end());
			heap.pop_back();
		}
		
		else if (isInput && c != ' ')
		{
			heap.push_back(c);
			make_heap(heap.begin(), heap.end());
			isInput = false;
		}
		else if (c == ' ')
			continue;
	}
	print1(heap);
	print2(heap);
	print3(heap);
	
}
void rotated(vector<char> heap, int rootindex)
{
	if (rootindex < heap.size())
	{
		rotated(heap, (2 * rootindex + 2));
		cout << setw(((int)(log(rootindex + 1) / log(2.0)) + 1) * 3) << heap[rootindex] << endl;
		rotated(heap, (2 * rootindex + 1));
	}
}
void print1(vector<char> heap)
{
	cout << "1. rotated form" << endl;
	rotated(heap, 0);
	cout << endl << endl;
}

void print2(vector<char> heap)
{
	int index = 0;
	int depth = (int)((log(heap.size()) / log(2.0))) + 1;
	cout << "2. not-rotated form" << endl;
	for (int i = 0; i < depth; i++)
	{
		index = pow(2, i) - 1;
		for (int j = 0; j < pow(2, depth - 1 - i) - 1; j++)
			cout << (char)32;
		for (int k = 0; k < pow(2, i); k++)
		{
			cout << heap[index + k];
			for (int j = 0; j < pow(2, depth - i) - 1; j++)
				cout << char(32);
			if (index + k == heap.size() - 1)
			{
				cout << endl << endl << endl << endl;
				return;
			}
			if ((i != depth - 1))
			{
				int temp = index + k;
				if ((int)((temp - 1) / 2) != (int)(temp / 2))
					cout << (char)32;
				else
					cout << (char)8;
			}
		}
		cout << endl << endl;
	}
}
void print3(vector<char> heap)
{
	int depth = (int)((log(heap.size()) / log(2.0))) + 1;
	vector<vector<char>> print(X(depth), vector<char>(Y(depth), 0));
	int startX = X(depth) / 2;
	int startY = Y(depth) / 2;
	htree(heap, 0, 'c', startX, startY, print);
	cout << "3. H-tree form" << endl;
	for (int i = 0; i < Y(depth); i++)
	{
		for (int j = 0; j < X(depth); j++)
		{
			if (print[j][i] != NULL)
				cout << print[j][i];
			else
				cout << (char)32;
			cout << (char)32;
		}
		cout << endl;
	}
}

int sequence(int n)
{
	if (n < 1)
		return -1;
	return pow(2, n - 1) - 1;
}
int X(int depth)
{
	return sequence((int)((depth + 2) / 2) + 1);
}
int Y(int depth)
{
	return X(depth - 1);
}

int number(int depth, int totalDepth)
{
	if (depth == 1)
		return -1;
	depth = totalDepth - depth + 2;
	if (depth == 2) 
		return 0;
	return sequence((int)((depth - 2) / 2) + 1);
}

void hprint(int width, char d, char value, int x, int y, vector<vector<char>>& print) 
{
	print[x][y] = value;
	char c = ' ';
	for (int i = 0; i < width; i++) {
		if (d == 'l') 	print[x + i + 1][y] = c;
		else if (d == 'r') print[x - i - 1][y] = c;
		else if (d == 'd') print[x][y - i - 1] = c;
		else if (d == 'u') print[x][y + i + 1] = c;
	}
}

void htree(vector<char> heap, int rIndex, char direction, int x, int y, vector<vector<char>>& print)
{
	char dLeft, dRight;
	int newlx = x, newly = y, newrx = x, newry = y;
	int width = number((int)((log(rIndex+1) / log(2.0))) + 2, (int)((log(heap.size()) / log(2.0))) + 1);
	if (width < 0)
		return;
	switch (direction)
	{
	case 'l': dLeft = 'u'; dRight = 'd'; newly = y - (width + 1); newry = y + (width + 1);  break;
	case 'r': dLeft = 'd'; dRight = 'u'; newly = y + (width + 1); newry = y - (width + 1);  break;
	case 'u': dLeft = 'r'; dRight = 'l'; newlx = x + (width + 1); newrx = x - (width + 1);  break;
	case 'd': dLeft = 'l'; dRight = 'r'; newlx = x - (width + 1); newrx = x + (width + 1);  break;
	case 'c': dLeft = 'l'; dRight = 'r'; newlx = x - (width + 1); newrx = x + (width + 1);  break;
	}
	if (rIndex < heap.size())
	{
		hprint(number((int)((log(rIndex+1) / log(2.0))) + 1, (int)((log(heap.size()) / log(2.0))) + 1), direction, heap[rIndex], x, y, print);
		htree(heap, 2*rIndex+1, dLeft, newlx, newly, print);
		htree(heap, 2*rIndex+2, dRight, newrx, newry, print);
	}
}


// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
