#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "input.h"

#define GAME_IN_PROGRESS 0
#define GAME_END_TIE 1
#define GAME_END_WON_O 2
#define GAME_END_WON_X 3

void initializeBoard(char board[3][3]);
void printBoard(char board[3][3]);
int checkGameEnd(char board[3][3]);
bool makeMove(char board[3][3], int row, int col, char player);
char switchPlayer(char currentPlayer);

int main() {
    char board[3][3];
    char currentPlayer = 'O';

    // Initialize the board
    initializeBoard(board);

    // Game loop
    while (!checkGameEnd(board)) {
        printBoard(board);

        int row, col;
        do {
            // Switch to the next player
            currentPlayer = switchPlayer(currentPlayer);

            printf("--- Player %c, enter your move --- \n", currentPlayer);
        
            do {
                printf("Row [0-2]? = ");
            } while(!readInteger(&row));

            do {
                printf("Col [0-2]? = ");
            } while(!readInteger(&col));
            
            // Make a valid move
        } while(!makeMove(board, row, col, currentPlayer));        
    }

    // Print the final board
    printBoard(board);

    // TODO: Print game result (who won or if it's a draw)

    return 0;
}

// Function to initialize the Tic-Tac-Toe board
void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

// Function to print the Tic-Tac-Toe board
void printBoard(char board[3][3]) {
    // TODO: Implement board printing
}

// Function to check if the game has ended
int checkGameEnd(char board[3][3]) {
    // TODO: Implement game end checking
	// Should return one of the constant values that indicate
	// the game state, i.e., GAME_IN_PROGRESS
    return GAME_IN_PROGRESS;
}

// Function to make a move on the Tic-Tac-Toe board
bool makeMove(char board[3][3], int row, int col, char player) {
    if (board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    } 
    
    printf("Invalid move. Cell already taken. Try again.\n");
    return false;
}

// Function to switch players (X to O and vice versa)
char switchPlayer(char currentPlayer) {
    return (currentPlayer == 'X') ? 'O' : 'X';
}