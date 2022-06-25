#ifndef QUIZAPP_H
#define QUIZAPP_H
#include"QuestionPool.h"
#include"MCQ.h"
#include"BlanksFill.h"
#include"TrueFalse.h"

class QuizApp
{
	static void storeQuestion(QuestionPool&);
	static void print(QuestionPool&);
	static void attemptQuiz(QuestionPool&, int count);
public:
	static void startApp();
};
#endif // !QUIZAPP_H
