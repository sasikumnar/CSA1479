#include <stdio.h>
#include <ctype.h>
void countWhitespacesAndNewlines(FILE *fp) {
    char c;
    int whitespaceCount = 0;
    int newlineCount = 0;
    while ((c = fgetc(fp)) != EOF) {     
        if (isspace(c) && c != '\n') {
            whitespaceCount++;
        }      
        if (c == '\n') {
            newlineCount++;
        }
    }
    printf("Number of whitespace characters (excluding newlines): %d\n", whitespaceCount);
    printf("Number of newline characters: %d\n", newlineCount);
}
int main(int argc, char *argv[]) {
    FILE *fp; 
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }
    countWhitespacesAndNewlines(fp);
    fclose(fp);
    return 0;
}