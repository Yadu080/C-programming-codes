#include <stdio.h>
#include <string.h>

int myInsertString(char *receiver, const char *insertion, int position) {
    int receiverLength = strlen(receiver);
    int insertionLength = strlen(insertion);

    // Check if position is valid
    if (position < 0 || position > receiverLength) {
        return 0;
    }

    // Shift elements to the right to make space for insertion
    for (int i = receiverLength; i >= position; i--) {
        receiver[i + insertionLength] = receiver[i];
    }

    // Insert the insertion string into the receiver string
    for (int i = 0; i < insertionLength; i++) {
        receiver[position + i] = insertion[i];
    }

    return 1; // Successful insertion
}

int main() {
    char receiver[100];
    char insertion[100];
    int position;

    printf("Enter the receiving string: ");
    scanf("%s", receiver);

    printf("Enter the string to be inserted: ");
    scanf("%s", insertion);

    printf("Enter the insertion position: ");
    scanf("%d", &position);

    if (myInsertString(receiver, insertion, position)) {
        printf("After insertion: %s\n", receiver);
    } else {
        printf("Invalid insertion position!\n");
    }

    return 0;
}