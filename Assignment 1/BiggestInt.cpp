/* Name: Kevin Kan
* Date: June 14 2015
* Purpose: Create a program that accepts no more than ten integers from the user and 
* arranges them to be th largest number possible.
*/
#include <iomanip>
#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;
int const MAX_VAL = 99;
int const MIN_VAL = 1;
int const MIN_NUM_VAL = 1;
int const MAX_NUM_VAL = 10;
int const VAL_POS = 0;
int const EXP_POS = 1;
int const TERMINATE_VAL = -1;
int const BASE = 10;

void sortVector(vector<vector<int>> &toSort)
{
	int length = (int)(toSort[VAL_POS].size());
	for (int i = 0; i < length-1; i++)
	{
		for (int j = i+1; j < length; j++)
		{
			static int pow1, pow2,comp1,comp2,tempVal,tempExp,count;//reuse memory each time the funciton is called

			count = 0;//how deep into the number from the left has it gone
			do{
				pow1 = (toSort[EXP_POS][i] - 1 - count>0) ? toSort[EXP_POS][i] - 1 - count : 0;// get the power base 10 to comapre, if the max position minus 1 (power 10 adjustment minus the position from the left is less than zero make the value 0 
				pow2 = (toSort[EXP_POS][j] - 1 - count>0) ? toSort[EXP_POS][j] - 1 - count : 0;
				comp1 = (int)(toSort[VAL_POS][i] / pow(BASE, pow1))%10;//gets the digit of type int in comparison
				comp2 = (int)(toSort[VAL_POS][j] / pow(BASE, pow2))%10;//gets the digit of type int in comparison
				//cout << "comp1: " << comp1 << " comp2: " << comp2 << endl; //debugging

				if (comp1 < comp2)
				{
					//if comp1 is less than comp2 swap both value and exponential size in the vector.
					tempVal = toSort[VAL_POS][i];
					tempExp = toSort[EXP_POS][i];
					toSort[VAL_POS][i] = toSort[VAL_POS][j];
					toSort[EXP_POS][i] = toSort[EXP_POS][j];
					toSort[VAL_POS][j] = tempVal;
					toSort[EXP_POS][j] = tempExp;
				}
				else if (comp1 == comp2)// if the comparison values are the same
				{
					count++;//increment the depth of the left position counter
				}
			} while (comp1 == comp2 && (pow1 != 0 && pow2 != 0));//do this until comp1 isn't the same as comp2 or if both coparison digits are at the ones location;
			
		}
		//debugging code
		/*for (int j = 0; j < length; j++)
		{
			cout << toSort[VAL_POS][j] << " ";
		}
		cout << endl;*/
	}
}
//Gets the number of digits there are in a number other words finds the exponential value base ten
//Paramter int test is the int that the function tries to get the number of digits
//Returns int power base ten of the number in question.
int getHighestExponent(int test)// modified from http://stackoverflow.com/questions/1489830/efficient-way-to-determine-number-of-digits-in-an-integer
{
	test = abs(test);//remove negatives
	return (test > 0) ? (int)log10((double)test) + 1 : 1;//turnerary operator. if test is 0 then digit is 1 else get the log base10 as an int (drop all decimals)
}

int main()
{
	char endChar = 'y';
	int input;
	vector<vector<int>> numSet(2,vector<int>());
	while (endChar != 'n' && numSet[VAL_POS].size()<MAX_NUM_VAL){//while the user wishes to continue and the vector contains less than the max
		cout << "Please enter in a number between "<<MIN_VAL<<" and "<<MAX_VAL<<" inclusive. or -1 to terminate"<<endl;
		cin >> input;
		if (input == TERMINATE_VAL)
		{
			if (numSet[VAL_POS].size() > MIN_NUM_VAL){
				endChar = 'n';
			}
			else
			{
				cout << "There must be at least two items in the list to compare." << endl;
			}
		}
		else if (input >= MIN_VAL && input <= MAX_VAL)// if the input is between Min value and max value add it to the vector
		{
			//cout << endl << input << endl;
			numSet[VAL_POS].push_back(input);
			numSet[EXP_POS].push_back(getHighestExponent(input));
			//cout << "val :" << numSet[VAL_POS].back();
			//cout << " digits :" << numSet[EXP_POS].back()<<endl;
			//cout << "\n val first digit :" <<(int) (numSet[VAL_POS].back()/pow(BASE, numSet[EXP_POS].back()-1))<<endl;
		}
		else// otherwise display error
		{
			cout <<input<< " was invalid. The number must be between " << MIN_VAL << " and " << MAX_VAL << " inclusive." << endl;
		}
	}
	sortVector(numSet);//sort the number list to the order
	cout << "The largest number possible is ";
	for (int l = 0; l < numSet[VAL_POS].size(); l++)
	{
		cout << numSet[VAL_POS][l];
	}
	cout << endl;
	system("pause");
	return 0;
	

}