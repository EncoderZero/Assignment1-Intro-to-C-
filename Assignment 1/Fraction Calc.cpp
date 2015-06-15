/* Name: Kevin Kan
 * Date: June 14 2015
 * Purpose: Create a program that accepts two fractions as strings and does, addition, subraction, multiplicaiton and division; 
 * then display the results in a formatted table
 */
#include <iomanip>
#include <iostream>
#include <cctype>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
int const STR_SIZE = 1000;
int const ADJ_DELIMETER = 1;
char const SEARCH_DELIM = '/';
int const TBL_WD = 10;
/* greatesetCommonFactor gets the greatest common factor
* Parameter: int num1, numerator of the fraction
* Parameter: int den1, denominator of the fraction
* Returns int comFac, the greatest common factor
*/
int greatesetCommonFactor(int fact1, int fact2)
{
	int comFac = 1;
	for (int i = 1; i <= fact1&&i <= fact2; i++)
	{
		if (fact1%i == 0 & fact2%i == 0)
		{
			comFac = i;
		}
	}
	return comFac;
}

/* reduceFrac gets the most reduce form of the fraction
* Parameter: int num1, numerator of the fraction
* Parameter: int den1, denominator of the fraction
* Returns: string full, the fraction in lowest terms.
*/
string reduceFrac(int num1, int den1)
{
	string full;
	if (num1%den1 == 0){
		full = to_string((num1 / den1));
	}
	else{
		int comDiv = greatesetCommonFactor(num1, den1);
		full = to_string(num1 / comDiv) + "/" + to_string(den1 / comDiv);
	}

	return full;
}

/*addFrac adds two fractions together and returns the results
*
*/
string addFrac(int num1,int den1,int num2, int den2)
{
	int sumNum, sumDen;
	sumNum = (num1*den2) + (num2*den1);
	sumDen = den2*den1;

	return reduceFrac(sumNum,sumDen);
}

/*subtractFrac subtracts two fractions
*
*/
string subtractFrac(int num1, int den1, int num2, int den2)
{
	int sumNum, sumDen;
	sumNum = (num1*den2) - (num2*den1);
	sumDen = den2*den1;

	return reduceFrac(sumNum, sumDen);
}

/*multiplyFrac multiplies two fractions
*/
string multiplyFrac(int num1, int den1, int num2, int den2)
{
	int prodNum, prodDen;
	prodNum = num1*num1;
	prodDen = den1*den2;
	return reduceFrac(prodNum,prodDen);
}

/* divFrac divides two fractions
*/
string divFrac(int num1, int den1, int num2, int den2)
{
	int quotientNumerator, quotientDenominator;
	quotientNumerator = num1*den2;
	quotientDenominator = den1*num2;
	return reduceFrac(quotientNumerator,quotientDenominator);
}

//main funciton to run
int main()
{
	char *save;
	char frac1[STR_SIZE], frac2[STR_SIZE];
	int num1, num2, den1, den2;
	cout << "First fractions: \n";
	cin.getline(frac1, STR_SIZE);
	cout << "Second fractions: \n";
	cin.getline(frac2, STR_SIZE);
    string frac3 = frac1;//convert to string to delemite the numberator from denominator as strtok fails on VS 2013
	string frac4 = frac2;
	num1 = stoi(frac3.substr(0, frac3.find(SEARCH_DELIM)));
	den1 = stoi(frac3.substr(frac3.find(SEARCH_DELIM) + 1));
	num2 = stoi( frac4.substr(0, frac4.find(SEARCH_DELIM)));
	den2 = stoi(frac4.substr(frac4.find(SEARCH_DELIM) + 1));
	cout << setw(TBL_WD) << "Addition" << setw(TBL_WD) << "Subtract" << setw(TBL_WD) << "Multiply" << setw(TBL_WD) << "Divide" << endl;
	cout << setw(TBL_WD) << addFrac(num1, den1, num2, den2);
	cout << setw(TBL_WD) << subtractFrac(num1, den1, num2, den2);
	cout << setw(TBL_WD) << multiplyFrac(num1, den1, num2, den2);
	cout << setw(TBL_WD) << divFrac(num1, den1, num2, den2) << endl;
	system("pause");
	return 0;
}