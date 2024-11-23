#include <iostream>
using namespace std;

// Function prototypes
string choosePlayer();
void printMatrix(char matrix[3][3]);
bool isWinner(char matrix[3][3], char player);
bool isBoardFull(char matrix[3][3]);

int main() {
    // Variables
    string p1, p2;
    bool isWin = false;

    // Matrix
    char matrix[3][3] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}
    };

    // Choose player
    p1 = choosePlayer();
    p2 = choosePlayer();

    // Game loop
    char currentPlayerMark;
    int turn = 0;

    do {
        // Print matrix
        printMatrix(matrix);

        // Determine current player
        currentPlayerMark = (turn % 2 == 0) ? 'X' : 'O';
        string currentPlayer = (turn % 2 == 0) ? p1 : p2;
        
        // Player's turn
        cout << "\n" << currentPlayer << "'s turn" << endl;
        int row, col;

        // Input row and column
        while (true) {
            cout << "Row (0-2): ";
            cin >> row;
            cout << "Column (0-2): ";
            cin >> col;

            if (row >= 0 && row < 3 && col >= 0 && col < 3 && matrix[row][col] == '-') {
                break; 
            } else {
                cout << "Invalid input. Please try again." << endl; // Invalid input
            }
        }

        // Update matrix
        matrix[row][col] = currentPlayerMark;
        isWin = isWinner(matrix, currentPlayerMark);
        turn++;

    } while (!isWin && !isBoardFull(matrix));

    printMatrix(matrix);
    
    // Print result
    if (isWin) {
        cout << "Congratulations, " << ((turn - 1) % 2 == 0 ? p1 : p2) << "! You win!" << endl; // The winner is the previous player
    } else {
        cout << "It's a draw!" << endl;
    }

    return 0;
}

// Choose player
string choosePlayer() {
    string player;
    cout << "Player: ";
    cin >> player;
    return player;
}

// Print matrix
void printMatrix(char matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

//Check if the player wins
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

// Check if the board is full
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