#include <stdio.h>

int main() {
    int a[100], f[100] = {0};
    int n, i, j, ctr;

    // Input the number of elements in the array
    printf("Input the number of elements in the array: ");
    scanf("%d", &n);

    // Input array elements
    printf("Input %d elements in the array:\n", n);
    for (i = 0; i < n; i++) {
        printf("element - %d: ", i);
        scanf("%d", &a[i]);
    }

    // Calculate frequency of each element
    for (i = 0; i < n; i++) {
        if (f[i] != 0) continue; // Skip already counted elements

        ctr = 1; // Initialize counter for the current element
        for (j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                ctr++;     // Increment counter for matching elements
                f[j] = -1; // Mark the element as counted
            }
        }
        f[i] = ctr; // Store frequency of the current element
    }

    // Print the frequency of each element and histogram
    printf("\nFrequency of all elements:\n");
    for (i = 0; i < n; i++) {
        if (f[i] > 0) {
            printf("%d occurs %d times\n", a[i], f[i]);
            printf("%2d %2d ", a[i], f[i]);
            for (j = 0; j < f[i]; j++)
                printf("*");
            printf("\n");
        }
    }

    return 0;
}