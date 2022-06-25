#include"Quiz.h"

int Quiz::getObtainedMarks()
{
	return obtainedMarks;
}
int Quiz::getMaximumMarks()
{
	return maximumMarks;
}
void Quiz:: setMaximumMarks(int m)
{
	maximumMarks = m;
}
void Quiz:: setAnswerForCurrentQuestion(const String& ans)
{
	userAnswer[currentQuestion] = ans;
	markQuestion();
}
bool Quiz:: isQuizFinished()
{
	return noOfQuestions == currentQuestion;
}
void Quiz:: printQuiz()
{
	for (int i = 0; i < noOfQuestions; i++)
	{
		cout << i + 1 << ": ";
		data[i]->printQuestion();
	}
}
void Quiz:: nextQuestion()
{
	currentQuestion++;
}
void Quiz:: showCurrentQuestion()
{
	cout << '\n' << currentQuestion + 1 << ": ";
	data[currentQuestion]->printQuestion();
}
void Quiz:: delayQuestion()
{
	Question* temp = data[currentQuestion];
	for (int i = currentQuestion; i < noOfQuestions - 1; i++)
		data[i] = data[i + 1];
	data[noOfQuestions - 1] = temp;
}
void Quiz:: markQuestion()
{
	if (data[currentQuestion]->isCorrectAnswer(userAnswer[currentQuestion]))
		obtainedMarks += data[currentQuestion]->getMarks(); 
}
void Quiz:: populateQuiz(Question** p, int qCount)
{
	data = p;
	noOfQuestions = qCount;
	userAnswer = new String[qCount];
}