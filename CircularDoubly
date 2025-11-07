#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

// Function to insert at beginning
void insertAtBeginning(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
    } else {
        struct Node *last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
    printf("%d inserted at the beginning.\n", value);
}

// Function to insert at end
void insertAtEnd(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
    } else {
        struct Node *last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
    }
    printf("%d inserted at the end.\n", value);
}

// Function to delete from beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {
        printf("%d deleted from beginning.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    struct Node *last = head->prev;
    struct Node *temp = head;
    head = head->next;
    head->prev = last;
    last->next = head;
    printf("%d deleted from beginning.\n", temp->data);
    free(temp);
}

// Function to delete from end
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {
        printf("%d deleted from end.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    struct Node *last = head->prev;
    struct Node *secondLast = last->prev;
    secondLast->next = head;
    head->prev = secondLast;
    printf("%d deleted from end.\n", last->data);
    free(last);
}

// Function to display list in forward direction
void displayForward() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("Circular Doubly Linked List (Forward): ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

// Function to display list in reverse direction
void displayReverse() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head->prev;
    printf("Circular Doubly Linked List (Reverse): ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    } while (temp != head->prev);
    printf("(back to head)\n");
}

// Main Function
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Doubly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display Forward\n");
        printf("6. Display Reverse\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                deleteFromBeginning();
                break;
            case 4:
                deleteFromEnd();
                break;
            case 5:
                displayForward();
                break;
            case 6:
                displayReverse();
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
