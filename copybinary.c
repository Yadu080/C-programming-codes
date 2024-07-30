#include<stdio.h>

int copy(FILE *s, FILE *d) {
    int n;
    while (fread(&n, sizeof(int), 1, s) == 1) {
        if (fwrite(&n, sizeof(int), 1, d) != 1) {
            return 0; // error writing to destination file
        }
    }
    return 1;
}

int main() {
    FILE *s;
    FILE *d;
    char sf[100], df[100];
    printf("Enter the source and destination file: ");
    scanf("%s %s", sf, df);
    s = fopen(sf, "r");
    if (s == NULL) {
        printf("Error opening source file\n");
        return 1;
    }
    d = fopen(df, "w");
    if (d == NULL) {
        printf("Error opening destination file\n");
        fclose(s);
        return 1;
    }
    if (copy(s, d)) {
        printf("Text transferred\n");
    } else {
        printf("Error transferring text\n");
    }
    fclose(s);
    fclose(d);


    return 0;
}