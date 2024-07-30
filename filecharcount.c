#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *file;
    char filename[100];
    char ch;
    int alphaCount = 0, punctCount = 0, spaceCount = 0;

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        if (isalpha(ch)) {
            alphaCount++;
        } else if (ispunct(ch)) {
            punctCount++;
        } else if (isspace(ch)) {
            spaceCount++;
        }
    }

    fclose(file);

    printf("\nReport:\n");
    printf("Alphabetic characters: %d\n", alphaCount);
    printf("Punctuation characters: %d\n", punctCount);
    printf("White space characters: %d\n", spaceCount);

    return 0;
}