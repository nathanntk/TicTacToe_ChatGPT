// this game was created with the help of chatGPT 

#include <iostream>
#include <limits>
#include <cstdlib>

using namespace std;

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char current_player = 'X';

void drawBoard(char board[][3])
{
    system("clear"); //Clear the console
    cout << " Tic Tac Toe Game" << endl;
    cout << " Player 1 (X)  -  Player 2 (O)" << endl;
    cout << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
    cout << "     |     |     " << endl;
    cout << endl;
}

bool check_move(char board[][3], int row, int col)
{
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        return false;
    }

    if (board[row][col] != ' ') {
        return false;
    }

    return true;
}

void getPlayerChoice()
{
    int choice;
    bool valid_choice = false;
    
    while (!valid_choice) {
        cout << "Player " << current_player << ", enter a number (1-9): ";
        cin >> choice;

        // Check for input failure
        if (cin.fail()) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (check_move(board, row, col)) {
            board[row][col] = current_player;
            valid_choice = true;
        } else {
            cout << "Invalid move. Please try again." << endl;
        }
    }
}



bool isGameOver()
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return true;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return true;
    }

    // Check if the game is a tie
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
            {
                return false;
            }
        }
    }

    return true;
}


void switch_player(char& current_player)
{
    if (current_player == 'X')
    {
        current_player = 'O';
	}
	else {
		current_player = 'X';
	}
}

bool make_move(char board[][3], char player, int row, int col) {
    // Check if the move is valid
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        return false;
    }

    if (board[row][col] != ' ') {
        return false;
    }

    // Make the move
    board[row][col] = player;

    return true;
}

bool check_win(char board[][3], char player) {
    // Check rows for a win
    for (int row = 0; row < 3; row++) {
        if (board[row][0] == player && board[row][1] == player && board[row][2] == player) {
            return true;
        }
    }

    // Check columns for a win
    for (int col = 0; col < 3; col++) {
        if (board[0][col] == player && board[1][col] == player && board[2][col] == player) {
            return true;
        }
    }

    // Check diagonals for a win
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    // No win found
    return false;
}



int main() {
    // Declare and initialize game variables
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char current_player = 'X';
    int row, col;

    // Display instructions
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    cout << "Player 1: X" << endl;
    cout << "Player 2: O" << endl;
    cout << "To make a move, enter the row and column numbers (0-2) separated by a space." << endl;

    // Main game loop
    while (true) {
        // Draw the board
        drawBoard(board);

        // Prompt the current player for their move
        cout << "Player " << current_player << ", enter your move: ";
        cin >> row >> col;

        // Make the move
        if (make_move(board, current_player, row, col)) {
            // Check for a win
            if (check_win(board, current_player)) {
                cout << "Player " << current_player << " wins!" << endl;
                break;
            }

            // Switch to the other player's turn
            switch_player(current_player);
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }

    return 0;
}

	
