#include"QuestionPool.h"
#include"CUniqueRandom.h"
QuestionPool::QuestionPool(int cap)
{
	capacity = cap <= 0 ? 20 : cap;
	data = new Question * [capacity];
	noOfQuestions = 0;
}
void QuestionPool:: addQuestion(const Question& q)
{
	data[noOfQuestions] = q.clone();
	noOfQuestions++;
}
void QuestionPool:: generateQuiz(Quiz& quiz, int questCount)
{
	if (questCount <= 0)
		return;
	if (noOfQuestions == 0)
	{
		cout << "There are no questions in pool\n";
		return;
	}
	if (questCount > noOfQuestions)
		cout << "Total no of questions in the pool is : " << noOfQuestions << '\n';
	int marks = 0;
	CUniqueRandom temp;
	Array tempArr = temp.getRandomSequence(0, noOfQuestions - 1, questCount);
	Question** ptr;
	ptr = new Question * [questCount];
	for (int i = 0; i < questCount; i++)
	{
		ptr[i] = data[tempArr[i]];
		marks += ptr[i]->getMarks();
	}
	quiz.populateQuiz(ptr, questCount);
	quiz.setMaximumMarks(marks);
}