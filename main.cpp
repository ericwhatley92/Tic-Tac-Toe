/*
Eric Whatley	11/28/2012
Driver File
Tic Tac Toe
*/

#include <iostream>
#include "stdlib.h"
#include "tictactoe.h"

using namespace std;

TicTacToe TTT;

char response;
int count;

int main()
{

	do
	{	
		TicTacToe TTT;
		TTT.FindMark();
		count = 0;
		do
		{
			TTT.PrintScreen();
			TTT.GetInput();
			TTT.PlaceMark();
			count++;
			system("cls");
		}while(!TTT.FindWinner());
		
		cout<<"Would you like to play another game? Y/N "<<endl;
		cin>>response;
		system("cls");
	}while(response == 'Y' || response == 'y');
	
	TTT.WinnerStats();
	
	return 0;
}
