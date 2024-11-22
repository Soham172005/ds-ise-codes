//Write a program to represent the given graph using adjacency linked list and implement Depth First Search Traversal for a given graph. 
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// Structure to represent a graph node (for adjacency list)
typedef struct GraphNode {
    int vertex;
    struct GraphNode* next;
} GraphNode;

// Structure to represent the graph using an adjacency list
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

// Function to add an edge to the graph (directed graph)
void addEdge(Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    GraphNode* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

// Function to perform DFS traversal (recursive)
void DFS(Graph* graph, int vertex, int visited[]) {
    printf("%d ", vertex);  // Process the current vertex
    visited[vertex] = 1;     // Mark the vertex as visited

    // Explore all unvisited adjacent vertices
    GraphNode* temp = graph->adjList[vertex];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            DFS(graph, temp->vertex, visited);  // Recursive call for unvisited adjacent vertex
        }
        temp = temp->next;
    }
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

    // Perform DFS traversal
    int visited[MAX_VERTICES] = {0};  // Array to track visited vertices
    int start;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &start);

    printf("DFS Traversal starting from vertex %d: ", start);
    DFS(graph, start, visited);
    printf("\n");

    return 0;
}
