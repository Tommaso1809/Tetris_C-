/**
 * The above C++ program implements a simple tic-tac-toe game where players can input their names, take
 * turns to play, and determine the winner or a draw based on the game rules.
 * 
 * @return The program returns 0 at the end of the `main()` function, which indicates successful
 * execution of the program.
 */

// Include necessary libraries
#include <iostream>
using namespace std;


/* These lines are function declarations in C++: */
string choosePlayer();
void printMatrix(char matrix[3][3]);
bool isWinner(char matrix[3][3], char player);
bool isBoardFull(char matrix[3][3]);

int main() {
    string p1, p2;
    bool isWin = false;


    char matrix[3][3] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}
    };

    
    p1 = choosePlayer();
    p2 = choosePlayer();

    char currentPlayerMark;
    int turn = 0;

    /* This part of the code snippet is the main game loop in the Tic-Tac-Toe game implementation.
    Here's a breakdown of what it does: */
    do {
        printMatrix(matrix);

        currentPlayerMark = (turn % 2 == 0) ? 'X' : 'O';
        string currentPlayer = (turn % 2 == 0) ? p1 : p2;
        
        cout << "\n" << currentPlayer << "'s turn" << endl;
        int row, col;

        /* This code snippet is responsible for taking input from the player for the row and column
        they want to place their mark (X or O) in the tic-tac-toe game. Here's a breakdown of what
        it does: */
        while (true) {
            cout << "Row (0-2): ";
            cin >> row;
            cout << "Column (0-2): ";
            cin >> col;

            if (row >= 0 && row < 3 && col >= 0 && col < 3 && matrix[row][col] == '-') {
                break; 
            } else {
                cout << "Invalid input. Please try again." << endl;  
            }
        }

        matrix[row][col] = currentPlayerMark;
        isWin = isWinner(matrix, currentPlayerMark);
        turn++;

    } while (!isWin && !isBoardFull(matrix));

    printMatrix(matrix);
    
    /* This part of the code is responsible for displaying the final outcome of the tic-tac-toe game. */
    if (isWin) {
        cout << "Congratulations, " << ((turn - 1) % 2 == 0 ? p1 : p2) << "! You win!" << endl; 
    } else {
        cout << "It's a draw!" << endl;
    }

    return 0;
}

/**
 * The function "choosePlayer" prompts the user to enter a player name and returns the input as a
 * string.
 * 
 * @return The function `choosePlayer()` returns a string value, which is the player input entered by
 * the user.
 */
string choosePlayer() {
    string player;
    cout << "Player: ";
    cin >> player;
    return player;
}

/**
 * The function `printMatrix` prints a 3x3 matrix of characters to the console.
 * 
 * @param matrix The `printMatrix` function takes a 3x3 matrix of characters as input. It iterates over
 * the rows and columns of the matrix and prints each element followed by a tab character ("\t"). After
 * printing all elements in a row, it moves to the next line using `cout << endl
 */
void printMatrix(char matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

/**
 * The function checks if a player has won in a Tic-Tac-Toe game based on the current state of the game
 * board.
 * 
 * @param matrix A 3x3 matrix representing a tic-tac-toe board where each cell can contain either 'X',
 * 'O', or any other character.
 * @param player The `isWinner` function checks if a player has won in a Tic-Tac-Toe game represented
 * by a 3x3 matrix. The function takes two parameters:
 * 
 * @return The function `isWinner` returns a boolean value - `true` if the player has won based on the
 * current state of the tic-tac-toe `matrix`, and `false` otherwise.
 */
bool isWinner(char matrix[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if ((matrix[i][0] == player && matrix[i][1] == player && matrix[i][2] == player) ||
            (matrix[0][i] == player && matrix[1][i] == player && matrix[2][ i] == player)) {
            return true;
        }
    }
    if ((matrix[0][0] == player && matrix[1][1] == player && matrix[2][2] == player) ||
        (matrix[0][2] == player && matrix[1][1] == player && matrix[2][0] == player)) {
        return true;
    }
    return false;
}

/**
 * The function `isBoardFull` checks if a 3x3 board represented by a matrix is completely filled with
 * characters other than '-' and returns true if it is full.
 * 
 * @param matrix The `matrix` parameter is a 3x3 2D array of characters representing the game board.
 * Each element in the matrix can have one of the following values:
 * 
 * @return The function `isBoardFull` returns a boolean value - `true` if the board is full (i.e., all
 * positions are filled), and `false` if there is at least one empty position represented by the
 * character '-'.
 */
bool isBoardFull(char matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] == '-') {
                return false; 
            }
        }
    }
    return true; 
}