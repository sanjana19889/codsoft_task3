#include <iostream>
using namespace std;

void displayBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    
    return false;
}

bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char curr = 'X';
    bool gameWon = false;
    
    cout << "Tic-Tac-Toe Game" << endl;
    
    while (!gameWon) {
        displayBoard(board);
        
        int row, col;
        cout << "Player " << curr << ", enter your move (row and column): ";
        cin >> row >> col;
        
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = curr;
            
            if (checkWin(board, curr)) {
                displayBoard(board);
                cout << "Player " << curr << " wins!" << endl;
                gameWon = true;
            } else if (checkDraw(board)) {
                displayBoard(board);
                cout << "It's a draw!" << endl;
                gameWon = true;
            } else {
                curr = (curr == 'X') ? 'O' : 'X';
            }
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }
    
    char playAgain;
    cout << "Play again? (Y/N): ";
    cin >> playAgain;
    
    if (playAgain == 'Y' || playAgain == 'y') {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }
        curr = 'X';
        gameWon = false;
    } else {
        cout << "Thanks for playing!" << endl;
    }
    
    return 0;
}