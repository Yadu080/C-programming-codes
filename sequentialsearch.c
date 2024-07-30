#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_VALUE 100
#define MIN_VALUE 1

// Function prototypes
void fillArrayWithRandomNumbers(int array[], int size);
bool sequentialSearch(int array[], int size, int target, int *location, int *tests);

int main() {
    int arraySize, target, tests, location;
    int successfulSearches = 0, totalTests = 0;

    // Prompt user for array size
    printf("Enter the number of integers: ");
    if (scanf("%d", &arraySize) != 1) {
        fprintf(stderr, "Invalid input for array size.\n");
        return 1;
    }

    // Validate array size
    if (arraySize <= 0) {
        fprintf(stderr, "Array size must be a positive integer.\n");
        return 1;
    }

    // Seed random number generator
    srand(time(NULL));

    // Allocate memory for array
    int *array = (int *)malloc(arraySize * sizeof(int));
    if (array == NULL) {
        perror("Memory allocation failed");
        return 1;
    }

    // Fill array with random numbers
    fillArrayWithRandomNumbers(array, arraySize);

    // Perform searches
    for (int i = 0; i < arraySize; i++) {
        target = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
        printf("Target of search %d: %d\n", i, target);

        if (sequentialSearch(array, arraySize, target, &location, &tests)) {
            successfulSearches++;
            printf("Found at index %d\n", location);
        }
        totalTests += tests;
    }

    // Print search statistics
    printf("Number of searches: %d\n", arraySize);
    printf("Successful searches: %d\n", successfulSearches);
    printf("Success percentage: %.2f%%\n", (successfulSearches / (double)arraySize) * 100);
    printf("Average tests per search: %.2f\n", totalTests / (double)arraySize);

    // Free allocated memory
    free(array);

    return 0;
}

void fillArrayWithRandomNumbers(int array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
        printf("%d\n", array[i]);
    }
}

bool sequentialSearch(int array[], int size, int target, int *location, int *tests) {
    *tests = 0;
    for (int i = 0; i < size; i++) {
        (*tests)++;
        if (array[i] == target) {
            *location = i;
            return true;
        }
    }
    *location = -1;
    return false;
}