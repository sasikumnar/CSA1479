#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_RULES 100
#define MAX_SYMBOLS 100
void eliminateLeftRecursion(char nonTerminal, char rules[MAX_RULES][MAX_SYMBOLS], int ruleCount) {
    int i, j;
    char newNonTerminal = nonTerminal + 1; 
    printf("Original rules for %c:\n", nonTerminal);
    for (i = 0; i < ruleCount; i++) {
        printf("%c -> %s\n", nonTerminal, rules[i]);
    }
    printf("Eliminated left recursion rules:\n");
    printf("%c -> ", nonTerminal);
    for (i = 0; i < ruleCount; i++) {
        if (rules[i][0] != nonTerminal) {
            printf("%s%c | ", rules[i], newNonTerminal);
        }
    }
    printf("\n");
    printf("%c -> ", newNonTerminal);
    for (i = 0; i < ruleCount; i++) {
        if (rules[i][0] == nonTerminal) {
            printf("%s%c | ", rules[i] + 1, newNonTerminal);
        }
    }
    printf("e\n");
}
int main() {
    char nonTerminal;
    char rules[MAX_RULES][MAX_SYMBOLS];
    int ruleCount;
    int i;
    printf("Enter the non-terminal (e.g., A): ");
    scanf(" %c", &nonTerminal);
    printf("Enter the number of rules for %c: ", nonTerminal);
    scanf("%d", &ruleCount);
    printf("Enter the rules (one per line):\n");
    for (i = 0; i < ruleCount; i++) {
        printf("Rule %d: ", i + 1);
        scanf("%s", rules[i]);
    }
    eliminateLeftRecursion(nonTerminal, rules, ruleCount);
    return 0;
}
