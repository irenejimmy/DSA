#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char url[100];
    struct Node* prev;
    struct Node* next;
};
struct Node* current = NULL;

struct Node* createNode(char* url) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->url, url);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void visitNewPage(char* url) {

    struct Node* newNode = createNode(url);


    newNode->prev = current;
    newNode->next = NULL;

   
    if (current != NULL) {
        current->next = newNode;
    }

    current = newNode;

  
    printf("Visited: %s\n", current->url);
}


void goBack() {
 
    if (current == NULL || current->prev == NULL) {
        printf("Cannot go back!\n");
    } else {
      
        current = current->prev;
        printf("Moved back to: %s\n", current->url);
    }
}

void goForward() {

    if (current == NULL || current->next == NULL) {
        printf("Cannot go forward!\n");
    } else {
       
        current = current->next;
        printf("Moved forward to: %s\n", current->url);
    }
}

void displayCurrent() {
    if (current == NULL) {
        printf("No page visited yet.\n");
    } else {
        printf("Current page: %s\n", current->url);
    }
}


void freeAllPages() {
    struct Node* temp = current;

  
    while (temp && temp->prev != NULL) {
        temp = temp->prev;
    }

  
    while (temp != NULL) {
        struct Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
}

int main() {
    int choice;
    char url[100];

    do {

        printf("\n--- Browser Navigation Menu ---\n");
        printf("1. Visit new page\n");
        printf("2. Go back\n");
        printf("3. Go forward\n");
        printf("4. Display current page\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

      
        switch(choice) {
            case 1:
                printf("Enter URL: ");
                scanf("%s", url);
                visitNewPage
