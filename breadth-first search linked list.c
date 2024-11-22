1.	// Write a program to represent the given graph using adjacency linked list and implement Breadth-First Search Traversal for a given Graph. 
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// Structure to represent a graph node
typedef struct GraphNode {
    int vertex;
    struct GraphNode* next;
} GraphNode;

// Structure to represent the graph using adjacency list
typedef struct Graph {
    int numVertices;
    GraphNode* adjList[MAX_VERTICES];
} Graph;

// Function to create a new graph node
GraphNode* createNode(int vertex) {
    GraphNode* newNode = (GraphNode*)malloc(sizeof(GraphNode));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    // Initialize all adjacency lists to NULL
    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph (undirected)
void addEdge(Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    GraphNode* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Add an edge from dest to src (for undirected graph)
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Function to perform BFS traversal
void BFS(Graph* graph, int start) {
    int visited[MAX_VERTICES] = {0};  // Array to track visited vertices
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    // Enqueue the starting vertex and mark it as visited
    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal starting from vertex %d: ", start);
    
    while (front < rear) {
        int vertex = queue[front++];  // Dequeue a vertex
        printf("%d ", vertex);  // Process the vertex

        // Explore all unvisited adjacent vertices
        GraphNode* temp = graph->adjList[vertex];
        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex] = 1;
                queue[rear++] = temp->vertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

// Function to print the adjacency list of the graph
void printGraph(Graph* graph) {
    printf("Adjacency List representation of the graph:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        GraphNode* temp = graph->adjList[i];
        printf("Vertex %d: ", i);
        while (temp != NULL) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int vertices, edges, u, v;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    Graph* graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Input edges
    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d (u, v): ", i + 1);
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    // Print the adjacency list
    printGraph(graph);

    // Perform BFS traversal
    int start;
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &start);

    BFS(graph, start);

    return 0;
}
