#include <stdio.h>
#include <stdlib.h>

void wordCount(FILE *file);

int main() {
    char filename[100];

    printf("Enter the name of the text file: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file. Make sure the file exists and is accessible.\n");
        return 1;
    }

    wordCount(file);

    fclose(file);

    return 0;
}

void wordCount(FILE *file) {
    int charCount = 0, wordCount = 0, lineCount = 0;
    int inWord = 0;  // Flag to track if currently in a word
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        if (ch != '\n' && ch != '\r') {
            charCount++;
        }

        if (ch == '\n' || ch == '\r') {
            lineCount++;
        }

        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r') {
            inWord = 0;
        } else {
            if (!inWord) {
                inWord = 1;
                wordCount++;
            }
        }
    }

    if (charCount > 0) {
        lineCount++;
    }

    printf("Number of characters: %d\n", charCount);
    printf("Number of words: %d\n", wordCount);
    printf("Number of lines: %d\n", lineCount);
}
