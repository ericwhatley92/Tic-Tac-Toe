/*
Eric Whatley	11/28/2012
Implementation File
Tic Tac Toe
*/

#include <iostream>
#include <cstring>
#include <string>
#include "tictactoe.h"

using namespace std;


enum Marker{X, O};
Marker mark;

//variables for the overall winner function
int xWin, oWin, cat = 0;

//prototypes
void printX(int, int, int, int, char[][12]); // sets up the X in the board
void printO(int, int, int, int, char[][12]); //sets up the O in the board


TicTacToe::TicTacToe()
{
	gameCount = 0;
	for(int row = 0; row<12; row++)
		for(int col = 0; col<12; col++)
			{
				if(row == 2 && col == 0)
					board[row][col] = 'A';
				else if(row == 6 && col == 0)
					board[row][col] = 'B';
				else if(row == 10 && col == 0)
					board[row][col] = 'C';
				//these 3 are for the A,B,C coordinates to be in their places
				else if(row == 0 || col == 0)
					board[row][col] = ' ';
				//for the blank spaces in the 0 column
				else if(float(col)/4 == 1 || float(col)/4 == 2)
					board[row][col] = '|';
				//to place the vertical lines
				else if(float(row)/4 == 1 || float(row)/4 == 2)
					board[row][col] = '-';
				//to place the horizontal lines
				else
					board[row][col] = ' ';
				//blank spaces everywhere else
			}		
			
}

void TicTacToe::PrintScreen()
{
	cout<<"  1"<<"   2"<<"   3"<<endl; //coordinate header
	for(int row = 0; row<12; row++)
		for(int col = 0; col<12; col++)
		{	
			cout<<board[row][col];
			if(col == 11)
				cout<<endl;
		}	
}

void TicTacToe::FindMark()
{
	char response;
	bool finished = false;
	do
	{
		cout<<"Would you like to start with X or O?"<<endl;
		cin>>response;
		switch(response)
		{
			case 'O':
			case 'o':
				{
					mark = O;
					finished = true;
					break;
				}
			case 'X':
			case 'x':
				{
					mark = X;
					finished = true;
					break;
				}
			default:
				cout<<"Wrong! Try again!"<<endl;
		}
	}while(!finished);
}

void TicTacToe::GetInput()
{
	switch(mark)
	{
		case X:
			{
				cout<<"X: Enter your coordinates: "<<endl;
				gameCount++;
				break;
			}
		case O:
			{
				cout<<"O: Enter your coordinates: "<<endl;
				gameCount++;
				break;
			}
	};

		cin>>ch1>>ch2;
}
void TicTacToe::PlaceMark()
{
	switch(ch1)
	{
		case 'A':
		case 'a':
			{	
				switch(ch2)
				{
					case '1':
					{
						y = 1;
						endy = 3;					
						break;
					}
					case '2':
					{
						y = 5;
						endy = 7;
						break;
					}
					case '3':
					{
						y = 9;
						endy = 11;
						break;
					}
				};
				x = 1;
				endx = 3;
				break;
			}	
		case 'B':
		case 'b':
			{
				switch(ch2)
				{
					case '1':
					{
						y = 1;
						endy = 3;
						break;
					}
					case '2':
					{
						y = 5;
						endy = 7;
						break;
					}
					case '3':
					{
						y = 9;
						endy = 11;
						break;
					}
				};
				x = 5;
				endx = 7;
				break;
			}
		case 'C':
		case 'c':
			{
				switch(ch2)
				{
					case '1':
					{
						y = 1;
						endy = 3;
						break;
					}
					case '2':
					{
						y = 5;
						endy = 7;
						break;
					}
					case '3':
					{
						y = 9;
						endy = 11;
						break;
					}
				};
				x = 9;
				endx = 11;
				break;
			}	
	};
		
	switch(mark)
	{
		case X:
			{
				printX(x, endx, y, endy, board);
				mark = Marker(mark+1);
				break;
			}
		case O:	
			{						
				printO(x, endx, y, endy, board); 
				mark = Marker(mark-1);
				break;
			}
	};
}

bool TicTacToe::FindWinner()
{	
	if((board[2][2]=='X' && board[2][6]=='X' && board[2][10]=='X') || //row A
	(board[6][2]=='X' && board[6][6]=='X' && board[6][10]=='X') || //row B
	(board[10][2]=='X' && board[10][6]=='X' && board[10][10]=='X')) //row C
	{
		cout<<"X is the winner!"<<endl;
		xWin++;
		return true;
	}
	
	else if((board[2][2]=='X' && board[6][2]=='X' && board[10][2]=='X' ) || //col 1
	(board[2][6]=='X' && board[6][6]=='X' && board[10][6]=='X') || //col 2
	(board[2][10]=='X' && board[6][10]=='X' && board[10][10]=='X')) //col 3
	{
		cout<<"X is the winner!"<<endl;
		xWin++;
		return true;
	}
	
	else if((board[2][2]=='X' && board[6][6]=='X' && board[10][10]=='X') || //first diagonal
	(board[2][10]=='X' && board[6][6]=='X' && board[10][2]=='X')) //second diagonal
	{
		cout<<"X is the winner!"<<endl;
		xWin++;
		return true;
	}
//-----------------------------------------------------------------------------------
	if((board[2][1]=='|' && board[2][5]=='|' && board[2][9]=='|') || //row A
	(board[6][1]=='|' && board[6][5]=='|' && board[6][9]=='|') || //row B
	(board[10][1]=='|' && board[10][5]=='|' && board[10][9]=='|')) //row C
	{
		cout<<"O is the winner!"<<endl;
		oWin++;
		return true;
	}
	
	else if((board[2][1]=='|' && board[6][1]=='|' && board[10][1]=='|' ) || //col 1
	(board[2][5]=='|' && board[6][5]=='|' && board[10][5]=='|') || //col 2
	(board[2][9]=='|' && board[6][9]=='|' && board[10][9]=='|')) //col 3
	{
		cout<<"O is the winner!"<<endl;
		oWin++;
		return true;
	}
	
	else if((board[2][1]=='|' && board[6][5]=='|' && board[10][9]=='|') || //first diagonal
	(board[2][9]=='|' && board[6][5]=='|' && board[10][1]=='|')) //second diagonal
	{
		cout<<"O is the winner!"<<endl;
		oWin++;
		return true;
	}
//-----------------------------------------------------------------------------------	
	else if (gameCount == 9)
	{
		cout<<"Cat!"<<endl;
		cat++;
		return true;
	}
	else
		return false;
}
	
void TicTacToe::WinnerStats()
{
	int total = xWin + oWin + cat;
	if(xWin > oWin)
		cout<<"The winner was X with a total of "<<xWin<<" wins out of "<<total<<" total games!"<<endl;
	else if(oWin > xWin)
		cout<<"The winner was O with a total of "<<oWin<<" wins out of "<<total<<" total games!"<<endl;
	else
		cout<<"Tied! No overall winner!"<<endl;
}

void printX(int x, int endx, int y, int endy, char board[][12])
{
	int count = 0;
	for(int row = x; row<=endx; row++)
		for(int col = y; col<=endy; col++)
		{
			switch(count)
			{
				case 0:
				case 8:
					{
						board[row][col] = '\\';
						count++;
						break;
					}
				case 2:
				case 6:
					{
						board[row][col] = '/';
						count++;
						break;
					}
				case 4:
					{
						board[row][col] = 'X';
						count++;
						break;
					}
				default:
					{
						count++;
						break;
					}
				
			}
		}
}
	
void printO(int x, int endx, int y, int endy, char board[][12])
{
	int count = 0;
	for(int row = x; row<=endx; row++)
		for(int col = y; col<=endy; col++)
		{
			switch(count)
			{
				case 0:
				case 8:
					{
						board[row][col] = '/';
						count++;
						break;
					}
				case 1:
				case 7:
					{
						board[row][col] = '-';
						count++;
						break;
					}
				case 2:
				case 6:
					{
						board[row][col] = '\\';
						count++;
						break;
					}
				case 3:
				case 5:
					{
						board[row][col] = '|';
						count ++;
						break;
					}
				case 4:
					{
						board[row][col] = ' ';
						count++;
						break;
					}
				
			}
		}
}


