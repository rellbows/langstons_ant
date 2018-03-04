/*********************************************************************
** Program name: LangstonsAnt
** Author: Ryan Ellis
** Date: 1/22/17
** Description: Class implementation file for Board class.
*********************************************************************/

#include <iostream>
#include "Board.hpp"
// #include "Ant.hpp"

using std::cout;
using std::endl;

// constructor 


Board::Board(int rowsIn, int columnsIn)
{
	board = NULL;
	boardRows = rowsIn;
	boardColumns = columnsIn;
}

// destructor. unallocates memory the 2D board array was using.
Board::~Board()
{
	
	for(int index = 0; index < boardRows; ++index)
	{
		delete [] board[index];
	}
	
	delete [] board;
	board = NULL;
	
}

// sets the member variable for number of rows for the board by
// passing in an argument

void Board::setRows(int numRows)
{
	boardRows = numRows;
}

// sets the member variable for the number of columns for the
// board by passing in an argument

void Board::setColumns(int numColumns)
{
	boardColumns = numColumns;
}

int Board::getLastRow()
{
	return boardRows - 1;
}

int Board::getLastColumn()
{
	return boardColumns - 1;
}

char Board::getCurrentPointColor(int currentRowIn, int currentColumnIn)
{

	return board[currentRowIn][currentColumnIn];

}

// creates a 2D array using the memeber vars for rows and columns
// passed to it. then, loads x's (representing color black) int 
// each cell.

void Board::createBoard()
{

	// creating 2D array
	board = new char *[boardRows];

	for(int counter = 0; counter < boardRows; counter++)
	{
		board[counter] = new char[boardColumns];
	}

	// nested for loop to load black spaces into array
	for(int row = 0; row < boardRows; row++)
	{
		for(int column = 0; column < boardColumns; column++)
		{
			board[row][column] = '#';
			
		}
	}
}

// flows  current row/col of ant have been held in the ant object 
// as arguments. updates the board based off of those parameters.

void Board::antOnBoard(int currentRowIn, int currentColumnIn)
{
	// updates board to match ants current pos
	board[currentRowIn][currentColumnIn] = '*';
	
}

// updates point on board ant was in previously

void Board::prevPoint(int previousRowIn, int previousColumnIn, char previousPointColor)
{
	// changes the previous point to the correct color
	if(previousPointColor == '#')
	{
		board[previousRowIn][previousColumnIn] = ' ';
	}
	else
	{
		board[previousRowIn][previousColumnIn] = '#';	
	}
}

// prints out the current board

void Board::printBoard()
{
	for(int row = 0; row < boardRows; row++)
	{
		for(int column = 0; column < boardColumns; column++)
		{
			cout << board[row][column];
		}
	cout << endl;
	}
}
