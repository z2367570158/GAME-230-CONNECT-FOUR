
#include "Config.h"
#include "Judge.h"
#include "ai.h"

int board[7][6];
int ranking[7];
bool again = true;
bool win = false;
string inputString = "";
int inputColumn = -1;
char whoturn = 'X';

int currentRow = -1;
int currentCol = -1;

template <class T>
int getArrayLen(T& array)
{

	return (sizeof(array) / sizeof(array[0]));
}


void paintBoard();
bool inputNotNumber(string input);
bool invalidNumber(int input);
void changeTurn();
bool putOnBoard(int column);
void initiate();
bool isDrawGame();
void resetRanking();

void printRanking()
{
	for (int i = 0; i < getArrayLen(ranking); i++)
	{
		cout << ranking[i]<<"   ";
	}
	cout << endl;
}

int main()
{
 	while (again)
	{
		initiate();
		system("cls");
		while (!win)
		{
			
			paintBoard();
			
			cout << "it's " << whoturn << "'s turn," << "choose the column you want to put:";


			while (invalidNumber(inputColumn))
			{
				cin >> inputString;

				if (inputNotNumber(inputString))
				{
					cout << "sorry, you must input a number, please re-input:";
					continue;
				}

				inputColumn = atoi(inputString.c_str())-1;

				if (invalidNumber(inputColumn))
				{
					cout << "sorry, invalid number, please re-input:";
					continue;
				}

				if (!putOnBoard(inputColumn))
				{
					cout << "sorry, the column is full, please re-input:";
					inputColumn = -1;
					continue;
				}
			}

			system("cls");

			if (judgeAll(currentCol, currentRow))
			{
				paintBoard();
				win = true;
				cout << "game over, " << whoturn << " wins! do you want to play again? y/n:";
				char tempAgain = ' ';
				while (tempAgain != 'Y'&&tempAgain != 'y'&&tempAgain != 'N'&&tempAgain != 'n')
				{
					cin >> tempAgain;
					if (tempAgain == 'Y' || tempAgain == 'y')
					{
						again = true;
					}
					else if (tempAgain == 'N' || tempAgain == 'n')
					{
						again = false;
					}
				}
			}

			if (isDrawGame())
			{
				paintBoard();
				win = true;
				cout << "game over, draw game! do you want to play again? y/n:";
				char tempAgain = ' ';
				while (tempAgain != 'Y'&&tempAgain != 'y'&&tempAgain != 'N'&&tempAgain != 'n')
				{
					cin >> tempAgain;
					if (tempAgain == 'Y' || tempAgain == 'y')
					{
						again = true;
					}
					else if (tempAgain == 'N' || tempAgain == 'n')
					{
						again = false;
					}
				}
			}


			inputColumn = -1;

			changeTurn();
			resetRanking();
			setRanking();
			printRanking();
			int aiColumn = searchTopRanking();
			putOnBoard(aiColumn);
			paintBoard();
			system("cls");

			if (judgeAll(currentCol, currentRow))
			{
				paintBoard();
				win = true;
				cout << "game over, " << whoturn << " wins! do you want to play again? y/n:";
				char tempAgain = ' ';
				while (tempAgain != 'Y'&&tempAgain != 'y'&&tempAgain != 'N'&&tempAgain != 'n')
				{
					cin >> tempAgain;
					if (tempAgain == 'Y' || tempAgain == 'y')
					{
						again = true;
					}
					else if (tempAgain == 'N' || tempAgain == 'n')
					{
						again = false;
					}
				}
			}

			if (isDrawGame())
			{
				paintBoard();
				win = true;
				cout << "game over, draw game! do you want to play again? y/n:";
				char tempAgain = ' ';
				while (tempAgain != 'Y'&&tempAgain != 'y'&&tempAgain != 'N'&&tempAgain != 'n')
				{
					cin >> tempAgain;
					if (tempAgain == 'Y' || tempAgain == 'y')
					{
						again = true;
					}
					else if (tempAgain == 'N' || tempAgain == 'n')
					{
						again = false;
					}
				}
			}
			changeTurn();
		}
	}

	
	system("pause");
}


void paintBoard()
{
	for (int i = 0; i < getArrayLen(board); i++)
		cout << i+1 << " ";

	cout << endl;

	for (int i = 0;i<getArrayLen(board[0]);i++)
	{
		for (int j = 0; j < getArrayLen(board); j++)
		{
			if (board[j][i] == 0)
			{
				cout << ". ";
			}
			else if(board[j][i]==1)
			{
				cout << "X ";
			}
			else if (board[j][i] == 2)
			{
				cout << "O ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

bool inputNotNumber(string input)
{
	if (input.empty())
	{
		cout << "empty" << endl;
		return true;
	}
	else
	{
		for (int i = 0; i < input.length(); i++)
		{
			if (input.c_str()[i] < '0' || input.c_str()[i] > '9')
			{
				return true;
			}
		}
	}
	
	return false;
}

bool invalidNumber(int input)
{
	if (input >= getArrayLen(board) || input < 0)
		return true;
	else
		return false;
}

void changeTurn()
{
	if (whoturn == 'X')
		whoturn = 'O';
	else if (whoturn == 'O')
		whoturn = 'X';
}

bool putOnBoard(int column)
{
	for (int i = getArrayLen(board[column]) - 1; i >= 0; i--)
	{
		if (board[column][i] == 0)
		{
			if (whoturn == 'X')
			{
				board[column][i] = 1;
				currentCol = column;
				currentRow = i;
				return true;
			}
			else
			{
				board[column][i] = 2;
				currentCol = column;
				currentRow = i;
				return true;
			}
		}
	}
	return false;
}


void initiate()
{
	for (int i = 0; i < getArrayLen(board); i++)
	{
		for (int j = 0; j < getArrayLen(board[0]); j++)
		{
			board[i][j] = 0;
			ranking[i] = 0;
		}
	}
	win = false;
	inputString = "";
	inputColumn = -1;
	whoturn = 'X';

	currentRow = -1;
	currentCol = -1;
}

bool isDrawGame()
{
	for (int i = 0; i < getArrayLen(board); i++)
	{
		for (int j = 0; j < getArrayLen(board[0]); j++)
		{
			if (board[i][j] == 0)
				return false;
		}
	}
	return true;
}

void resetRanking()
{
	for (int i = 0; i < getArrayLen(ranking); i++)
	{
		ranking[i] = 0;
	}
}