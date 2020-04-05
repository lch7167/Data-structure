#pragma once

class MyDoubleVector {

public:
	MyDoubleVector(size_t init_cpacity=100);
	//postcondition : 기본생성자
	MyDoubleVector(const MyDoubleVector& v);
	//postcondition : copy constructor for deep copy
	MyDoubleVector operator=(MyDoubleVector& v);
	//postcondition : assignment operator for deep copy
	void operator+=(MyDoubleVector& v);
	//postcondition : RHS 오브젝트를 LHS 오브젝트에 추가
	double& operator[](const int& n);
	//postcondition : 해당범위의 element 리턴, 범위를 벗어나면 assert function을 이용하여 종료
	MyDoubleVector operator+(const MyDoubleVector& v);
	//precondition : two operands의 size가 같아야함
	//postcondition : 두 객체들의 벡터의 합을 리턴
	MyDoubleVector operator-(const MyDoubleVector& v);
	//precondition : two operands의 size가 같아야함
	//postcondition : 두 객체들의 벡터의 차를 리턴 
	double operator*(const MyDoubleVector& v);
	//precondition : two operands의 size가 같아야함
	//postcondition : 내적을 구함
	void operator-();
	//postcondition : 부호를 바꿔서 리턴
	bool operator==(MyDoubleVector& v);
	//precondition : two operands의 size가 같아야함 capacity가 아니라
	//postcondition : 두 벡터가 같은지 같지않은지 리턴
	void operator()();
	//postcondition : 실수형으로 변경
	void pop_back();
	//postcondition : last element를 지우고 vector size도 하나 줄임
	void push_back(double x);
	//postcondition : vector 끝에 new element를 추가하고 x로 초기화
	size_t capacity() const;
	//postcondition : capacity값 반환;
	size_t size() const;
	//postcondition : size값 반환
	void reserve(size_t n);
	//precondition : n은 양수
	//postcondition : 저장 공간의 용량이 적어도 n 개의 요소를 보유하기에 충분하도록 요청
	bool empty() const;
	//postcondition : 벡터 size가 0인지 판단
	void clear();
	//postcondition : 벡터 모든 요소 삭제
	~MyDoubleVector();
	//postcondition : 소멸자
	void print();
	// 테스트용 함수

private:
	double* data;
	size_t used, cap = 0, Default_capacity = 10000;
};
