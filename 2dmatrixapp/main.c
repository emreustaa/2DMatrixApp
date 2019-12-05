/*
@file bp3proje
@description matrixOps.h dosyasından include edilen fonksiyonların test edilmesi işlemleri gerçekleştirilmiştir. Command prompt'tan alınan verilerle matris işlemleri gerçekleştirilmiş olup ardından kullanıcıya açılan menu ile diğer adımların yapılması sağlanmıştır.

@assignment BLM204 - Bilgisayar Programlama 3 Proje
@date Kod son güncelleme tarihi : 02/12/2019
@author Emre USTA - emreustaa34@gmail.com

*/

#include "matrixOps.h"

int main(int argc, char *argv[])
{
    int rowCountFirst, columnCountFirst, directionFirst, rangeFirst, stepFirst;

    rowCountFirst = atoi(argv[1]);
    columnCountFirst = atoi(argv[2]);
    directionFirst = atoi(argv[3]);
    rangeFirst = atoi(argv[4]);
    stepFirst = atoi(argv[5]);

    printf("Values : %d %d %d \n", rowCountFirst, columnCountFirst, directionFirst, rangeFirst, stepFirst);

    matrixOperations(rowCountFirst, columnCountFirst, directionFirst, rangeFirst, stepFirst);

    int rowCountSecond, columnCountSecond, directionSecond, rangeSecond, stepSecond;

    typedef enum
    {
        false = 0,
        true = 1
    } bool;
    bool isExitting = true;

    while (isExitting)
    {

        showMenu();

        printf("Choise a operation from the menu.\n");
        int selected = 0;
        scanf("%d", &selected);

        switch (selected)
        {
        case 1:
            matrixOperations(rowCountSecond, columnCountSecond, directionSecond, rangeSecond, stepSecond);
            break;

        case 2:
            printf("Enter the row count :\n");
            scanf("%d", &rowCountSecond);
            printf("Enter the column count :\n");
            scanf("%d", &columnCountSecond);
            printf("Enter the matrix range :\n");
            scanf("%d", &rangeSecond);
            createMatrix(rowCountSecond, columnCountSecond, rangeSecond);
            break;

        case 3:
            printf("Enter the direction :\n");
            scanf("%d", &directionSecond);
            break;
        case 4:
            printf("Enter step :\n");
            scanf("%d", &stepSecond);
            break;
        case 5:
            isExitting = false;
            break;
        default:
            break;
        }
    }
}
