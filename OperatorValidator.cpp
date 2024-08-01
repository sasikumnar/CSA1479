#include <stdio.h>
#include <ctype.h>
int isArithmeticOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}
void lexicalAnalyzer(FILE *fp) {
    char c;
    while ((c = fgetc(fp)) != EOF) {
        if (isspace(c)) {
            continue;
        }

        if (isArithmeticOperator(c)) {
            printf("Operator: %c\n", c);
        } else {
 
        }
    }
}
int main() {
    FILE *fp = stdin;
    printf("Enter the source code (Ctrl+D to end):\n");
    lexicalAnalyzer(fp);
    return 0;
}
