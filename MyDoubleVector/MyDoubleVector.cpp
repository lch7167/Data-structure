// homework1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cassert>
#include "MyDoubleVector.h"
#include <cstdlib>
using namespace std;

MyDoubleVector::MyDoubleVector(size_t init_capacity) {
	data = new double[init_capacity];
	cap = init_capacity;
	used = 0;
}

MyDoubleVector::MyDoubleVector(const MyDoubleVector& v) {
	data = new double[v.cap];
	cap = v.cap;
	used = v.used;
	copy(v.data, v.data + used, data);
}

MyDoubleVector MyDoubleVector::operator=(MyDoubleVector& v) {
	if (this == &v)
		return *this;
	if (cap != v.cap)
	{
		delete[] data;
		data = new double[v.cap];
		cap = v.cap;
	}
	used = v.used;
	copy(v.data, v.data + used, data);
	return *this;
}

void MyDoubleVector::operator+=(MyDoubleVector& v) {
	if (used + v.used > cap)
		reserve(used + v.used);
	copy(v.data, v.data + v.used, data + used);
	used += v.used;
}

double& MyDoubleVector::operator[](const int& n) {
	assert(n > 0);
	assert(n <= used);
	return data[n - 1];
}
MyDoubleVector MyDoubleVector::operator+(const MyDoubleVector& v) {
	int i;
	MyDoubleVector vplus(v);
	assert(used == v.used);
		for (i = 0; i <= used; i++)
		{
			vplus.data[i] = data[i] + v.data[i];
		}
		for (i = 0; i <= used; i++)
			if (vplus.data[i] != NULL)
				vplus.used = i;
	return vplus;
	
}

MyDoubleVector MyDoubleVector::operator-(const MyDoubleVector& v) {
	int i;
	MyDoubleVector vminus(v);
	assert(used == v.used);
		for (i = 0; i <= used; i++)
		{
			vminus.data[i] = data[i] - v.data[i];
		}
		for (i = 0; i <= used; i++)
			if (vminus.data[i] != NULL)
				vminus.used = i;
	return vminus;
	
}

double MyDoubleVector::operator*(const MyDoubleVector& v) {
	int i;
	double result=0;
	MyDoubleVector vdot(v);
	assert(used == v.used);
		for (i = 0; i < used; i++) {
			result += data[i] * v.data[i];
		}
	return result;
}

void MyDoubleVector::operator-() {
	int i;
	for (i = 0; i < used; i++) {
		data[i] = data[i] * -1;
	}
}

bool MyDoubleVector::operator==(MyDoubleVector& v) {
	int i;
	assert(used == v.used);
	for (i = 0; i < used; i++)
	{
		if (data[i] != v.data[i])
		{
			return false;
			break;
		}
	}
	return true;
}

void MyDoubleVector::operator()() {
	(double)used;
	(double)cap;
	(double)Default_capacity;
}

void MyDoubleVector::pop_back() {
	data[used] = NULL;
	--used;
	--cap;
}

void MyDoubleVector::push_back(double x) {
	data[used] = x;
	used++;
}

size_t MyDoubleVector::capacity() const {
	return cap;
}

size_t MyDoubleVector::size() const {
	return used;
}

bool MyDoubleVector::empty() const {
	if (used == 0)
		return true;
	else
		return false;
}

void MyDoubleVector::clear()
{
	MyDoubleVector::~MyDoubleVector();
	cap = NULL;
	used = NULL;
}

void MyDoubleVector::reserve(size_t n) {
	double* larger_array;
	if (n == cap)
		return;
	if (n < used)
		n = used;

	larger_array =new double[n];
	copy(data, data + used, larger_array);
	delete[] data;
	data = larger_array;
	cap = n;
}
MyDoubleVector::~MyDoubleVector() {
	delete[] data;
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
