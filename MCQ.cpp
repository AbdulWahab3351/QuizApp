#include"MCQ.h"

void MCQ:: inputQuestion()
{
	Question::inputQuestion();
	cout << "Enter option A : ";
	cin >> options[0];
	cout << "Enter option B : ";
	cin >> options[1];
	cout << "Enter option C : ";
	cin >> options[2];
	cout << "Enter option D : ";
	cin >> options[3];
	cout << "Which option is correct: A:B:C:D?";
	char opt;
	cin >> opt;
	while (opt < 'A' || correctOption > 'D')
	{
		cout << "Error: Select option (A,B,C,D) : ";
		cin >> opt;
	}
	setCorrectAnswer(opt);
	cout << "Enter question marks: ";
	int m;
	cin >> m;
	setMarks(m);
	cin.ignore();
}
void MCQ:: printQuestion()
{
	Question::printQuestion();
	cout << '\t' << "A. " << options[0] << '\n';
	cout << '\t' << "B. " << options[1] << '\n';
	cout << '\t' << "C. " << options[2] << '\n';
	cout << '\t' << "D. " << options[3] << "\n\n";

}
void MCQ:: setOption(const String& opt, int optNumber)
{
	if (optNumber >= 0 && optNumber <= 3)
		options[optNumber] = opt;
}
void MCQ:: setCorrectAnswer(char opt)
{
	if (opt >= 'A' && opt <= 'D')
		correctOption = opt - 'A';
}
String MCQ:: getCorrectAnswer()
{
	return options[correctOption];
}
bool MCQ:: isCorrectAnswer(const String& ans)
{
	return (ans[0] - 'A') == correctOption;
}
Question* MCQ:: clone() const
{
	return new MCQ{ *this };
}