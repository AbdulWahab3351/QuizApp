#ifndef BLANKSFILL_H
#define BLANKSFILL_H
#include"Question.h"
class BlanksFill : public Question
{
	String correctOption;
public:
	bool isCorrectAnswer(const String& ans);
	void setCorrectAnswer(const String& ans);
	String getCorrectAnswer();
	Question* clone() const;
	void printQuestion()override;
	void inputQuestion();
};
#endif // !BLANKSFILL_H
