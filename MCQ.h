#ifndef MCQ_H
#define MCQ_H
#include"Question.h"
class MCQ : public Question
{
	String options[4];
	int correctOption;
public:
	void setOption(const String& opt, int optNumber);
	void setCorrectAnswer(char opt);
	String getCorrectAnswer();
	bool isCorrectAnswer(const String& ans);
	Question* clone() const;
	void printQuestion()override;
	void inputQuestion();
};
#endif // !MCQ_H
