#include "Judge.h"
#include "Config.h"

bool judgeAll(int col, int row, bool wrap)
{
	return judgeCol(col, row, wrap) || judgeRow(col, row, wrap) || judgeK1(col, row, wrap) || judgeK2(col, row, wrap);
}
bool judgeRow(int col, int row, bool wrap)
{
	int count = 1;
	int XorO = board[col][row];
	int i = 1;

	if (wrap) 
	{
		//left
		while (true)
		{
			int tempcol = (col - i < 0 ? (col - i + getArrayLen(board)) : col - i);
			if (XorO == board[tempcol][row])
			{
				count++;
				if (count >= 4)
				{
					return true;
				}
			}
			else
				break;

			i++;
		}
		//right
		i = 1;
		while (true)
		{
			int tempcol = (col + i > (getArrayLen(board) - 1) ? (col + i - getArrayLen(board)) : col + i);
			if (XorO == board[tempcol][row])
			{
				count++;
				if (count >= 4)
				{
					return true;
				}
			}
			else
				break;

			i++;
		}
	}
	else
	{

		for(int i=1;col-i>=0;i++)
		{
		if (XorO == board[col - i][row])
		count++;
		else
		break;
		}


		for (int i = 1; col + i < getArrayLen(board); i++)
		{
		if (XorO == board[col + i][row])
		count++;
		else
		break;
		}
	}
	
	if (count >= 4)
		return true;
	else
		return false;
}
bool judgeCol(int col, int row, bool wrap)
{
	int count = 1;
	int XorO = board[col][row];
	int i = 1;

	if (wrap)
	{
		//up
		while (true)
		{
			int temprow = (row - i < 0 ? (row - i + getArrayLen(board[col])) : row - i);
			if (XorO == board[col][temprow])
			{
				count++;
				if (count >= 4)
				{
					return true;
				}
			}
			else
				break;

			i++;
		}
		//down
		i = 1;
		while (true)
		{
			int temprow = (row + i > (getArrayLen(board[col]) - 1) ? (row + i - getArrayLen(board[col])) : row + i);
			if (XorO == board[col][temprow])
			{
				count++;
				if (count >= 4)
				{
					return true;
				}
			}
			else
				break;

			i++;
		}
	}
	else
	{


		for (int i = 1; row - i >= 0; i++)
		{
			if (XorO == board[col][row - i])
				count++;
			else
				break;
		}

		for (int i = 1; row + i < getArrayLen(board[col]); i++)
		{
		if (XorO == board[col][row + i])
		count++;
		else
		break;
		}
	}


	if (count >= 4)
		return true;
	else
		return false;
}
bool judgeK1(int col, int row, bool wrap)
{
	int count = 1;
	int XorO = board[col][row];
	int i = 1;

	if (wrap)
	{
		//left down
		while (true)
		{
			int tempcol = (col - i < 0 ? (col - i + getArrayLen(board)) : col - i);
			int temprow = (row + i >(getArrayLen(board[col]) - 1) ? (row + i - getArrayLen(board[col])) : row + i);

			if (XorO == board[tempcol][temprow])
			{
				count++;
				if (count >= 4)
				{
					return true;
				}
			}
			else
				break;

			i++;
		}
		//right up
		i = 1;
		while (true)
		{
			int tempcol = (col + i > (getArrayLen(board) - 1) ? (col + i - getArrayLen(board)) : col + i);
			int temprow = (row - i < 0 ? (row - i + getArrayLen(board[col])) : row - i);

			if (XorO == board[tempcol][temprow])
			{
				count++;
				if (count >= 4)
				{
					return true;
				}
			}
			else
				break;

			i++;
		}
	}
	else
	{
		for (int i = 1; col - i >= 0&& row+i<getArrayLen(board[col-i]); i++)
		{
		if (XorO == board[col-i][row + i])
		count++;
		else
		break;
		}

		for (int i = 1; col + i < getArrayLen(board) && row - i >= 0; i++)
		{
		if (XorO == board[col + i][row - i])
		count++;
		else
		break;
		}
	}

	
	

	if (count >= 4)
		return true;
	else
		return false;
}
bool judgeK2(int col, int row, bool wrap)
{
	int count = 1;
	int XorO = board[col][row];
	int i = 1;

	if (wrap)
	{
		//right down
		while (true)
		{
			int tempcol = (col + i > (getArrayLen(board) - 1) ? (col + i - getArrayLen(board)) : col + i);
			int temprow = (row + i >(getArrayLen(board[col]) - 1) ? (row + i - getArrayLen(board[col])) : row + i);

			if (XorO == board[tempcol][temprow])
			{
				count++;
				if (count >= 4)
				{
					return true;
				}
			}
			else
				break;

			i++;
		}
		//left up
		i = 1;
		while (true)
		{
			int tempcol = (col - i < 0 ? (col - i + getArrayLen(board)) : col - i);
			int temprow = (row - i < 0 ? (row - i + getArrayLen(board[col])) : row - i);

			if (XorO == board[tempcol][temprow])
			{
				count++;
				if (count >= 4)
				{
					return true;
				}
			}
			else
				break;

			i++;
		}
	}
	else
	{
		for (int i = 1; col + i < getArrayLen(board) && row + i<getArrayLen(board[col + i]); i++)
		{
		if (XorO == board[col + i][row + i])
		count++;
		else
		break;
		}

		for (int i = 1; col - i >= 0 && row - i >= 0; i++)
		{
		if (XorO == board[col - i][row - i])
		count++;
		else
		break;
		}
	}
	
	
	if (count >= 4)
		return true;
	else
		return false;
}