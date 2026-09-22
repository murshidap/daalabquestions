#include <stdio.h>
#include <stdlib.h>

int safe(int board[], int row, int column) {
    int previous;

    for (previous = 0; previous < row; previous++)
        if (board[previous] == column ||
            abs(board[previous] - column) == row - previous)
            return 0;
    return 1;
}

int solve(int board[], int row, int n) {
    int column;

    if (row == n) return 1;
    for (column = 0; column < n; column++) {
        if (safe(board, row, column)) {
            board[row] = column;
            if (solve(board, row + 1, n)) return 1;
        }
    }
    return 0;
}

int main(void) {
    int n, row, column;

    printf("Enter number of queens: ");
    scanf("%d", &n);
    if (n < 1) {
        printf("Number of queens must be positive.\n");
        return 1;
    }

    int board[n];
    if (!solve(board, 0, n)) {
        printf("No solution exists.\n");
        return 0;
    }

    printf("\nSolution:\n");
    for (row = 0; row < n; row++) {
        for (column = 0; column < n; column++)
            printf(board[row] == column ? "Q " : ". ");
        printf("\n");
    }
    return 0;
}