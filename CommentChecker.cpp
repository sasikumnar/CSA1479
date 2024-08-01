#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_ID_LENGTH 31
int isOperator(char c) {
    char operators[] = "+-*/=<>!&|";
    return strchr(operators, c) != NULL;
}
int isIdentifierChar(char c) {
    return isalnum(c) || c == '_';
}
void lexicalAnalyzer(FILE *fp) {
    char c;
    char identifier[MAX_ID_LENGTH + 1];
    int id_len = 0;
    int is_comment = 0;
    while ((c = fgetc(fp)) != EOF) {
        if (c == '/') {
            char next_char = fgetc(fp);
            if (next_char == '/') {
                is_comment = 1;
                while ((c = fgetc(fp)) != EOF && c != '\n');
                is_comment = 0;
                continue;
            } else if (next_char == '*') {
                is_comment = 1;
                while ((c = fgetc(fp)) != EOF) {
                    if (c == '*' && (c = fgetc(fp)) == '/') {
                        is_comment = 0;
                        break;
                    }
                }
                if (c == EOF) {
                    fprintf(stderr, "Error: Unclosed multi-line comment\n");
                }
                continue;
            } else {
                ungetc(next_char, fp); 
            }
        }
        if (isspace(c)) {
            continue;
        }
        if (is_comment) {
            continue;
        }
        if (isalpha(c) || c == '_') {
            identifier[id_len++] = c;
            while ((c = fgetc(fp)) != EOF && isIdentifierChar(c)) {
                if (id_len < MAX_ID_LENGTH) {
                    identifier[id_len++] = c;
                }
            }
            identifier[id_len] = '\0';
            printf("Identifier: %s\n", identifier);
            id_len = 0;
            if (c != EOF) {
                ungetc(c, fp);
            }
            continue;
        }
        if (isdigit(c)) {
            char constant[32];
            int i = 0;
            constant[i++] = c;
            while ((c = fgetc(fp)) != EOF && isdigit(c)) {
                if (i < 31) {
                    constant[i++] = c;
                }
            }
            constant[i] = '\0';
            printf("Constant: %s\n", constant);
            if (c != EOF) {
                ungetc(c, fp);
            }
            continue;
        }
        if (isOperator(c)) {
            printf("Operator: %c\n", c);
            continue;
        }
        printf("Unknown character: %c\n", c);
    }
}

int main() {
    FILE *fp = stdin;
    printf("Enter the source code (Ctrl+D to end):\n");
    lexicalAnalyzer(fp);
    return 0;
}
