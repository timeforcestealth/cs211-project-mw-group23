#include <iostream>
#include <random>
#include <iomanip>
using namespace std;

void move_left(int board[][5], int numrows = 5)
{
	//Move left before merge
	for (int row = 0; row < 5; row++)
	{
		// Start at the leftmost column
		int targetColumn = 0;

		// Move all numbers left
		for (int col = 0; col < 5; col++)
		{
			//check if the number is 0 or not
			if (board[row][col] != 0)
			{
				//If not in leftmost column
				if (col != targetColumn)
				{
					board[row][targetColumn] = board[row][col];
					board[row][col] = 0;
				}
				//Move all numbers left 
				targetColumn++;
			}
		}
		//Merge matching numbers in the direction of last movement
		for (int col = 0; col < 4; col++)
		{
			//Check if the number to the right is the same number
			if (board[row][col] != 0 &&
				board[row][col] == board[row][col + 1])
			{
				// Double the left number
				board[row][col] *= 2;

				// Remove the right number
				board[row][col + 1] = 0;

				// Skip the number that just merged
				col++;
			}
		}
		//Move remaining numbers left again
		targetColumn = 0;

		for (int col = 0; col < 5; col++)
		{
			if (board[row][col] != 0)
			{
				if (col != targetColumn)
				{
					board[row][targetColumn] = board[row][col];
					board[row][col] = 0;
				}

				targetColumn++;
			}
		}
	}
}

void move_right(int board[][5], int numrows = 5)
{
	//Move right before merge
	for (int row = 4; row >= 0; row--)
	{
		// Start at the rightmost column
		int targetColumn = 4;

		// Move all numbers right
		for (int col = 4; col >= 0; col--)
		{
			//check if the number is 0 or not
			if (board[row][col] != 0)
			{
				//If not in leftmost column
				if (col != targetColumn)
				{
					board[row][targetColumn] = board[row][col];
					board[row][col] = 0;
				}
				//Move all numbers left 
				targetColumn--;
			}
		}
		//Merge matching numbers in the direction of last movement
		for (int col = 4; col >= 0; col--)
		{
			//Check if the number to the right is the same number
			if (board[row][col] != 0 &&
				board[row][col] == board[row][col - 1])
			{
				// Double the right number
				board[row][col] *= 2;

				// Remove the right number
				board[row][col - 1] = 0;
				// Skip the number that just merged
					col--;
				}
			}
			targetColumn = 4;

			// Move all numbers right
			for (int col = 4; col >= 0; col--)
			{
				//check if the number is 0 or not
				if (board[row][col] != 0)
				{
					//If not in leftmost column
					if (col != targetColumn)
					{
						board[row][targetColumn] = board[row][col];
						board[row][col] = 0;
					}
					//Move all numbers left 
					targetColumn--;
				}
			}	
	}
}

void move_up(int board[][5], int numrows = 5)
{
	//Move right before merge
	for (int col = 0; col < 5; col++)
	{
		// Start at the topmost row
		int targetRow = 0;

		// Move all numbers right
		for (int row = 0; row < 5; row++)
		{
			//check if the number is 0 or not
			if (board[row][col] != 0)
			{
				//If not in topmost column
				if (row != targetRow)
				{
					board[targetRow][col] = board[row][col];
					board[row][col] = 0;
				}
				//Move all numbers left 
				targetRow++;
			}
		}
		//Merge matching numbers in the direction of last movement
		for (int row = 0; row < 4; row++)
		{
			//Check if the number bellow is the same number
			if (board[row][col] != 0 &&
				board[row][col] == board[row + 1][col])
			{
				// Double the upper number
				board[row][col] *= 2;

				// Remove the lower number
				board[row + 1][col] = 0;
				// Skip the number that just merged
					row++;
				}
			}
			targetRow = 0;

			// Move all numbers right
			for (int row = 0; row < 5; row++)
			{
				//check if the number is 0 or not
				if (board[row][col] != 0)
				{
					//If not in leftmost column
					if (row != targetRow)
					{
						board[targetRow][col] = board[row][col];
						board[row][col] = 0;
					}
					//Move all numbers upwards 
					targetRow++;
				}
			}	
	}
}

void move_down(int board[][5], int numrows = 5)
{
	//CODE HERE
	//Move down before merge
	for (int col = 4; col >= 0; col--)
	{
		// Start at the bottommost row
		int targetRow = 4;

		// Move all numbers right
		for (int row = 4; row >= 0; row--)
		{
			//check if the number is 0 or not
			if (board[row][col] != 0)
			{
				//If not in topmost column
				if (row != targetRow)
				{
					board[targetRow][col] = board[row][col];
					board[row][col] = 0;
				}
				//Move all numbers down
				targetRow--;
			}
		}
		//Merge matching numbers in the direction of last movement
		for (int row = 4; row >=0; row--)
		{
			//Check if the number above is the same number
			if (board[row][col] != 0 &&
				board[row][col] == board[row - 1][col])
			{
				// Double the lower number
				board[row][col] *= 2;

				// Remove the upper number
				board[row - 1][col] = 0;
				// Skip the number that just merged
					row--;
				}
			}
			targetRow = 4;

			// Move all numbers down
			for (int row = 4; row >=0; row--)
			{
				//check if the number is 0 or not
				if (board[row][col] != 0)
				{
					//If not in bottommost column
					if (row != targetRow)
					{
						board[targetRow][col] = board[row][col];
						board[row][col] = 0;
					}
					//Move all numbers down 
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

