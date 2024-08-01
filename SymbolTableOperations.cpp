#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 10
typedef struct Symbol {
    char name[50];
    struct Symbol *next;
} Symbol;
Symbol *hashTable[TABLE_SIZE];
unsigned int hash(char *name) {
    unsigned int hashValue = 0;
    while (*name) {
        hashValue = (hashValue << 5) + *name++;
    }
    return hashValue % TABLE_SIZE;
}
void initializeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}
void insertSymbol(char *name) {
    unsigned int index = hash(name);
    Symbol *newSymbol = (Symbol *)malloc(sizeof(Symbol));
    strcpy(newSymbol->name, name);
    newSymbol->next = hashTable[index];
    hashTable[index] = newSymbol;
    printf("Inserted: %s\n", name);
}
int lookupSymbol(char *name) {
    unsigned int index = hash(name);
    Symbol *current = hashTable[index];
    while (current) {
        if (strcmp(current->name, name) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}
void deleteSymbol(char *name) {
    unsigned int index = hash(name);
    Symbol *current = hashTable[index];
    Symbol *prev = NULL;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            if (prev) {
                prev->next = current->next;
            } else {
                hashTable[index] = current->next;
            }
            free(current);
            printf("Deleted: %s\n", name);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Symbol not found: %s\n", name);
}
void displayTable() {
    printf("Symbol Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        Symbol *current = hashTable[i];
        if (current) {
            printf("Index %d: ", i);
            while (current) {
                printf("%s -> ", current->name);
                current = current->next;
            }
            printf("NULL\n");
        }
    }
}
int main() {
    int choice;
    char name[50];

    initializeTable();

    while (1) {
        printf("\nSymbol Table Operations:\n");
        printf("1. Insert Symbol\n");
        printf("2. Lookup Symbol\n");
        printf("3. Delete Symbol\n");
        printf("4. Display Table\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 
        switch (choice) {
            case 1:
                printf("Enter symbol name to insert: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; 
                insertSymbol(name);
                break;
            case 2:
                printf("Enter symbol name to lookup: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; 
                if (lookupSymbol(name)) {
                    printf("Symbol found: %s\n", name);
                } else {
                    printf("Symbol not found: %s\n", name);
                }
                break;
            case 3:
                printf("Enter symbol name to delete: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; 
                deleteSymbol(name);
                break;
            case 4:
                displayTable();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
