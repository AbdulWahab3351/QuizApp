#include"CUniqueRandom.h"
int CUniqueRandom:: getRandomNumber(int lower, int upper)
{
	if (isFirstTime)
	{
		isFirstTime = false;
		prevNum = CRandom::getRandomNumber(lower, upper);
		return prevNum;
	}
	int temp = CRandom::getRandomNumber(lower, upper);
	while(temp==prevNum)
		temp = CRandom::getRandomNumber(lower, upper);
	prevNum = temp;
	return temp;
}
Array CUniqueRandom::getRandomSequence(int lower, int upper, int seqSize)
{
	int range = upper - lower + 1;
	seqSize = !seqSize ? range : seqSize;
	Array temp{ seqSize };
	if (seqSize == range)
	{
		Array temp{ range };
		for (int i = lower, index = 0; i <= upper; i++,index++)
			temp[index] = i;
		shuffleArray(temp);
		return temp;
	}
	else if (seqSize < range)
	{
		Array temp{ range };
		for (int i = lower, index = 0; i <= upper; i++, index++)
			temp[index] = i;
		shuffleArray(temp);
		Array newArray{ seqSize };
		for (int i = 0; i < seqSize; i++)
			newArray[i] = temp[i];
		return newArray;
	}
	else
	{
		Array temp{ seqSize };
		int index = 0;
		for (int i = lower; i <= upper; i++)
		{
			temp[index] = i;
			index++;
		}
		while (index < seqSize)
		{
			temp[index] = CRandom::getRandomNumber(lower, upper);
			index++;
		}
		shuffleArray(temp);
		return temp;
	}
}