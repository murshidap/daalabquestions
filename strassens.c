#include <stdio.h>
#define MAX 4

void add(int A[][MAX], int B[][MAX], int C[][MAX], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    }
}

void subtract(int A[][MAX], int B[][MAX], int C[][MAX], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    }
}

void strassen(int A[][MAX], int B[][MAX], int C[][MAX], int n)
{
    int i, j;
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    int k = n / 2;
    int A11[MAX][MAX], A12[MAX][MAX], A21[MAX][MAX], A22[MAX][MAX];
    int B11[MAX][MAX], B12[MAX][MAX], B21[MAX][MAX], B22[MAX][MAX];
    int M1[MAX][MAX], M2[MAX][MAX], M3[MAX][MAX], M4[MAX][MAX], M5[MAX][MAX], M6[MAX][MAX], M7[MAX][MAX];
    int T1[MAX][MAX], T2[MAX][MAX];

    for (i = 0; i < k; i++)
    {
        for (j = 0; j < k; j++)
        {
            A11[i][j] = A[i][j]; A12[i][j] = A[i][j + k]; A21[i][j] = A[i + k][j]; A22[i][j] = A[i + k][j + k];
            B11[i][j] = B[i][j]; B12[i][j] = B[i][j + k]; B21[i][j] = B[i + k][j]; B22[i][j] = B[i + k][j + k];
        }
    }
    add(A11, A22, T1, k); add(B11, B22, T2, k); strassen(T1, T2, M1, k);
    add(A21, A22, T1, k); strassen(T1, B11, M2, k);
    subtract(B12, B22, T2, k); strassen(A11, T2, M3, k);
    subtract(B21, B11, T2, k); strassen(A22, T2, M4, k);
    add(A11, A12, T1, k); strassen(T1, B22, M5, k);
    subtract(A21, A11, T1, k); add(B11, B12, T2, k); strassen(T1, T2, M6, k);
    subtract(A12, A22, T1, k); add(B21, B22, T2, k); strassen(T1, T2, M7, k);
    add(M1, M4, T1, k); subtract(T1, M5, T2, k); add(T2, M7, T1, k);

    for (i = 0; i < k; i++)
    {
        for (j = 0; j < k; j++)
            C[i][j] = T1[i][j];
    }

    add(M3, M5, T1, k);
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < k; j++)
            C[i][j + k] = T1[i][j];
    }

    add(M2, M4, T1, k);
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < k; j++)
            C[i + k][j] = T1[i][j];
    }

    subtract(M1, M2, T1, k);
    add(T1, M3, T2, k);
    add(T2, M6, T1, k);
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < k; j++)
            C[i + k][j + k] = T1[i][j];
    }
}

void display(int A[][MAX], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d\t", A[i][j]);
        printf("\n");
    }
}

int main()
{
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int i, j;
    printf("Enter elements of Matrix A (4x4):\n");
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
            scanf("%d", &A[i][j]);
    }
    printf("Enter elements of Matrix B (4x4):\n");
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
            scanf("%d", &B[i][j]);
    }
    strassen(A, B, C, MAX);
    printf("\nResult Matrix (A x B):\n");
    display(C, MAX);
    return 0;
}
