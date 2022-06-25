#include"CRandom.h"
#include<cstdlib>
#include<ctime>

Array CRandom:: getRandomSequence(int lower, int upper, int seqSize)
{
	int size = !seqSize ? upper - lower + 1 : seqSize;
	Array temp{ size };
	for (int i = 0; i < size; i++)
		temp[i] = getRandomNumber(lower, upper);
	return temp;
}
void CRandom:: shuffleArray(Array& ref)
{
	int size = ref.getCapacity();
	for (int i = 0; i < size - 1; i++)
		swap(ref[i], ref[getRandomNumber(i, size - 1)]);
}
CRandom::CRandom()
{
	srand(time(0));
}
int CRandom:: getRandomNumber(int lower, int upper)
{
	return (rand() % (upper - lower + 1)) + lower;
	
}
void CRandom::swap(int& num1, int& num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}