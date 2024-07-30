#include <stdio.h>

// Function to print Pascal's Triangle
void printPascal(int n) {
    for (int line = 0; line < n; line++) {
        // Print leading spaces for alignment
        for (int space = 0; space < n - line - 1; space++)
            printf("  ");

        int c = 1; // Initialize the first value in a line to 1

        // Print each value in the current line
        for (int i = 0; i <= line; i++) {
            printf("%4d", c); // Print the current value
            
            // Calculate the next value using binomial coefficient formula
            c = c * (line - i) / (i + 1);
        }
        
        printf("\n"); // Move to the next line
    }
}

int main() {
    int n;
    printf("Enter the number of rows to display the triangle: ");
    scanf("%d", &n); // Read number of rows
    printPascal(n);  // Generate Pascal's Triangle
    return 0;
}