#include"BlanksFill.h"

bool BlanksFill:: isCorrectAnswer(const String& ans)
{
	return (ans == correctOption) == 0;
}
void BlanksFill:: setCorrectAnswer(const String& ans)
{
	correctOption = ans;
}
String BlanksFill::getCorrectAnswer()
{
	return correctOption;
}
Question* BlanksFill:: clone() const
{
	return new BlanksFill{ *this };
}
void BlanksFill:: printQuestion()
{
	Question::printQuestion();
	cout << '\n';
}
void BlanksFill:: inputQuestion()
{
	Question::inputQuestion();
	cout << "Enter Answer : ";
	cin >> correctOption;
	cout << "Enter question marks : ";
	int m;
	cin >> m;
	setMarks(m);
	cin.ignore();
}