#include <stdio.h>
#include <stdlib.h>

// Structure for a stack node
struct Node {
    int data;
    struct Node* next;
};

// Function to push an element to stack
void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed to stack\n", value);
}

// Function to pop an element from stack
void pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow! Nothing to pop.\n");
        return;
    }
    struct Node* temp = *top;
    printf("Popped element: %d\n", temp->data);
    *top = (*top)->next;
    free(temp);
}

// Function to peek (see top element)
void peek(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element: %d\n", top->data);
    }
}

// Function to display the stack
void display(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

int main() {
    struct Node* top = NULL;
    int choice, value;

    do {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&top, value);
                break;
            case 2:
                pop(&top);
                break;
            case 3:
                peek(top);
                break;
            case 4:
                display(top);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
