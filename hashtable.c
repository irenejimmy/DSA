#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int hashTable[SIZE], flag[SIZE]; // 0=empty, 1=occupied, -1=deleted

int hash(int key) { return key % SIZE; }

void insert(int key) {
    int i = hash(key), start = i;

    while (flag[i] == 1) {
        i = (i + 1) % SIZE;
        if (i == start) {
            printf("Hash Table Full!\n");
            return;
        }
    }

    hashTable[i] = key;
    flag[i] = 1;
    printf("Inserted %d at %d\n", key, i);
}

void search(int key) {
    int i = hash(key), start = i;

    while (flag[i] != 0) {
        if (flag[i] == 1 && hashTable[i] == key) {
            printf("Found %d at %d\n", key, i);
            return;
        }
        i = (i + 1) % SIZE;
        if (i == start) break;
    }

    printf("Not Found!\n");
}

void deleteKey(int key) {
    int i = hash(key), start = i;

    while (flag[i] != 0) {
        if (flag[i] == 1 && hashTable[i] == key) {
            flag[i] = -1;
            printf("Deleted %d from %d\n", key, i);
            return;
        }
        i = (i + 1) % SIZE;
        if (i == start) break;
    }

    printf("Key not found!\n");
}

void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (flag[i] == 1)
            printf("%d -> %d\n", i, hashTable[i]);
        else if (flag[i] == -1)
            printf("%d -> Deleted\n", i);
        else
            printf("%d -> Empty\n", i);
    }
}

int main() {
    for(int i = 0; i < SIZE; i++) flag[i] = 0;  // Initialize flags

    int ch, key;
    while (1) {
        printf("\n1.Insert 2.Search 3.Delete 4.Display 5.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Key: "); scanf("%d", &key); insert(key); break;
            case 2: printf("Key: "); scanf("%d", &key); search(key); break;
            case 3: printf("Key: "); scanf("%d", &key); deleteKey(key); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid!\n");
        }
    }
    return 0;
}
