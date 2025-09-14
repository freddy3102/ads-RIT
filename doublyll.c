#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;    // global head pointer
struct Node* newNode = NULL;// global newNode pointer
struct Node* temp;
int value, pos;              // global variables for input

// Insert at beginning
void insbeg() {
    printf("Enter value: ");
    scanf("%d", &value);

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Insert at end
void insend() {
    printf("Enter value: ");
    scanf("%d", &value);

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    temp = head;
    while (temp->next != NULL) temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Insert at specific position
void inspos() {
    printf("Enter value: ");
    scanf("%d", &value);
    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos <= 1 || head == NULL) {
        insbeg();
        return;
    }

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = newNode->next = NULL;

    temp = head;
    int i = 1;
    while (i < pos - 1 && temp->next != NULL) {
        temp = temp->next;
        i++;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) temp->next->prev = newNode;
    temp->next = newNode;
}

// Delete from beginning
void delbeg() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    temp = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    printf("Deleted: %d\n", temp->data);
    free(temp);
}

// Delete from end
void delend() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    temp = head;
    if (temp->next == NULL) {
        printf("Deleted: %d\n", temp->data);
        free(temp);
        head = NULL;
        return;
    }
    while (temp->next != NULL) temp = temp->next;
    printf("Deleted: %d\n", temp->data);
    temp->prev->next = NULL;
    free(temp);
}

// Delete from specific position
void delpos() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1) {
        delbeg();
        return;
    }
    temp = head;
    int i = 1;
    while (i < pos && temp != NULL) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        printf("Position not found\n");
        return;
    }
    printf("Deleted: %d\n", temp->data);
    if (temp->next != NULL) temp->next->prev = temp->prev;
    if (temp->prev != NULL) temp->prev->next = temp->next;
    free(temp);
}

// Search an element
void search() {
    int flag=0;
    printf("Enter value to search: ");
    scanf("%d", &value);

    temp = head;
    int p = 1;
    while (temp != NULL) {
        if (temp->data == value) {
            printf("Element %d found at position %d\n", value, p);
            flag=1;
        }
        temp = temp->next;
        p++;
    }
    if(flag==0)
    printf("Element %d not found\n", value);
}

// Traversal forward
void traverseForward() {
    struct Node* temp = head;
    printf("Forward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Traversal backward
void traverseBackward() {
    
if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    printf("Backward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Main function
void main() {
    int choice;
    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete from position\n");
        printf("7. Search\n");
        printf("8. Traverse forward\n");
        printf("9. Traverse backward\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insbeg(); break;
            case 2: insend(); break;
            case 3: inspos(); break;
            case 4: delbeg(); break;
            case 5: delend(); break;
            case 6: delpos(); break;
            case 7: search(); break;
            case 8: traverseForward(); break;
            case 9: traverseBackward(); break;
            case 0: exit(0);
            default: printf("Invalid choice!\n");
        }
    }