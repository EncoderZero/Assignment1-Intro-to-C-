/* Name: Kevin Kan
* Date: June 15 2015
* Purpose: Create a program that accepts a grades.txt file, parses it and calculates the student's
* grades for their tests. It will calculate an average for the test scores for each student,
* calculate grade for the sudent, calculate average of all tests and all students and will print the results
* on screen.
*/
#include <iomanip>
#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

/* calculateAverage calculates the average test scores for each student
*
*/
float calculateAverage(float total, int numStudents)
{
	return total / numStudents;
}

/*claculateGrade calculates the letter grade value given a grade percentage
* Parameter: float percent percent is the numerical percent between 0 and 100 inclusive
* Returns: char grade it returns the letter grade value given a percentage
*/
char claculateGrade(float percent)
{
	const float A_GRADE = 90.0;
	const float B_GRADE = 80.0;
	const float C_GRADE = 70.0;
	const float D_GRADE = 60.0;
	const float F_GRADE = 50.0;
	char grade;
	if (percent >= A_GRADE)
	{
		grade = 'A';
	}
	else if (percent >= B_GRADE)
	{
		grade = 'B';
	}
	else if (percent >= C_GRADE)
	{
		grade = 'C';
	}
	else if (percent >= D_GRADE)
	{
		grade = 'D';
	}
	else
	{
		grade = 'E';
	}
	return grade;
}

/* TestAvg calcualtes the average of all tests and overall average of students
* Parameter vector<string> studentNames: a list of student names
* Parameter vector<vector<grades>> studentNames: a list of grades, the first index is the student position and the second is the test number
*/
void TestAvg(vector<string>&studentNames, vector<vector<float>>&grades)
{
	int const FIRST_STUDENT = 0;
	int numTests = grades[FIRST_STUDENT].size(), numStudents = studentNames.size();
	string const TEST_AVG_TITLE = "Test Avg:";
	studentNames.push_back(TEST_AVG_TITLE);
	float studentTotal;
	vector<float>testTotal(numTests + 1, 0);

	for (int student = 0; student < numStudents; student++)
	{
		studentTotal = 0;
		for (int test = 0; test < numTests; test++)
		{
			studentTotal += grades[student][test];//get the total grade for a student
			testTotal[test] += grades[student][test];//add the test score to it's test location
			//cout << testTotal[0] << " : " << testTotal[0] / numTests << endl;
		}
		testTotal[numTests] += studentTotal / numTests;//get the average averages
		grades[student].push_back(calculateAverage(studentTotal, numTests));//add the total/number of tests (average) to the end of the student grades
	}

	for (int i = 0; i<(int)testTotal.size(); i++)//calculate the average for each test
	{
		testTotal[i] = testTotal[i] / numStudents;
		//cout << testTotal[i] << " : " << testTotal[i] / numStudents << endl;
	}

	grades.push_back(testTotal);
	//debugging
	//for (int student = 0; student <(int)studentNames.size(); student++)
	//{
	//	cout << studentNames[student]<<": ";
	//	for (int test = 0; test <(int)grades[student].size(); test++)
	//	{
	//		cout << grades[student][test]<<" : ";
	//	}
	//	cout << endl;
	//}

}
/*Prints the grades and results onsreen
*Parameter vector<string> studentNames: a list of student names
*Parameter vector<vector<grades>> studentNames: a list of grades, the first index is the student position and the second is the test number
*/
void printGrades(vector<string>&studentNames, vector<vector<float>>&grades)
{
	int const FIRST_STUDENT = 0;
	int const TITLE_SPACE = 9;
	cout << setw(TITLE_SPACE) << "Name";
	for (int test = 0; test <(int)grades[FIRST_STUDENT].size() - 1; test++)
	{
		string msg = "test " + to_string(test + 1);
		cout << setw(TITLE_SPACE) << msg;
	}
	cout << setw(TITLE_SPACE) << "AVG" << setw(TITLE_SPACE) << "Grade" << endl;
	for (int student = 0; student <(int)studentNames.size(); student++)
	{
		cout << setw(TITLE_SPACE) << studentNames[student];
		for (int test = 0; test <(int)grades[student].size(); test++)
		{
			cout << setw(TITLE_SPACE) << grades[student][test];
		}
		cout << setw(TITLE_SPACE) << claculateGrade(grades[student].back()) << endl;
	}
}

int runGradeSchema()
{
	ifstream inData;
	inData.open("grades.txt");
	int numStudent, numTest;
	int const STUDENT_POS = 0;
	int const TEST_START_POS = 1;
	string studentName;
	float grade;
	inData >> numStudent;
	inData >> numTest;

	vector<vector<float>> studentGrades(numStudent, vector<float>());
	vector<string>studentNames;
	for (int student = 0; student < numStudent; student++)
	{
		inData >> studentName;
		studentNames.push_back(studentName);
		for (int test = 0; test < numTest; test++)
		{
			inData >> grade;
			studentGrades[student].push_back(grade);
		}
	}

	TestAvg(studentNames, studentGrades);
	printGrades(studentNames, studentGrades);
	cin.ignore();
	cin.get();
	cout << "Press any key to terminate the program ..." << endl;
	return 0;
}