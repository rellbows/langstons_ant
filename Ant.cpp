/*********************************************************************
** Program name: LangstonsAnt
** Author: Ryan Ellis
** Date: 1/22/17
** Description: Class implementation file for Ant class.
*********************************************************************/

#include <iostream> // for testing
#include "Ant.hpp"
#include "Board.hpp"

using std::cout;
using std::endl;

Ant::Ant(Board *aBoardPtr, int numSteps, int rowIn, int columnIn)
{
	currentBoardPtr = aBoardPtr;
	currentRow = rowIn;
	currentColumn = columnIn;
	previousRow = rowIn;
	previousColumn = columnIn;
	currentPointColor = '#';
	previousPointColor = '#'; // whole board is black, so defaults to that
	steps = numSteps;
	currentHeading = NORTH;
}

Ant::~Ant()
{
	currentBoardPtr = 0;
}

void Ant::setBoard(Board *boardPtrIn)
{
	currentBoardPtr = boardPtrIn;
}

// mostly for testing
Board* Ant::getBoard()
{
	return currentBoardPtr;
}

void Ant::setPoint(int rowIn, int columnIn)
{
	currentRow = rowIn;
	currentColumn = columnIn;
}

void Ant::setHeading(Heading headingIn)
{
	currentHeading = headingIn;
}

void Ant::move()
{
	// show ant starting point
	cout << "Start" << endl;
	currentBoardPtr->antOnBoard(currentRow, currentColumn);

	currentBoardPtr->printBoard();

	for(int stepsTaken = 1; stepsTaken <= steps; stepsTaken++)
	{
		cout << "Step #" << stepsTaken << endl;

		// moves the ant in differnt direction based on heading
		switch(currentHeading)
		{
			// for north
			case 0:
				previousRow = currentRow;
				previousColumn = currentColumn;
				if(currentRow == 0)
				{	
					
					currentRow = currentBoardPtr->getLastRow();
				}
				else
				{
					currentRow -= 1;
				}

				// swaps out the colors
				previousPointColor = currentPointColor;
				currentPointColor = currentBoardPtr->getCurrentPointColor(currentRow, 
	currentColumn);

			break;
			
			// for east
			case 1: 
				previousRow = currentRow;
				previousColumn = currentColumn;
				if(currentColumn == currentBoardPtr->getLastColumn())
				{
					currentColumn = 0;
				}
				else
				{
					currentColumn += 1;
				}

							// swaps out the colors
				previousPointColor = currentPointColor;
				currentPointColor = currentBoardPtr->getCurrentPointColor(currentRow, 
	currentColumn);

			break;

			// for south
			case 2:
				previousRow = currentRow;
				previousColumn = currentColumn;
				if(currentRow == currentBoardPtr->getLastRow())
				{
					currentRow = 0;
				}
				else
				{
					currentRow += 1;
				}

							// swaps out the colors
				previousPointColor = currentPointColor;
				currentPointColor = currentBoardPtr->getCurrentPointColor(currentRow, 
	currentColumn);

			break;

			// for west
			case 3:

				// passes current position to previous in preparation for 
				// updating current position
				previousRow = currentRow;
				previousColumn = currentColumn;

				//
				if(currentColumn == 0)
				{
					currentColumn = currentBoardPtr->getLastColumn();
				}			
				else
				{
					currentColumn -= 1;
				}

							// swaps out the colors
				previousPointColor = currentPointColor;
				currentPointColor = currentBoardPtr->getCurrentPointColor(currentRow, 
	currentColumn);

			break;
		}

	// flows new info back to the board object
	boardUpdate();

	// determines the new heading
	turn();
	
	cout << endl;
	}
}

// helper function that flows data back to the board object
void Ant::boardUpdate()
{

			// updates board of where ant's new position is
			currentBoardPtr->antOnBoard(currentRow, currentColumn);
			// updates board at ant's previous point to correct color
			currentBoardPtr->prevPoint(previousRow, previousColumn, previousPointColor);
			
			currentBoardPtr->printBoard();
}

// changes the ants heading based on current heading/point color
void Ant::turn()
{
			if(currentHeading == NORTH)
			{
				if(currentPointColor == '#')
				{
					currentHeading = WEST;
				}
				else
				{
					currentHeading = EAST;
				}
			}
			else if(currentHeading == EAST)
			{
				if (currentPointColor == '#')
				{
					currentHeading = NORTH;
				}
				else
				{
					currentHeading = SOUTH;
				}
			}
			else if(currentHeading == SOUTH)
			{
				if (currentPointColor == '#')
				{
					currentHeading = EAST;
				}
				else
				{
					currentHeading = WEST;
				}
			}
			else
			{
				if (currentPointColor == '#')
				{
					currentHeading = SOUTH;
				}
				else
				{
					currentHeading = NORTH;
				}
			}
}
