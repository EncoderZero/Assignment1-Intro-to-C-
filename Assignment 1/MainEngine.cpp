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
	int const FRAC_CALC = 1, GRADE_SCHEMA = 2, BIGEST_INT = 3;
	int selection =0;
	do{
		cout << "Please choose, what program to run. Choose " << FRAC_CALC << " for the fraction calculator, " << GRADE_SCHEMA << " for the grade schema " << BIGEST_INT;
		cout << " for the biggest integer program." << endl;
		cin >> selection;
	} while (selection!=FRAC_CALC && selection!=GRADE_SCHEMA && selection!=BIGEST_INT);
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
		break;
	}
	cin.ignore();
	cout << "Press any key to end program..." << endl;
	cin.get();
	return 0;
}