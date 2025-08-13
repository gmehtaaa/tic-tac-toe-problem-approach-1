#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int BOARD_SIZE = 9;
const int MOVETABLE_SIZE = 19683; // 3^9

// Convert board vector to decimal index (base-3)
int boardToIndex(const vector<int>& board) {
    int index = 0;
    int power = 1;
    for (int i = 0; i < BOARD_SIZE; i++) {
        index += board[i] * power;
        power *= 3;
    }
    return index;
}

// Print the board
void printBoard(const vector<int>& board) {
    cout << "\n";
    for (int i = 0; i < BOARD_SIZE; i++) {
        char c = (board[i] == 0 ? '.' : (board[i] == 1 ? 'X' : 'O'));
        cout << c << " ";
        if ((i + 1) % 3 == 0) cout << "\n";
    }
    cout << "\n";
}

// Check if someone has won
int checkWinner(const vector<int>& board) {
    int wins[8][3] = {
        {0,1,2},{3,4,5},{6,7,8}, // rows
        {0,3,6},{1,4,7},{2,5,8}, // cols
        {0,4,8},{2,4,6}          // diagonals
    };
    for (auto &w : wins) {
        if (board[w[0]] != 0 &&
            board[w[0]] == board[w[1]] &&
            board[w[1]] == board[w[2]])
            return board[w[0]];
    }
    return 0; // no winner
}

// Check if board is full
bool isFull(const vector<int>& board) {
    for (int cell : board) if (cell == 0) return false;
    return true;
}

// Generate move table: computer plays O in first empty cell
void generateMoveTable(vector<vector<int>>& movetable) {
    for (int i = 0; i < MOVETABLE_SIZE; i++) {
        vector<int> board(BOARD_SIZE);
        int temp = i;
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[j] = temp % 3;
            temp /= 3;
        }

        vector<int> nextBoard = board;
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (nextBoard[j] == 0) {
                nextBoard[j] = 2; // O (computer)
                break;
            }
        }
        movetable[i] = nextBoard;
    }
}

int main() {
    vector<int> board(BOARD_SIZE, 0); // Start empty
    vector<vector<int>> movetable(MOVETABLE_SIZE, vector<int>(BOARD_SIZE));

    // Precompute all moves
    generateMoveTable(movetable);

    cout << "Tic Tac Toe (You = X, Computer = O)\n";
    cout << "Board positions are numbered as:\n";
    cout << "1 2 3\n4 5 6\n7 8 9\n";

    while (true) {
        printBoard(board);

        if (checkWinner(board) == 2) {
            cout << "Computer wins!\n";
            break;
        } else if (checkWinner(board) == 1) {
            cout << "You win!\n";
            break;
        } else if (isFull(board)) {
            cout << "It's a draw!\n";
            break;
        }

        // Player move
        int pos;
        cout << "Enter your move (1-9): ";
        cin >> pos;
        while (pos < 1 || pos > 9 || board[pos-1] != 0) {
            cout << "Invalid move. Try again: ";
            cin >> pos;
        }
        board[pos-1] = 1; // X (player)

        // Check win after player move
        if (checkWinner(board) == 1) {
            printBoard(board);
            cout << "You win!\n";
            break;
        } else if (isFull(board)) {
            printBoard(board);
            cout << "It's a draw!\n";
            break;
        }

        // Computer move using movetable
        int index = boardToIndex(board);
        board = movetable[index];
    }

    return 0;
}
