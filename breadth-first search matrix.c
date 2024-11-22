// Write a program to represent the given graph using adjacency matrix and implement Breadth-First Search Traversal for a given Graph. 
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// Function to perform BFS traversal
void BFS(int graph[MAX_VERTICES][MAX_VERTICES], int start, int n) {
    int visited[MAX_VERTICES] = {0}; // Array to track visited nodes
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    // Enqueue the starting node and mark it as visited
    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal starting from vertex %d: ", start);
    
    while (front < rear) {
        int node = queue[front++];  // Dequeue a node
        printf("%d ", node);  // Process the node

        // Enqueue all unvisited adjacent nodes
        for (int i = 0; i < n; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

// Function to add an edge to the graph (undirected)
void addEdge(int graph[MAX_VERTICES][MAX_VERTICES], int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1; // For undirected graph
}

// Function to print the adjacency matrix
void printGraph(int graph[MAX_VERTICES][MAX_VERTICES], int n) {
    printf("Adjacency Matrix representation of the graph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = {0}; // Initialize the graph with 0
    int n, e, u, v;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    // Input edges
    for (int i = 0; i < e; i++) {
        printf("Enter edge %d (u, v): ", i + 1);
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    // Print the adjacency matrix
    printGraph(graph, n);

    // Perform BFS traversal
    int start;
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &start);

    BFS(graph, start, n);

    return 0;
}
