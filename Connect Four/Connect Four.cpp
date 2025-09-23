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

int main()
{
    std::cout << "Connect Four!" << std::endl;
    std::cout << std::endl;

	std::vector<std::vector<char>> board(rows, std::vector<char>(cols, empty));
    
	printBoard(board);
    std::cout << std::endl;
	
    bool gameOver = false;
    bool noughtTurn = true;
    int chosenColumn = 0;

    while (gameOver == false) // Loops whilst game isn't over
    {
        if (noughtTurn)
        {
            std::cout << "Nought's turn, which column do you want to drop your piece into? ";
        }
        else
        {
            std::cout << "Cross's turn, which column do you want to drop your piece into? ";
        }

        std::cin >> chosenColumn;
        if (noughtTurn)
            updateBoard(board, chosenColumn - 1, nought);
        else
            updateBoard(board, chosenColumn - 1, cross);

        printBoard(board);
        std::cout << std::endl;

        noughtTurn = !noughtTurn; // Flips whose turn it is
    }
}