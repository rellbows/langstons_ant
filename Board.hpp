/*********************************************************************
** Program name: LangstonsAnt
** Author: Ryan Ellis
** Date: 1/22/17
** Description: Class specification file for the Board class. 
*********************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

class Board
{
	private:
		char **board; // 2D array that holds the board		
		int boardRows, boardColumns;
	public:
		Board(int, int);
		~Board();
		void setRows(int);
		void setColumns(int);
		void createBoard();
		int getLastRow();
		int getLastColumn();
		char getCurrentPointColor(int currentRowIn, int currentColumnIn);
		void antOnBoard(int currentRowIn, int currentColumnIn);
		void prevPoint(int prevRowIn, int prevColumnIn, char prevPointColor);
		// void boardState();
		void printBoard();

};

#endif
