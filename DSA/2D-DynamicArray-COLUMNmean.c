#include <stdio.h>
#include <stdlib.h>

int **create(int m, int n)
{
    int **temp = (int **)malloc(sizeof(int *) * m);
    for (int i = 0; i < m; i++)
        temp[i] = (int *)malloc(sizeof(int) * n);
    printf("enter numbers \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &temp[i][j]);
        }
    }
    return temp;
}

void findmean(int **mat, int m, int n)
{
    float sum;
    for (int i = 0; i < m; i++)
    {
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += mat[j][i];
        }
        sum = sum / m;
        printf("%f\n", sum);
    }
}

int main()
{
    int m, n;
    printf("Enter rows and columns \n");
    scanf("%d%d", &m, &n);
    int **mat = create(m, n);
    findmean(mat, m, n);
}