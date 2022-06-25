#ifndef TRUEFALSE_H
#define TRUEFALSE_H
#include"Question.h"
class TrueFalse : public Question
{
	bool correctOption;
public:
	bool isCorrectAnswer(const String&);
	void setCorrectAnswer(char opt);
	String getCorrectAnswer();
	Question* clone() const;
	void printQuestion()override;
	void inputQuestion();
};
#endif // !TRUEFALSE_H
