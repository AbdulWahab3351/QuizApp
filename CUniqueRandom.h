#ifndef CUNIQUE_RANDOM_H
#define CUNIQUE_RANDOM_H
#include"CRandom.h"
class CUniqueRandom:public CRandom
{
	bool isFirstTime = true;
	int prevNum;
public:
	int getRandomNumber(int lower, int upper)override;
	Array getRandomSequence(int lower, int upper, int seqSize = 0)override;
};
#endif // !CUNIQUE_RANDOM_H
