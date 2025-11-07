#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Function to enqueue (insert)
void enqueue() {
    int value;
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot insert.\n");
    } else {
        printf("Enter value to insert: ");
        scanf("%d", &value);
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
        printf("%d inserted into the queue.\n", value);
    }
}

// Function to dequeue (delete)
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! No elements to delete.\n");
    } else {
        printf("Deleted element: %d\n", queue[front]);
        front++;
        if (front > rear) { // Reset when queue becomes empty
            front = rear = -1;
        }
    }
}

// Function to peek (front element)
void peek() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty!\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}

// Function to display all elements
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    do {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Peek (Front)\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: printf("Exiting program...\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
