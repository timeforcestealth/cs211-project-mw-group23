#include <iostream>
#include <random>
#include <iomanip>
#include <fstream>
using namespace std;

int score = 0; 

void move_left(int board[][5], int numrows = 5)
{
	//Move left w/ merging
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

				//the merged number is added to the score
				score += board[row][col]; 

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
	//Move right w/ merging
	for (int row = 4; row >=0; row--)
	{
		// Start at the rightmost column
		int targetColumn = 4;

		// Move all numbers right
		for (int col = 4; col >= 0; col--)
		{
			//check if the number is 0 or not
			if (board[row][col] != 0)
			{
				//If not in rightmost column
				if (col != targetColumn)
				{
					board[row][targetColumn] = board[row][col];
					board[row][col] = 0;
				}
				//Move all numbers right
				targetColumn--;
			}
		}
		//Merge matching numbers in the direction of last movement
		for (int col = 4; col >=0; col--)
		{
			//Check if the number to the left is the same number
			if (board[row][col] != 0 &&
				board[row][col] == board[row][col - 1])
			{
				// Double the right number
				board[row][col] *= 2;

				//the merged number is added to the score
				score += board[row][col];

				// Remove the left number
				board[row][col - 1] = 0;

				// Skip the number that just merged
				col--;
			}
		}
		//Move remaining numbers right again
		targetColumn = 4;

		for (int col = 4; col >=0; col--)
		{
			if (board[row][col] != 0)
			{
				if (col != targetColumn)
				{
					board[row][targetColumn] = board[row][col];
					board[row][col] = 0;
				}

				targetColumn--;
			}
		}
	}
}

void move_up(int board[][5], int numrows = 5)
{
	//Move up before merge
	for (int col = 0; col < 5; col++)
	{
		// Start at the topmost row
		int targetRow = 0;

		// Move all numbers up
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
				//Move all numbers up 
				targetRow++;
			}
		}
		//Merge matching numbers in the direction of last movement
		for (int row = 0; row < 4; row++)
		{
			//Check if the number below is the same number
			if (board[row][col] != 0 &&
				board[row][col] == board[row + 1][col])
			{
				// Double the upper number
				board[row][col] *= 2;

				//the merged number is added to the score
				score += board[row][col];

				// Remove the lower number
				board[row + 1][col] = 0;
				// Skip the number that just merged
					row++;
				}
			}
			targetRow = 0;

			// Move all numbers up
			for (int row = 0; row < 5; row++)
			{
				//check if the number is 0 or not
				if (board[row][col] != 0)
				{
					//If not in upperrmost column
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
	//Move down before merge
	for (int col = 4; col >= 0; col--)
	{
		// Start at the bottommost row
		int targetRow = 4;

		// Move all numbers down
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

				//the merged number is added to the score
				score += board[row][col];

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
	cout << "Score: " << score; 
	cout << "\t" << endl << endl;
}

bool game_over(int board[][5], int numrows = 5)
{
	//check every number on the board
	for (int row = 0; row<5; row++)
	{
		for (int col = 0; col<5; col++)
		{
			//is the space if a zero, return false, the game can continue
			if (board[row][col] == 0)
			{
				return false; 
			}
			//check to the right for equal number
			if (col < 4 && board [row][col] == board[row][col+1])
			{
				return false; 
			}

			//check below for equal number
			if(row <4 && board[row][col] == board[row+1][col])
			{
				return false; 
			}
		}
		 
	}
	//no empty spaces or equal numbers found
	return true;
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
bool save_game(const int board[][5]) // Saves the current game state to a file
{
    ofstream file("save.txt"); // Open the save file for writing
    if (!file) // Check if the file was successfully opened
        return false; // Could not open the save file for writing

    // Save the current score and board to the file

    file << score << ' '; // Save the current score to the file
    for (int row = 0; row < 5; row++) // Save each row of the board to the file
    {
        for (int col = 0; col < 5; col++) // Save each column of the current row to the file
            file << board[row][col] << ' '; // Save the current cell to the file
        file << ' '; // End of the current row
    }

    file.close(); // Close the save file after writing
    return !file.fail(); // Return true if the file was successfully written, false otherwise
}

bool load_game(int board[][5]) // Loads the game state from a file
{
    ifstream file("save.txt"); // Open the save file for reading
    if (!file) // Check if the file was successfully opened
        return false; // Could not open the save file for reading

    int loaded_score; // Variable to store the loaded score from the save file
    int loaded_board[5][5]; // Variable to store the loaded board from the save file

    if (!(file >> loaded_score) || loaded_score < 0) // Read the saved score and validate it
        return false; // Invalid score in the save file

    for (int row = 0; row < 5; row++) // Read each row of the board from the save file
    {
        for (int col = 0; col < 5; col++)
        {
            int value; // Variable to store the value of the current cell from the save file
            if (!(file >> value) || value < 0 || // Read the value and validate it
                (value != 0 && (value < 2 || (value & (value - 1)) != 0))) // Check if the value is a valid 2048 tile
                return false; // Invalid value in the save file

            loaded_board[row][col] = value; // Store the validated value in the loaded board
        }
    }

    // Only replace the current game after the whole save is valid.
    score = loaded_score; // Update the current score with the loaded score
    for (int row = 0; row < 5; row++) // Update each row of the current board with the loaded board
        for (int col = 0; col < 5; col++) // Update each column of the current row with the loaded board
            board[row][col] = loaded_board[row][col]; // Copy the value from the loaded board to the current board

    return true;
}

