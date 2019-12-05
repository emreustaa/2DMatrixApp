/*
@file bp3proje
@description matris operasyonları command prompt'tan girilen değerler ile sağlanmıştır. matrixOperations, createMatrix ve showMenu olmak üzere 3 adet fonksiyon tanımlanmıştır
matrixOperations fonksiyonun içerisinde matris oluşturma, verilen yöne göre döndürme işlemi yapılmıştır. createMatrix fonksiyonunda kullanıcı tarafından alınan verilerle yeni matris oluşturulması sağlanmıştır. showMenu fonksiyonunda program içerisinde kullanıcıya gösterilecek menu tanımlanmıştır.

@assignment BLM204 - Bilgisayar Programlama 3 Proje
@date Kod son güncelleme tarihi : 02/12/2019
@author Emre USTA - emreustaa34@gmail.com

*/

#include "matrixOps.h"

void matrixOperations(int rowCount, int columnCount, int direction, int range, int step)
{
    srand(time(NULL));

    if (rowCount == 0 || columnCount == 0 || range == 0)
    {
        printf("Any value mustn't be 0.\n");
    }
    else
    {
        int i, j;

        int **myArray = (int **)malloc(rowCount * sizeof(int *));

        for (i = 0; i < rowCount; i++)
        {

            *(myArray + i) = (int *)malloc(columnCount * sizeof(int));
        }

        for (i = 0; i < rowCount; i++)
        {
            for (j = 0; j < columnCount; j++)
            {
                *(*(myArray + i) + j) = 0 + (rand() % range);
            }
        }

        for (i = 0; i < rowCount; i++)
        {
            for (j = 0; j < columnCount; j++)
            {
                printf("%d ", *(*(myArray + i) + j));
            }
            printf("\n");
        }
        printf("\n");

        printf("------------------------------------------------------------------------------------------------------------\n");
        printf("Corner values of myArray : \n");
        printf("%d.satir %d sutun elemani : %d\n", rowCount - (rowCount - 1), columnCount - (columnCount - 1), *(*(myArray + 0) + 0));
        printf("%d.satir %d. sutun elemani : %d\n", rowCount - (rowCount - 1), columnCount, *(*(myArray + 0) + (columnCount - 1)));
        printf("%d.satir %d. sutun elemani : %d\n", rowCount, columnCount - (columnCount - 1), *(*(myArray + (rowCount - 1)) + 0));
        printf("%d.satir %d. sutun elemani : %d\n", rowCount, columnCount, *(*(myArray + (rowCount - 1)) + (columnCount - 1)));
        printf("------------------------------------------------------------------------------------------------------------\n");

        if (direction == -1)
        {

            int m = rowCount, n = columnCount;

            int row = 0, col = 0;
            int prev, curr;

            while (row < m && col < n)
            {

                if (row + 1 == m || col + 1 == n)
                {
                    break;
                }
                prev = *(*(myArray + (row + 1)) + col);

                for (int i = col; i < n; i++)
                {
                    curr = *(*(myArray + row) + i);
                    *(*(myArray + row) + i) = prev;
                    prev = curr;
                }

                row++;

                for (int i = row; i < m; i++)
                {
                    curr = *(*(myArray + i) + (n - 1));
                    *(*(myArray + i) + (n - 1)) = prev;
                    prev = curr;
                }
                n--;

                if (row < m)
                {

                    for (int i = n - 1; i >= col; i--)
                    {
                        curr = *(*(myArray + (m - 1)) + i);
                        *(*(myArray + (m - 1)) + i) = prev;
                        prev = curr;
                    }
                }
                m--;

                if (col < n)
                {
                    for (int i = m - 1; i >= row; i--)
                    {
                        curr = *(*(myArray + i) + col);
                        *(*(myArray + i) + col) = prev;
                        prev = curr;
                    }
                }
                col++;
            }

            for (i = 0; i < rowCount; i++)
            {
                for (j = 0; j < columnCount; j++)
                {
                    printf("%d ", *(*(myArray + i) + j));
                }
                printf("\n");
            }

            printf("------------------------------------------------------------------------------------------------------------\n");
        }

        else if (direction == 1)
        {

            for (int x = 0; x < columnCount / 2; x++)
            {
                for (int y = x; y < columnCount - x - 1; y++)
                {

                    int temp = *(*(myArray + x) + y);

                    *(*(myArray + x) + y) = *(*(myArray + y) + (columnCount - 1 - x));

                    *(*(myArray + y) + (columnCount - 1 - x)) = *(*(myArray + (columnCount - 1 - x)) + (columnCount - 1 - y));

                    *(*(myArray + (columnCount - 1 - x)) + (columnCount - 1 - y)) = *(*(myArray + (columnCount - 1 - y)) + x);

                    *(*(myArray + (columnCount - 1 - y)) + x) = temp;
                }
            }
            for (i = 0; i < rowCount; i++)
            {
                for (j = 0; j < columnCount; j++)
                {
                    printf("%d ", *(*(myArray + i) + j));
                }
                printf("\n");
            }
        }

        printf("------------------------------------------------------------------------------------------------------------\n");

        free(myArray);
    }
}

void createMatrix(int rCount, int cCount, int rangeMat)
{

    int i, j;

    int **secondArray = (int **)malloc(rCount * sizeof(int *));

    for (i = 0; i < rCount; i++)
    {

        *(secondArray + i) = (int *)malloc(cCount * sizeof(int));
    }

    for (i = 0; i < rCount; i++)
    {
        for (j = 0; j < cCount; j++)
        {
            *(*(secondArray + i) + j) = 0 + (rand() % rangeMat);
        }
    }

    for (i = 0; i < rCount; i++)
    {
        for (j = 0; j < cCount; j++)
        {
            printf("%d ", *(*(secondArray + i) + j));
        }
        printf("\n");
    }

    free(secondArray);
}

void showMenu()
{

    printf("Menu\n");
    printf("--------\n");
    printf("1- Run App\n");
    printf("2- Crete Matrix\n");
    printf("3- Enter the Direction\n");
    printf("4- Enter the step number\n");
    printf("5- Exit\n");
}
