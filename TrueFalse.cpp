#include"TrueFalse.h"

void TrueFalse:: inputQuestion()
{
	Question::inputQuestion();
	cout << "A. True\n";
	cout << "B. False\n";
	cout << "Which option is correct: A:B? ";
	char opt;
	cin >> opt;
	while (opt != 'A' && opt != 'B')
	{
		cout << "Error: Enter A or B : ";
		cin >> opt;

	}
	correctOption = opt - 'A';
	cout << "Enter qustion marks : ";
	int m;
	cin >> m;
	setMarks(m);
	cin.ignore();
}
void TrueFalse:: printQuestion()
{
	Question::printQuestion();
	cout << "\tA. True\n";
	cout << "\tB. False\n\n";
}
void TrueFalse::setCorrectAnswer(char opt)
{
	if (opt == 'A' || opt == 'B')
		correctOption = opt - 'A';
}
String TrueFalse:: getCorrectAnswer()
{
	return correctOption ? "True" : "False";
}
bool TrueFalse:: isCorrectAnswer(const String& ans)
{
	return (ans[0] - 'A') == correctOption;
}
Question* TrueFalse:: clone() const
{
	return new TrueFalse{ *this };
}