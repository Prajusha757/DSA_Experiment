#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack Node (for Browser History)
struct StackNode {
    char url[100];
    struct StackNode *next;
};

// Queue Node (for Print Jobs)
struct QueueNode {
    char jobName[100];
    struct QueueNode *next;
};

struct StackNode *top = NULL;
struct QueueNode *front = NULL, *rear = NULL;

// --- Stack Functions (Browser History) ---
void visitPage(char url[]) {
    struct StackNode *newNode = (struct StackNode *)malloc(sizeof(struct StackNode));
    strcpy(newNode->url, url);
    newNode->next = top;
    top = newNode;
    printf("Visited: %s\n", url);
}

void goBack() {
    if (top == NULL) {
        printf("No pages to go back.\n");
        return;
    }
    struct StackNode *temp = top;
    top = top->next;
    printf("Going back from: %s\n", temp->url);
    free(temp);
}

void showHistory() {
    if (top == NULL) {
        printf("No browsing history.\n");
        return;
    }
    struct StackNode *temp = top;
    printf("Browser History:\n");
    while (temp != NULL) {
        printf("%s\n", temp->url);
        temp = temp->next;
    }
}

// --- Queue Functions (Print Jobs) ---
void addPrintJob(char jobName[]) {
    struct QueueNode *newNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    strcpy(newNode->jobName, jobName);
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Added print job: %s\n", jobName);
}

void printJob() {
    if (front == NULL) {
        printf("No print jobs in queue.\n");
        return;
    }
    struct QueueNode *temp = front;
    printf("Printing job: %s\n", temp->jobName);
    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(temp);
}

void showPrintQueue() {
    if (front == NULL) {
        printf("No print jobs in queue.\n");
        return;
    }
    struct QueueNode *temp = front;
    printf("Print Queue:\n");
    while (temp != NULL) {
        printf("%s\n", temp->jobName);
        temp = temp->next;
    }
}

// --- Safe Input Function ---
void readString(char *str, int size) {
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = '\0'; // remove newline
}

// --- Main Function ---
int main() {
    int choice;
    char input[100];

    while (1) {
        printf("\n--- Real-Life Simulation ---\n");
        printf("1. Visit Browser Page (Stack)\n");
        printf("2. Go Back (Stack)\n");
        printf("3. Show Browser History (Stack)\n");
        printf("4. Add Print Job (Queue)\n");
        printf("5. Print Job (Queue)\n");
        printf("6. Show Print Queue (Queue)\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline from input buffer

        switch (choice) {
            case 1:
                printf("Enter URL: ");
                readString(input, sizeof(input));
                visitPage(input);
                break;
            case 2:
                goBack();
                break;
            case 3:
                showHistory();
                break;
            case 4:
                printf("Enter Print Job Name: ");
                readString(input, sizeof(input));
                addPrintJob(input);
                break;
            case 5:
                printJob();
                break;
            case 6:
                showPrintQueue();
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
