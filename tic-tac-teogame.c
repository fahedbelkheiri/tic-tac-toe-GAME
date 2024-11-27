#include <stdio.h>
#include <stdbool.h>

void printBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

bool checkWinner(char board[3][3], char *winner) {
 
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            *winner = board[i][0];
            return true;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            *winner = board[0][i];
            return true;
        }
    }
    
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        *winner = board[0][0];
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        *winner = board[0][2];
        return true;
    }
    return false;
}

bool isDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return false;
    return true;
}

void playGame() {
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char players[2] = {'X', 'O'};
    int turn = 0;
    char winner;

    printf("Welcome to Tic-Tac-Toe!\n");
    printBoard(board);

    while (true) {
        int row, col;
        printf("Player %d's turn (%c): Enter row and column (0-2, space-separated): ", turn % 2 + 1, players[turn % 2]);
        if (scanf("%d %d", &row, &col) != 2 || row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Invalid input or cell already taken. Try again.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

       
        board[row][col] = players[turn % 2];
        printBoard(board);

        
        if (checkWinner(board, &winner)) {
            printf("Player %d (%c) wins!\n", turn % 2 + 1, winner);
            break;
        }
        if (isDraw(board)) {
            printf("It's a draw!\n");
            break;
        }

        turn++;
    }
}

int main() {
    playGame();
    return 0;
}
