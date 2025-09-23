// Connect Four.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>

const int rows = 6;
const int cols = 7;

const char empty = '-';
const char divider = '|';
const char nought = 'O';
const char cross = 'X';

// Prints the board to the console
void printBoard(const std::vector<std::vector<char>>& board)
{
    for (int r = 0; r < rows; r++)
    {
		std::cout << divider;

        for (int c = 0; c < cols; c++)
        {
            std::cout << " " << board[r][c] << " " << divider;
        }
        std::cout << std::endl;
    }
}

// Updates the board with the player's turn
void updateBoard(std::vector<std::vector<char>>& board, int column, char playerPiece)
{
    for (int r = rows - 1; r >= 0; r--)
    {
        if (board[r][column] == empty)
        {
            board[r][column] = playerPiece;
            break;
        }
    }
}

bool checkForWinner(const std::vector<std::vector<char>>& board, char playerPiece)
{
    // Horizontal Win
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c <= cols - 4; c++) // The last few columns don't need to be checked as we're checking from the starting points
        {
            if (board[r][c] == playerPiece &&
                board[r][c + 1] == playerPiece &&
                board[r][c + 2] == playerPiece &&
                board[r][c + 3] == playerPiece)
                return true;
        }
    }

    // Vertical Win
    for (int c = 0; c < cols; c++)
    {
        for (int r = 0; r <= rows - 4; r++)
        {
            if (board[r][c] == playerPiece &&
                board[r + 1][c] == playerPiece &&
                board[r + 2][c] == playerPiece &&
                board[r + 3][c] == playerPiece)
                return true;
        }
    }

    // Horizontal Win


    return false; // No winners
}

int main()
{
    std::cout << "Connect Four!" << std::endl;
    std::cout << std::endl;

	std::vector<std::vector<char>> board(rows, std::vector<char>(cols, empty));
    
	printBoard(board);
    std::cout << std::endl;
	
    bool gameOver = false; // For the while loop, to keep game running if not over
    bool noughtTurn = true;
    int turnCount = 0; // Used to check for draws

    while (gameOver == false) // Loops whilst game isn't over
    {
        int chosenColumn = 0;
        char currentPlayerPiece = (noughtTurn) ? nought : cross; // Checks whose turn it is for messages

        if (noughtTurn)
        {
            std::cout << "Nought's turn, which column do you want to drop your piece into? ";
        }
        else
        {
            std::cout << "Cross's turn, which column do you want to drop your piece into? ";
        }

        // Ensures the input is within bounds, in a free column, or input is numerical
        bool validInput = false;
        while (!validInput)
        {
            std::cin >> chosenColumn;

            if (chosenColumn < 1 || chosenColumn > 7 || std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n'); // Resets the cin, either by ignoring 10,000 characters or when a new line is hit
                std::cout << "Invalid Input! Must be 1-7! ";
            }   
            else if (board[0][chosenColumn - 1] != empty)
                std::cout << "Column is full! Pick Again! ";
            else
                validInput = true;
        }

        updateBoard(board, chosenColumn - 1, currentPlayerPiece); // Updates the board with each turn
        turnCount++;

        printBoard(board); // Prints the board once a turn has been completed
        std::cout << std::endl;

        if (checkForWinner(board, currentPlayerPiece))
        {
            gameOver = true;
            if (currentPlayerPiece == nought)
                std::cout << "Congratulations! Noughts Win!" << std::endl;
            else
                std::cout << "Congratulations! Crosses Win!" << std::endl;
        }
        else if (turnCount == rows * cols) // Checks for tie, via checking if the sum of the board's tiles has been reached
        {
            gameOver = true;
            std::cout << "Its a Draw!" << std::endl;
        }
            

        noughtTurn = !noughtTurn; // Switches whose turn it is

    }
}