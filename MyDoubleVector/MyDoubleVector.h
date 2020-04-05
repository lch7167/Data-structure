#pragma once

class MyDoubleVector {

public:
	MyDoubleVector(size_t init_cpacity=100);
	//postcondition : �⺻������
	MyDoubleVector(const MyDoubleVector& v);
	//postcondition : copy constructor for deep copy
	MyDoubleVector operator=(MyDoubleVector& v);
	//postcondition : assignment operator for deep copy
	void operator+=(MyDoubleVector& v);
	//postcondition : RHS ������Ʈ�� LHS ������Ʈ�� �߰�
	double& operator[](const int& n);
	//postcondition : �ش������ element ����, ������ ����� assert function�� �̿��Ͽ� ����
	MyDoubleVector operator+(const MyDoubleVector& v);
	//precondition : two operands�� size�� ���ƾ���
	//postcondition : �� ��ü���� ������ ���� ����
	MyDoubleVector operator-(const MyDoubleVector& v);
	//precondition : two operands�� size�� ���ƾ���
	//postcondition : �� ��ü���� ������ ���� ���� 
	double operator*(const MyDoubleVector& v);
	//precondition : two operands�� size�� ���ƾ���
	//postcondition : ������ ����
	void operator-();
	//postcondition : ��ȣ�� �ٲ㼭 ����
	bool operator==(MyDoubleVector& v);
	//precondition : two operands�� size�� ���ƾ��� capacity�� �ƴ϶�
	//postcondition : �� ���Ͱ� ������ ���������� ����
	void operator()();
	//postcondition : �Ǽ������� ����
	void pop_back();
	//postcondition : last element�� ����� vector size�� �ϳ� ����
	void push_back(double x);
	//postcondition : vector ���� new element�� �߰��ϰ� x�� �ʱ�ȭ
	size_t capacity() const;
	//postcondition : capacity�� ��ȯ;
	size_t size() const;
	//postcondition : size�� ��ȯ
	void reserve(size_t n);
	//precondition : n�� ���
	//postcondition : ���� ������ �뷮�� ��� n ���� ��Ҹ� �����ϱ⿡ ����ϵ��� ��û
	bool empty() const;
	//postcondition : ���� size�� 0���� �Ǵ�
	void clear();
	//postcondition : ���� ��� ��� ����
	~MyDoubleVector();
	//postcondition : �Ҹ���
	void print();
	// �׽�Ʈ�� �Լ�

private:
	double* data;
	size_t used, cap = 0, Default_capacity = 100;
};