#ifndef ARRAY_H
#define ARRAY_H
#include<iostream>
using namespace std;
class Array
{
private:
	int* data;
	int capacity;

	void myMemCpy(void* dest, const void* src, int bytes);
	bool isValidIndex(int index)const;
public:
	Array(const Array&);
	Array(Array&&);
	Array(int cap = 0, ...);
	~Array();
	int& operator[](int index)const;
	int getCapacity()const;
	void reSize(int newCapacity);
	void display()const;
	Array& operator=(const Array&);
	Array& operator=(Array&&);

};
ostream& operator<<(ostream& temp, const Array& ref);
#endif

