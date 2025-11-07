#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Function to check if queue is full
int isFull() {
    return ((rear + 1) % MAX == front);
}

// Function to check if queue is empty
int isEmpty() {
    return (front == -1);
}

// Function to enqueue (insert)
void enqueue() {
    int value;
    if (isFull()) {
        printf("Queue Overflow! Cannot insert.\n");
    } else {
        printf("Enter value to insert: ");
        scanf("%d", &value);

        if (front == -1)
            front = 0;

        rear = (rear + 1) % MAX;
        queue[rear] = value;

        printf("%d inserted into the queue.\n", value);
    }
}

// Function to dequeue (delete)
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! No elements to delete.\n");
    } else {
        printf("Deleted element: %d\n", queue[front]);

        if (front == rear) {
            // Queue becomes empty
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }
}

// Function to peek (front element)
void peek() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}

// Function to display all elements
void display() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear)
                break;
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

int main() {
    int choice;
    do {
        printf("\n--- Circular Queue Menu ---\n");
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
