/*Implement a Min Heap tree and sort the elements. The following operations
should be supported:
a. heapify
b. extractMin (Deleting the min element)
c. heapsort*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // Maximum size of the heap

typedef struct {
    int size;
    int array[MAX_SIZE];
} MinHeap;

// Function to swap two integers
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to heapify a subtree rooted at index `i` in a Min Heap
void heapify(MinHeap* heap, int i) {
    int smallest = i;  // Initialize smallest as root
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check if left child is smaller than root
    if (left < heap->size && heap->array[left] < heap->array[smallest]) {
        smallest = left;
    }

    // Check if right child is smaller than smallest so far
    if (right < heap->size && heap->array[right] < heap->array[smallest]) {
        smallest = right;
    }

    // If smallest is not root, swap it with the smallest and continue heapifying
    if (smallest != i) {
        swap(&heap->array[i], &heap->array[smallest]);
        heapify(heap, smallest);
    }
}

// Function to extract the minimum element (root) from the Min Heap
int extractMin(MinHeap* heap) {
    if (heap->size <= 0) {
        printf("Heap is empty\n");
        return -1;
    }
    if (heap->size == 1) {
        heap->size--;
        return heap->array[0];
    }

    // Store the minimum value and remove it from heap
    int root = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heapify(heap, 0);

    return root;
}

// Function to insert an element into the Min Heap
void insert(MinHeap* heap, int key) {
    if (heap->size >= MAX_SIZE) {
        printf("Heap overflow\n");
        return;
    }

    // Insert the new key at the end
    int i = heap->size;
    heap->array[i] = key;
    heap->size++;

    // Fix the Min Heap property if it is violated
    while (i != 0 && heap->array[(i - 1) / 2] > heap->array[i]) {
        swap(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to perform heap sort
void heapSort(int arr[], int n) {
    MinHeap heap;
    heap.size = 0;

    // Build the Min Heap with all elements
    for (int i = 0; i < n; i++) {
        insert(&heap, arr[i]);
    }

    // Extract elements one by one and store them in sorted order
    for (int i = 0; i < n; i++) {
        arr[i] = extractMin(&heap);
    }
}

// Utility function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, key;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array:\n");
    printArray(arr, n);

    // Perform heap sort
    heapSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}
