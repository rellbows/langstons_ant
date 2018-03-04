/*********************************************************************
** Program name: LangstonsAnt
** Author: Ryan Ellis
** Date: 1/19/17
** Description: Class specification file for the ant class.
*********************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

#include "Board.hpp"

enum Heading {NORTH, EAST, SOUTH, WEST};

class Ant
{
	private:
	// holds coordinates of ants current position
	int currentRow;
	int currentColumn;
	// holds coordinate of ants prvious position, so board object
	// can be updated correctly
	int previousRow;
	int previousColumn;
	
	// holds the color of the previous/current points to ensure that
	// the board object will be updated correctly
	char currentPointColor;
	char previousPointColor;

	// keeps track of the ants direction
	Heading currentHeading;

	// holds number ant is supposed to take
	int steps;

	// holds Board object
	Board *currentBoardPtr;
			
	public:

	// constructor

	Ant(Board *aBoardPtr, int numSteps, int rowIn, int columnIn);
	
	// destructor
	~Ant();

	// passes the board object to the currentBoard member variable
	void setBoard(Board *); 

	// getter function for the current board Ptr
	Board* getBoard();

	// sets the current ants position
	void setPoint(int, int);

	// sets ants heading
	void setHeading(Heading);

	// moves the ant based on ants heading
	void move();

	// helper function that helps flow necessary data back to board for update
	void boardUpdate();

	// figures out ant's new heading based off current point color and heading
	void turn();

};

#endif

