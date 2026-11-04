#include <iostream>
#include <random>
#include <iomanip>
using namespace std;

void move_left(int board[][5], int numrows = 5)
{
	//CODE HERE
	//move all numbers to the left
	for (int row = 0; row < 5; row++)
	{
		//start at the leftmost column
    	int targetColumn = 0;
		//Examine each column, moving left to right
    	for (int col = 0; col < 5; col++)
    	{
			//Ignore zeroes
        	if (board[row][col] != 0)
        	{
            	if (col != targetColumn)
            	{
					//move to target column
               		board[row][targetColumn] = board[row][col];
					//clear the original position
                	board[row][col] = 0;
            	}
				//move the target position one column right
            	targetColumn++;
        	}
    	}
	}
}

void move_right(int board[][5], int numrows = 5)
{
	//CODE HERE
	// Move all numbers to the right
	for (int row = 0; row < 5; row++)
	{
		// Start at the rightmost column
		int targetColumn = 4;

		// Examine each column, moving from right to left
		for (int col = 4; col >= 0; col--)
		{
			// Ignore empty spaces (zeros)
			if (board[row][col] != 0)
			{
				// Only move the number if it isn't already in the correct position
				if (col != targetColumn)
				{
					// Move the number to the target column
					board[row][targetColumn] = board[row][col];

					// Clear its original position
					board[row][col] = 0;
				}

				// Move the target position one column left
				targetColumn--;
			}
		}
	}
}

void move_up(int board[][5], int numrows = 5)
{
	//CODE HERE
	// Move all numbers up
	for (int col = 0; col < 5; col++)
	{
		// Start at the highest row
		int targetRow = 0;

		// Examine each row, moving down
		for (int row = 0; row < 5; row++)
		{
			// Ignore empty spaces (zeros)
			if (board[row][col] != 0)
			{
				// Only move the number if it isn't already in the correct position
				if (row != targetRow)
				{
					// Move the number to the target row
					board[targetRow][col] = board[row][col];

					// Clear its original position
					board[row][col] = 0;
				}

				// Move the target position one row down
				targetRow++;
			}
		}
	}
}

void move_down(int board[][5], int numrows = 5)
{
	//CODE HERE
	// Move all numbers down
	for (int col = 0; col < 5; col++)
	{
		// Start at the highest row
		int targetRow = 4;

		// Examine each row, moving up
		for (int row = 4; row >=0; row--)
		{
			// Ignore empty spaces (zeros)
			if (board[row][col] != 0)
			{
				// Only move the number if it isn't already in the correct position
				if (row != targetRow)
				{
					// Move the number to the target row
					board[targetRow][col] = board[row][col];

					// Clear its original position
					board[row][col] = 0;
				}

				// Move the target position one row down
				targetRow--;
			}
		}
	}
}


void print_board(int board[][5], int numrows = 5)
{
	cout << endl << "\t-----------------------------------------" << endl;

	for (int r = 0; r < numrows; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			if(board[r][c] > 0)
				cout << "\t|" << right << setw(6) << setfill(' ') << board[r][c];
			else
				cout << "\t|" << right << setw(6) << setfill(' ') << " ";

			//cout << board[r][c] << "\t|\t";
		}
		cout << "\t|" << endl;
		cout << "\t-----------------------------------------" << endl;
	}

	cout << "\t" << endl << endl;
}


void insert_random(int board[][5], int numrows = 5)
{
	int r, c;
	//count empty
	int empty_count = 0;
	for (int r = 0; r < numrows; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			if (board[r][c] == 0)
				empty_count++;
		}
	}

	if (empty_count > 0)
	{
		while (true)
		{
			//generate random location r, c
			r = rand() % numrows;
			c = rand() % numrows;
			//check if empty
			if (board[r][c] == 0)
			{
				//add number randomly {2,4}
				board[r][c] = 2 * (1 + (rand() % 2));
				break;
			}
		}

	}
}

