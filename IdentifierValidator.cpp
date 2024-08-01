#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_ID_LENGTH 31
int isValidIdentifier(const char *identifier) {
    int length = strlen(identifier);
    if (length == 0 || length > MAX_ID_LENGTH) {
        return 0;
    }
    if (!isalpha(identifier[0]) && identifier[0] != '_') {
        return 0;
    }
    for (int i = 1; i < length; i++) {
        if (!isalnum(identifier[i]) && identifier[i] != '_') {
            return 0;
        }
    }
    return 1;
}
int main() {
    char identifier[MAX_ID_LENGTH + 2];
    printf("Enter an identifier: ");
    if (fgets(identifier, sizeof(identifier), stdin) != NULL) {
        size_t len = strlen(identifier);
        if (len > 0 && identifier[len - 1] == '\n') {
            identifier[len - 1] = '\0';
        }
        if (isValidIdentifier(identifier)) {
            printf("The identifier '%s' is valid.\n", identifier);
        } else {
            printf("The identifier '%s' is invalid.\n", identifier);
        }
    } else {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }
    return 0;
}
