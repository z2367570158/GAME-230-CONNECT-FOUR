#include "ai.h"
#include "Config.h"

int rank_near = 5;
int rank_two = 100;
int rank_three = 2000;


void setRanking()
{
	for (int i =0;i<getArrayLen(board);i++)
	{
		for (int j = getArrayLen(board[i]) - 1 ; j >= 0; j--)
		{
			if (board[i][j] == 0) {
				setRowLeftRank(i,j);
				setRowRightRank(i,j);
				setColUpRank(i,j);
				setColDownRank(i,j);
				setK1UpRank(i,j);
				setK1DownRank(i,j);
				setK2UpRank(i,j);
				setK2DownRank(i,j);
				break;
			}
		}

	}
}



void countToRank(int col, int count)
{
	switch (count)
	{
	case 0:
		ranking[col] += 0;
		break;
	case 1:
		ranking[col] += rank_near;
		break;
	case 2:
		ranking[col] += rank_two;
		break;
	case 3:
		ranking[col] += rank_three;
		break;
	}
}


void setRowLeftRank(int col, int row)
{
	int count = 0;
	for (int i = 1; col - i >= 0; i++)
	{
		if (board[col - i][row] == 1)
		{

			count++;
		}
		else 
		{
			break;
		}
	}
	countToRank(col,count);

}
void setRowRightRank(int col, int row)
{
	int count = 0;
	for (int i = 1; col + i < getArrayLen(board); i++)
	{
		if (board[col + i][row] == 1)
		{
			count++;
		}
		else
		{
			break;
		}
	}
	countToRank(col, count);
}
void setColUpRank(int col, int row)
{
	int count = 0;
	for (int i = 1; row - i >= 0; i++)
	{
		if (board[col][row - i] == 1)
		{

			count++;
		}
		else
		{
			break;
		}
	}
	countToRank(col, count);
}
void setColDownRank(int col, int row)
{
	int count = 0; 
	for (int i = 1; row + i < getArrayLen(board[col]); i++)
	{
		if (board[col][row + i] == 1)
		{
			count++;
		}
		else
		{
			break;
		}
	}
	countToRank(col, count);

}
void setK1UpRank(int col, int row)
{
	int count = 0;
	for (int i = 1; col+i < getArrayLen(board) && row - i >= 0; i++)
	{
		if (board[col+i][row - i] == 1)
		{

			count++;
		}
		else
		{
			break;
		}
	}
	countToRank(col, count);
}
void setK1DownRank(int col, int row)
{
	int count = 0;
	for (int i = 1; col - i >= 0  && row + i < getArrayLen(board[col]); i++)
	{
		if (board[col - i][row + i] == 1)
		{

			count++;
		}
		else
		{
			break;
		}
	}
	countToRank(col, count);
}
void setK2UpRank(int col, int row)
{
	int count = 0;
	for (int i = 1; col - i >= 0 && row - i >= 0; i++)
	{
		if (board[col - i][row - i] == 1)
		{

			count++;
		}
		else
		{
			break;
		}
	}
	countToRank(col, count);
}
void setK2DownRank(int col, int row)
{
	int count = 0;
	for (int i = 1; col + i < getArrayLen(board) && row + i < getArrayLen(board[col]); i++)
	{
		if (board[col + i][row + i] == 1)
		{

			count++;
		}
		else
		{
			break;
		}
	}
	countToRank(col, count);
}


int searchTopRanking()
{
	int topRankingColumn = -1;
	int topRanking = 0;
	for (int i = 0; i <	sizeof(ranking) / sizeof(ranking[0]); i++) {
		if (topRanking < ranking[i])
		{
			topRanking = ranking[i];
			topRankingColumn = i;
		}
	}
	return topRankingColumn;
}