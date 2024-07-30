#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to fill the array with random numbers between 1 and 100
void fillArrayWithRandomNo(int arr[], int N) {
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        arr[i] = (rand() % 100) + 1;
    }
}

// Function to sort the array using Bubble Sort algorithm
void bubbleSort(int list[], int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (list[j] > list[j + 1]) {
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

// Function to print the array
void printArray(int arr[], int N) {
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int N;
    printf("Enter the number of elements: ");
    scanf("%d", &N);

    int *arr = (int *)malloc(N * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    fillArrayWithRandomNo(arr, N);
    printf("Original array:\n");
    printArray(arr, N);

    bubbleSort(arr, N);
    printf("Sorted array:\n");
    printArray(arr, N);

    free(arr);
    return 0;
}