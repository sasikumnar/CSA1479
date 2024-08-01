#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_INPUT_SIZE 100
char input[MAX_INPUT_SIZE];
int position = 0;
void parseE();
void parseEPrime();
void parseT();
void parseTPrime();
void parseF();
void match(char expected);
void parseE() {
    parseT();
    parseEPrime();
}
void parseEPrime() {
    if (input[position] == '+') {
        match('+');
        parseT();
        parseEPrime();
    }
}
void parseT() {
    parseF();
    parseTPrime();
}
void parseTPrime() {
    if (input[position] == '*') {
        match('*');
        parseF();
        parseTPrime();
    }
}
void parseF() {
    if (input[position] == '(') {
        match('(');
        parseE();
        match(')');
    } else if (isalpha(input[position])) {
        match(input[position]);
    } else {
        printf("Syntax error: Expected identifier or '('\n");
    }
}
void match(char expected) {
    if (input[position] == expected) {
        position++;
    } else {
        printf("Syntax error: Expected '%c' but found '%c'\n", expected, input[position]);     
    }
}
void parse() {
    parseE();
    if (input[position] != '\0') {
        printf("Syntax error: Unexpected character '%c'\n", input[position]);  
    }
    printf("Input is valid.\n");
}
int main() {
    printf("Enter an arithmetic expression (use single alphabet characters for identifiers): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    if (strlen(input) == 0) {
        printf("Error: Empty input.\n");
        return 1;
    }
    parse();
    return 0;
}