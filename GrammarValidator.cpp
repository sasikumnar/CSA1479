#include <stdio.h>
#include <string.h>
int isValidString(const char *str) {
    int length = strlen(str);
    int balance = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] == 'a') {
            balance++;
        } else if (str[i] == 'b') {
            balance--;
            if (balance < 0) {
                return 0;
            }
        } else {
            return 0;
        }
    }
    return balance == 0;
}
int main() {
    char input[100];
    printf("Enter a string to check: ");
    scanf("%s", input);
    if (isValidString(input)) {
        printf("The string '%s' satisfies the grammar.\n", input);
    } else {
        printf("The string '%s' does not satisfy the grammar.\n", input);
    }
    return 0;
}
