/*********************************************************************
** Program name: LangstonsAnt
** Author: Ryan Ellis
** Date: 1/22/17
** Description: Function implementation file for the menu function.
** Displays a menu and prompts user to select an option.
********************************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "Ant.hpp"
#include "Board.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

void menuOptions(); //helper function that displays menu options
// char getMenuInput(char); //helper function that gets user menu choice
int inputValid();

void menu()
{
	const int MAX_CHOICE = 3;
	string strInput;
	int boardRows, boardColumns, startRow, startColumn, numSteps, menuChoice;

	do
	{
	menuOptions();

	// testing out using same input validation for menu options
	menuChoice = inputValid();

	while(menuChoice > MAX_CHOICE)
	{
		cout << "Sorry, invalid option. Please enter" << endl;
		cout << "a number between 1 and " << MAX_CHOICE << endl;
		menuChoice = inputValid();
	}

	switch(menuChoice)
	{
		case 1:
		{
			// get input from user
			cout << "# of Rows for Board:" << endl;
			boardRows = inputValid();

			cout << "# of Columns for Board:" << endl;
			boardColumns = inputValid();

			cout << "Ant's Start Row:" << endl;
			startRow = inputValid();
			// checks to ensure row for start point is on board
			while(startRow >= boardRows)
			{
				cout << "Sorry! Invalid input. Ant's starting" << endl;
				cout << "point must be less than " << boardRows << endl;
				startRow = inputValid();
			}

			cout << "Ant's Start Column:" << endl;
		 	startColumn = inputValid();
		 	// checks to ensrue column for start on board
		 	while(startColumn >= boardColumns)
			{
				cout << "Sorry! Invalid input. Ant's starting" << endl;
				cout << "point must be less than " << boardColumns << endl;
				startColumn = inputValid();
			}

			cout << "# of Steps:" << endl;
			numSteps = inputValid();

			// pass to board objects
			Board board(boardRows, boardColumns);
			board.createBoard();
			Ant ant(&board, numSteps, startRow, startColumn);
			ant.move();
			break;
		}
		// method for generating method numbers in between a range
		// came from article on cplusplus.com (link below)
		// http://www.cplusplus.com/reference/cstdlib/rand/
		case 2:
		{
			// get input from user
			cout << "# of Rows for Board:" << endl;
			boardRows = inputValid();

			cout << "# of Columns for Board:" << endl;
			boardColumns = inputValid();

			cout << "# of Steps:" << endl;
			numSteps = inputValid();

			// generates random start point base off # rows/columns
			startRow = rand() % (boardRows - 1);
			startColumn = rand() % (boardColumns - 1);

			Board board(boardRows, boardColumns);
			board.createBoard();
			Ant ant(&board, numSteps, startRow, startColumn);
			ant.move();

			break;
		}
		case 3:
			break;
	}	
	
	} while(menuChoice != MAX_CHOICE);
}

// displays desired menu options
void menuOptions()
{
	cout << "Welcome to the Langston's Ant simulator!" << endl;
	cout << "Please set the parameters for the" << endl;
	cout << "simulator using the below menu." << endl;
	cout << endl;
	cout << "1) Custom Parameters" << endl;
	cout << "2) Random Mode" << endl;
	cout << "3) Quit" << endl;
}

/* 
// Old input validation function for the menu option.
// Swapped out for this function for the
// parameter input validation.
// validates input for menu selection
char getMenuInput(char max)
{
	char input;
	cin >> input;
	cin.ignore(1000, '\n');
	
	while(input < '1'|| input > max)
	{
		cout << "Sorry, invalid option. Please enter" << endl;
		cout << "a number between 1 and " << max << endl;
		cin >> input;
		cin.ignore(1000, '\n');
	}
	return input;
}
*/

// function for validating parameter input from user to ensure it
// is numbers > 0.
// design came as a result of several resources:
// 1.checking individual chars in input string vs. the ascii code
//   for numers came from piazza post 223 (link below).
//   https://piazza.com/class/iv5rux38y871ci?cid=233
// 2.several other parts of the function (namely the stringstream
//   conversion) came from learncpp.com article (link below).
//   http://www.learncpp.com/cpp-tutorial/185-stream-states-and-input-validation/
int inputValid()
{
	// holds the input put in by user
	string aString;
	// variable that will hold value once validated
	int aNum;

	// check to ensure character is a number
	bool valid = false;

	while(!valid)
	{
		cin >> aString;
		cin.clear();
		cin.ignore(1000, '\n');

		// for loop that check indiviual characters in string vs.
		// the ascii codes for numerals.
		for(int index = 0; index < aString.length(); index++)
		{	
			//pulls out individual characters from string
			char strCharacter = aString.at(index);

			if(strCharacter < 48 || strCharacter > 57)
			{
				valid = false;
				break;
			}
			else
			{
				valid = true;
			}	
		}

		if(!valid)
		{
			cout << "Sorry, invalid input. Only numbers accepted."
			<< endl;
		}
	}

	// converts string to number
	std::stringstream strStream;
	strStream << aString;
	strStream >> aNum;

	// runs additional checks
	if(aNum <= 0)
	{
		valid = false;
	}

	if (!valid)
	{
		cout << "Sorry, invalid input. Please enter a number larger than 0." << endl;
		inputValid();
	}

	return aNum;
}

