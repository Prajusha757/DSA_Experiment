#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int adj[MAX][MAX];     // Adjacency matrix
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;

// Function to add edge to adjacency matrix
void addEdge(int u, int v) {
    adj[u][v] = 1;  // Directed edge from u to v
}

// BFS Traversal
void BFS(int start, int n) {
    int i;
    front = rear = -1;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    // Enqueue start vertex
    queue[++rear] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front != rear) {
        start = queue[++front];
        printf("%d ", start);

        for (i = 0; i < n; i++) {
            if (adj[start][i] == 1 && visited[i] == 0) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// DFS Traversal (Recursive)
void DFS(int v, int n) {
    int i;
    printf("%d ", v);
    visited[v] = 1;

    for (i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            DFS(i, n);
        }
    }
}

// Display Adjacency Matrix
void displayMatrix(int n) {
    int i, j;
    printf("Adjacency Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }
}

// Main function
int main() {
    int n, e;
    int i, u, v;
    int choice, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    // Initialize adjacency matrix
    for (i = 0; i < n; i++)
        for (v = 0; v < n; v++)
            adj[i][v] = 0;

    printf("Enter edges (source destination):\n");
    for (i = 0; i < e; i++) {
        scanf("%d%d", &u, &v);
        addEdge(u, v);
    }

    do {
        printf("\n--- Graph Traversal Menu ---\n");
        printf("1. Perform BFS\n");
        printf("2. Perform DFS\n");
        printf("3. Display Adjacency Matrix\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter starting vertex (0 to %d): ", n - 1);
                scanf("%d", &start);
                BFS(start, n);
                break;

            case 2:
                printf("Enter starting vertex (0 to %d): ", n - 1);
                scanf("%d", &start);
                for (i = 0; i < n; i++)
                    visited[i] = 0;
                printf("DFS Traversal: ");
                DFS(start, n);
                printf("\n");
                break;

            case 3:
                displayMatrix(n);
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 4);

    return 0;
}
