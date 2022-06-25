#include"QuizApp.h"
void QuizApp:: startApp()
{
	enum Status { EXIT, STORE_QUESTION, PRINT_QUIZ, ATTEMPT_QUIZ };
	QuestionPool pool;
	int choice;
	do
	{
		cout << "************* Quiz App *************\n";
		cout << "Enter 1 to store question in Question Data Bank\n";
		cout << "\t2 to Print a Quiz\n";
		cout << "\t3 to attempt a Quiz\n";
		cout << "\t0 to exit......................: ";
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case EXIT:
			cout << "<<<<<<< Exiting the Application >>>>>>>\n";
			break;
		case STORE_QUESTION:
			cout << "************* Quiz App *************\n";
			cout << "********* Questions Data Bank *********\n";
			storeQuestion(pool);
			break;
		case PRINT_QUIZ:
			print(pool);
			break;
		case ATTEMPT_QUIZ:
			cout << "Enter the count of questions you need in Quiz: ";
			int count;
			cin >> count;
			cin.ignore();
			attemptQuiz(pool, count);
			break;
		default:
			cout << "Invalid choice\n";
		}
	} while (choice!=EXIT);
}
void QuizApp:: storeQuestion(QuestionPool& pool)
{
	cout << "Enter 1 to add MCQ\n"
		<< "\t2 to add True / False\n"
		<< "\t3 to add Fill in the Blanks\n"
		<< "\t4 to return to Main - Menu / Quiz - App........: ";
	int choice;
	cin >> choice;
	cin.ignore();
	enum Status { MCQs = 1, TRUE_FALSE, FILL_IN, RETURN };
	
	if (choice == MCQs)
	{
		cout << "************* Quiz App *************\n"
			<< "********* Questions Data Bank *********\n"
			<< "*********** MCQ Storage ***********\n";
		MCQ mcq;
		char resume;
		do
		{
			mcq.inputQuestion();
			pool.addQuestion(mcq);
			cout << "Press enter to add more MCQs Or any other key to return to Main Menu: ";
			cin.get(resume);
		} while (resume == '\n');		
	}
	else if (choice == TRUE_FALSE)
	{
		cout << "************* Quiz App *************\n"
			<< "********* Questions Data Bank *********\n"
			<< "*********** True/False Storage ***********\n";
		TrueFalse tf;
		char resume;
		do
		{
			tf.inputQuestion();
			pool.addQuestion(tf);
			cout << "Press enter to add more True/False Or any other key to return to Main Menu: ";
			cin.get(resume);
		} while (resume == '\n');
		
	}
	else if (choice == FILL_IN)
	{
		cout << "************* Quiz App *************\n"
			<< "********* Questions Data Bank *********\n"
			<< "*********** Fill in the Blanks Storage ***********\n";
		BlanksFill fillInBlank;
		char resume;
		do
		{
			fillInBlank.inputQuestion();
			pool.addQuestion(fillInBlank);
			cout << "Press enter to add more Fill in the Blanks Question Or any other key to return to Main Menu : ";
			cin.get(resume);
		} while (resume == '\n');
	}
	else if (choice == RETURN)
		cout << "<<<<<<< Exiting the Application >>>>>>>\n";
	else
		cout << "Invalid Choice\n";	
}
void QuizApp:: print(QuestionPool& pool)
{
	cout << "Enter the count of questions you need in Quiz : ";
	int count;
	cin >> count;
	while (count <= 0)
	{
		cout << "Error : Please enter the no. of questions greater than zero : ";
		cin >> count;
	}
	cin.ignore();
	Quiz quiz;
	pool.generateQuiz(quiz, count);
	quiz.printQuiz();
}
void QuizApp:: attemptQuiz(QuestionPool& pool, int count)
{
	cout << "********* Quiz in Progress *********\n";
	Quiz quiz;
	pool.generateQuiz(quiz, count);
	String answer;
	while (!quiz.isQuizFinished())
	{
		quiz.showCurrentQuestion();
		cout << "Enter your Choice Or Simply Enter to Delay it : ";
		char ch;
		cin.get(ch);
		if (ch == '\n')
			quiz.delayQuestion();
		else
		{
			cin >> answer;
			answer.insert(0, ch);
			quiz.setAnswerForCurrentQuestion(answer);
			quiz.nextQuestion();
		}
	}
	cout << "Quiz Finished: Your Marks Are: " << quiz.getObtainedMarks() << '/' << quiz.getMaximumMarks() << '\n';
}
