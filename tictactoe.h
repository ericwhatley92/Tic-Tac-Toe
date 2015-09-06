/*
Eric Whatley	11/28/2012
Specification File
Tic Tac Toe
*/

#include <iostream>

using namespace std;

class TicTacToe
{
public:
	TicTacToe();
	//constructor setting the blank spaces to 0
	
	void PrintScreen();
	//prints the tic tac toe board to the screen
	
	void FindMark();
	//asks what mark (X or O) the user would like to start with
	
	void GetInput();
	//gets the input from the user and does the appropriate thing
	//Precondition:
		//FindMark must be called
	//Post Condition:
		//The mark is assigned to the appropriate place
		//PlaceMark must be called to place it
		//and PrintScreen again to show it
	
	void PlaceMark();
	//places mark on the screen
	//Precondition: 
		//GetInput MUST be called before this
	//Post Condition:
		//X or O is set in the appropriate place in the character array
		//array must be printed again to see the changes
	
	bool FindWinner();
	//finds the winner of the game
	//Should be run everytime someone goes after the FIFTH turn to check for winner.
	//or it can be run as a condition to know when to end the game
	
	void WinnerStats();
	//prints the overall winner
	
private:
	char board[12][12];
	char ch1, ch2;
	int x, endx, y, endy;
	int gameCount;
};
