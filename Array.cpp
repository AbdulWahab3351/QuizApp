#include<iostream>
#include<stdarg.h>
#include"Array.h"
using namespace std;

bool Array::isValidIndex(int index)const
{
	if (index >= 0 && index < capacity)
		return true;
	return false;
}

Array::Array(int cap, ...)
{
	data = nullptr;
	capacity = 0;
	if (cap <= 0)
		return;
	capacity = cap;
	data = new int[capacity];
	va_list list;
	va_start(list, cap);
	for (int i = 0; i < cap; i++)
		data[i] = va_arg(list, int);
	va_end(list);
}

Array :: ~Array()
{
	if (data)
		delete[]data;
	data = nullptr;
	capacity = 0;
}
int& Array::operator[](int index)const
{
	if (isValidIndex(index))
		return data[index];
	exit(0);
}

int Array::getCapacity()const
{
	return capacity;
}

void Array::reSize(int newCapacity)
{
	if (newCapacity <= 0)
	{
		this->~Array();
		return;
	}

	int* temp = new int[newCapacity];
	int small = (newCapacity < capacity ? newCapacity : capacity);
	for (int i = 0; i < small; i++)
		temp[i] = data[i];
	this->~Array();
	capacity = newCapacity;
	data = temp;
	temp = nullptr;
}

void Array::display()const
{
	for (int i = 0; i < getCapacity(); i++)
		cout << (*this)[i] << ' ';
	cout << endl;
}
Array::Array(const Array& ref)
{
	if (ref.capacity <= 0)
		return;
	capacity = ref.capacity;
	data = new int[capacity];
	myMemCpy(data, ref.data, capacity * sizeof(int));
}
void Array::myMemCpy(void* dest, const void* src, int bytes)
{
	char* d = (char*)dest;
	char* s = (char*)src;
	for (int i = 0; i < bytes; i++)
	{
		*d = *s;
		d++;
		s++;
	}
}
Array& Array:: operator=(const Array& ref)
{
	if (this == &ref)
		return *this;
	this->~Array();
	capacity = ref.capacity;
	data = new int[capacity];
	myMemCpy(data, ref.data, capacity * sizeof(int));
	return *this;
}
Array& Array:: operator=(Array&& ref)
{
	this->~Array();
	data = ref.data;
	capacity = ref.capacity;
	ref.data = nullptr;
	return *this;
}
Array::Array(Array&& ref)
{
	data = ref.data;
	capacity = ref.capacity;
	ref.data = nullptr;
}
ostream& operator<<(ostream& temp, const Array& ref)
{
	for (int i = 1; i < ref.getCapacity(); i++)
		temp << ref[i] << ' ';
	temp << '\n';
	return temp;
}