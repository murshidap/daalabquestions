#include <stdio.h>
#include <stdlib.h>

int board[20], n;

int safe(int row, int col)
{
    int i;

    for(i = 0; i < row; i++)
    {
        if(board[i] == col ||
           abs(board[i] - col) == abs(i - row))
            return 0;
    }

    return 1;
}

int solve(int row)
{
    int col;

    if(row == n)
        return 1;

    for(col = 0; col < n; col++)
    {
        if(safe(row, col))
        {
            board[row] = col;

            if(solve(row + 1))
                return 1;
        }
    }

    return 0;
}

int main()
{
    int i, j;

    printf("Enter N (maximum 20): ");
    scanf("%d", &n);

    if(n < 1 || n > 20)
    {
        printf("Invalid N");
        return 0;
    }

    if(solve(0))
    {
        printf("Solution:\n");

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(board[i] == j)
                    printf("Q ");
                else
                    printf(". ");
            }

            printf("\n");
        }
    }
    else
        printf("No solution exists\n");

    return 0;
}