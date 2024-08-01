#include <stdio.h>
#include <string.h>
#define MAX_RULES 100
#define MAX_SYMBOLS 100
int longestCommonPrefix(const char *str1, const char *str2, char *prefix) {
    int i = 0;
    while (str1[i] && str2[i] && str1[i] == str2[i]) {
        prefix[i] = str1[i];
        i++;
    }
    prefix[i] = '\0';
    return i;
}
void eliminateLeftFactoring(char nonTerminal, char rules[MAX_RULES][MAX_SYMBOLS], int ruleCount) {
    char commonPrefix[MAX_SYMBOLS];
    char newNonTerminal = nonTerminal + 1;
    int i, j;
    int prefixLength = 0;
    for (i = 0; i < ruleCount - 1; i++) {
        for (j = i + 1; j < ruleCount; j++) {
            char currentPrefix[MAX_SYMBOLS];
            int length = longestCommonPrefix(rules[i], rules[j], currentPrefix);
            if (length > prefixLength && length > 0) {
                prefixLength = length;
                strcpy(commonPrefix, currentPrefix);
            }
        }
    }

    if (prefixLength == 0) {
        printf("No left factoring needed.\n");
        for (i = 0; i < ruleCount; i++) {
            printf("%c -> %s\n", nonTerminal, rules[i]);
        }
        return;
    }
    printf("Eliminated left factoring rules:\n");
    printf("%c -> %s%c\n", nonTerminal, commonPrefix, newNonTerminal);
    printf("%c -> ", newNonTerminal);
    int first = 1;
    for (i = 0; i < ruleCount; i++) {
        if (strncmp(rules[i], commonPrefix, prefixLength) == 0) {
            if (!first) printf(" | ");
            printf("%s", rules[i] + prefixLength);
            first = 0;
        }
    }
    printf(" | e\n");
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
    eliminateLeftFactoring(nonTerminal, rules, ruleCount);
    return 0;
}
