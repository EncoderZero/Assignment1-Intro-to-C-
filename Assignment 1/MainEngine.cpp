/* Name: Kevin Kan
* Date: June 19 2015
* Purpose: Allows user to select which program to run and runs them
*/
#include<iostream>
#include<iomanip>
#include<BiggestInt.h>
#include<FractionCalc.h>
#include<GradeSchema.h>
using namespace std;
int main()
{
	int const FRAC_CALC = 1, GRADE_SCHEMA = 2, BIGEST_INT = 3,FAIL=0;
	int selection = FAIL;
	do{
		cout << "Please choose, what program to run. Choose " << FRAC_CALC << " for the fraction calculator, " << GRADE_SCHEMA << " for the grade schema " << BIGEST_INT;
		cout << " for the biggest integer program." << endl;
		cin >> selection;
		if (selection != FRAC_CALC && selection != GRADE_SCHEMA && selection != BIGEST_INT)
		{
			cout << "You did not enter in a proper value. Please try again. \n";
			cin.clear();
			cin.ignore();
			selection = FAIL;
		}
	} while (selection == FAIL);
	switch (selection)
	{
	case(FRAC_CALC) :
		runFractionCalc();
		break;
	case(GRADE_SCHEMA) :
		runGradeSchema();
		break;
	case(BIGEST_INT) :
		runBiggestInt();
		break;
	default:
		cout << "Somehow you broke the code and selected no program to run. \n";
		break;
	}
	cin.ignore();
	cout << "Press any key to end program..." << endl;
	cin.get();
	return 0;
}