#include <stdio.h>
#include <stdlib.h>

#define COLUMNS 4
#define ROWS 5

int main() {
    int arr[ROWS][COLUMNS];

    // Filling the array with random numbers from 0 to 98
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            arr[i][j] = rand() % 99;
        }
    }

    // Displaying the array
    printf("Array:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%2d  ", arr[i][j]);
        }
        printf("\n");
    }

    // Calculating and displaying the average of each row
    printf("\nAverage of rows:\n");
    for (int i = 0; i < ROWS; i++) {
        int sum = 0;
        for (int j = 0; j < COLUMNS; j++) {
            sum += arr[i][j];
        }
        printf("Row %d = %d\n", i + 1, sum / COLUMNS);
    }

    // Calculating and displaying the average of each column
    printf("\nAverage of columns:\n");
    for (int i = 0; i < COLUMNS; i++) {
        int sum = 0;
        for (int j = 0; j < ROWS; j++) {
            sum += arr[j][i];
        }
        printf("Column %d = %d\n", i + 1, sum / ROWS);
    }

    return 0;
}