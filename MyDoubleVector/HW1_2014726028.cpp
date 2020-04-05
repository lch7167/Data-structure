
#include"MyDoubleVector.h"
#include<iostream>
#include<cassert>
#include<cstdlib>

using namespace std;

void MyDoubleVector::print() {
	int i;
	for (i = 0; i < used; i++)
		cout << data[i] << " ";

	cout << endl << "capacity : " << cap << endl;
	cout << "used : " << used << endl;

}

int main() {
	MyDoubleVector v(5);
	v.push_back(1); //push_back(n) 테스트
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.print();
	//capacity=5인 v벡터 출력
	MyDoubleVector v2(5);
	v2.push_back(1);
	v2.push_back(3);
	v2.push_back(5);
	v2.push_back(7);
	v2.push_back(9);
	v2.print();
	//capacity=5인 v2벡터 출력
	MyDoubleVector v3(3);
	v3.push_back(2);
	v3.push_back(4);
	v3.push_back(6);
	//capacity=3인 v3벡터 출력
	MyDoubleVector v4(v2);
	//v2를 복사한 v4벡터 생성
	(v + v2).print(); // operator + 테스트
	cout << v * v2 << endl; //operator * 테스트
	(v - v2).print(); // operator - 테스트
	cout << v[3] << endl; //operator [] 테스트
	v[3] = 10;	//operator [] 테스트
	cout << v[3] << endl; //operator [] 테스트
	cout << "v==v2 " << ((v == v2) ? "true" : "false") << endl; // operator == 테스트
	cout << "v2==v4 " << ((v2 == v4) ? "true" : "false") << endl; //operator == 테스트
	v4.print(); // 복사한 v4 벡터확인
	cout << v.capacity() << endl; // capacity() 테스트
	v2.pop_back(); 
	v2.print(); // pop_back()테스트
	v3.reserve(10); 
	v3.print(); //reserve()테스트
	v.operator-();
	v.print(); // unary operator - 테스트
	v += v3;
	v.print(); // operator += 테스트
	v.operator()();
	v.print();
	cout << v.capacity() << endl; // capacity() 테스트
	cout << v.size() << endl; // size() 테스트
	cout << "v= empty?? :" << (v.empty() ? "empty" : "not empty") << endl; // empty() 테스트
	v.clear(); // clear() 테스트
	cout << "v= empty?? :" << (v.empty() ? "empty" : "not empty") << endl; // empty() 테스트

}