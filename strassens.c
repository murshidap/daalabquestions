#include <stdio.h>

int main()
{
    int a[4][4], b[4][4], c[4][4];
    int m1[2][2], m2[2][2], m3[2][2], m4[2][2];
    int m5[2][2], m6[2][2], m7[2][2];
    int p[2][2], q[2][2], r[2][2], s[2][2];
    int i, j, k;

    printf("Enter elements of matrix A:\n");
    for(i = 0; i < 4; i++)
        for(j = 0; j < 4; j++)
            scanf("%d", &a[i][j]);

    printf("Enter elements of matrix B:\n");
    for(i = 0; i < 4; i++)
        for(j = 0; j < 4; j++)
            scanf("%d", &b[i][j]);

    /* Strassen's algorithm using 2x2 submatrices */
    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            m1[i][j] = (a[i][j] + a[i+2][j+2]) *
                       (b[i][j] + b[i+2][j+2]);

            m2[i][j] = (a[i+2][j] + a[i+2][j+2]) * b[i][j];

            m3[i][j] = a[i][j] * (b[i][j+2] - b[i+2][j+2]);

            m4[i][j] = a[i+2][j+2] * (b[i+2][j] - b[i][j]);

            m5[i][j] = (a[i][j] + a[i][j+2]) * b[i+2][j+2];

            m6[i][j] = (a[i+2][j] - a[i][j]) *
                       (b[i][j] + b[i][j+2]);

            m7[i][j] = (a[i][j+2] - a[i+2][j+2]) *
                       (b[i+2][j] + b[i+2][j+2]);
        }
    }

    /* Calculate the result matrix */
    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            c[i][j] = m1[i][j] + m4[i][j] -
                      m5[i][j] + m7[i][j];

            c[i][j+2] = m3[i][j] + m5[i][j];

            c[i+2][j] = m2[i][j] + m4[i][j];

            c[i+2][j+2] = m1[i][j] - m2[i][j] +
                          m3[i][j] + m6[i][j];
        }
    }

    printf("Result matrix:\n");
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
            printf("%d ", c[i][j]);

        printf("\n");
    }

    return 0;
}