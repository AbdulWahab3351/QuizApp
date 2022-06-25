#include"Question.h"

void Question::setQuestion(const String& q, int num)
{
	question = q;
	marks = num;
}
String Question:: getQuestion()
{
	return question;
}
int Question:: getMarks()
{
	return marks;
}
void Question:: setMarks(int m)
{
	marks = m;
}
void Question:: printQuestion()
{
	cout << question << "   :  (" << marks << ")\n";
}
void Question:: inputQuestion()
{
	cout << "Enter Question Text : ";
	cin >> question;
}