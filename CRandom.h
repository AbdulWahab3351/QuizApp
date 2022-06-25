#ifndef CRANDOM_H
#define CRANDOM_H
#include"Array.h"

class CRandom
{
	void swap(int&, int&);
public:
	CRandom();
	virtual Array getRandomSequence(int lower, int upper, int seqSize = 0);
	virtual void shuffleArray(Array&);
	virtual int getRandomNumber(int lower, int upper);
};
#endif // !CRANDOM_H
