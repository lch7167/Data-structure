
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
	v.push_back(1); //push_back(n) �׽�Ʈ
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.print();
	//capacity=5�� v���� ���
	MyDoubleVector v2(5);
	v2.push_back(1);
	v2.push_back(3);
	v2.push_back(5);
	v2.push_back(7);
	v2.push_back(9);
	v2.print();
	//capacity=5�� v2���� ���
	MyDoubleVector v3(3);
	v3.push_back(2);
	v3.push_back(4);
	v3.push_back(6);
	//capacity=3�� v3���� ���
	MyDoubleVector v4(v2);
	//v2�� ������ v4���� ����
	(v + v2).print(); // operator + �׽�Ʈ
	cout << v * v2 << endl; //operator * �׽�Ʈ
	(v - v2).print(); // operator - �׽�Ʈ
	cout << v[3] << endl; //operator [] �׽�Ʈ
	v[3] = 10;	//operator [] �׽�Ʈ
	cout << v[3] << endl; //operator [] �׽�Ʈ
	cout << "v==v2 " << ((v == v2) ? "true" : "false") << endl; // operator == �׽�Ʈ
	cout << "v2==v4 " << ((v2 == v4) ? "true" : "false") << endl; //operator == �׽�Ʈ
	v4.print(); // ������ v4 ����Ȯ��
	cout << v.capacity() << endl; // capacity() �׽�Ʈ
	v2.pop_back(); 
	v2.print(); // pop_back()�׽�Ʈ
	v3.reserve(10); 
	v3.print(); //reserve()�׽�Ʈ
	v.operator-();
	v.print(); // unary operator - �׽�Ʈ
	v += v3;
	v.print(); // operator += �׽�Ʈ
	v.operator()();
	v.print();
	cout << v.capacity() << endl; // capacity() �׽�Ʈ
	cout << v.size() << endl; // size() �׽�Ʈ
	cout << "v= empty?? :" << (v.empty() ? "empty" : "not empty") << endl; // empty() �׽�Ʈ
	v.clear(); // clear() �׽�Ʈ
	cout << "v= empty?? :" << (v.empty() ? "empty" : "not empty") << endl; // empty() �׽�Ʈ

}