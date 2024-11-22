/*Implement the Max Heap tree and sort the elements. The following operations
should be supported:
a. heapify
b. extractMax (Deleting the max element)
c. heapsort*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // Maximum size of the heap

typedef struct {
    int size;
    int array[MAX_SIZE];
} MaxHeap;

// Function to swap two integers
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to heapify a subtree rooted at index `i` in a Max Heap
void maxHeapify(MaxHeap* heap, int i) {
    int largest = i;  // Initialize largest as root
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check if left child is larger than root
    if (left < heap->size && heap->array[left] > heap->array[largest]) {
        largest = left;
    }

    // Check if right child is larger than largest so far
    if (right < heap->size && heap->array[right] > heap->array[largest]) {
        largest = right;
    }

    // If largest is not root, swap it with the largest and continue heapifying
    if (largest != i) {
        swap(&heap->array[i], &heap->array[largest]);
        maxHeapify(heap, largest);
    }
}

// Function to extract the maximum element (root) from the Max Heap
int extractMax(MaxHeap* heap) {
    if (heap->size <= 0) {
        printf("Heap is empty\n");
        return -1;
    }
    if (heap->size == 1) {
        heap->size--;
        return heap->array[0];
    }

    // Store the maximum value and remove it from heap
    int root = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    maxHeapify(heap, 0);

    return root;
}

// Function to insert an element into the Max Heap
void insert(MaxHeap* heap, int key) {
    if (heap->size >= MAX_SIZE) {
        printf("Heap overflow\n");
        return;
    }

    // Insert the new key at the end
    int i = heap->size;
    heap->array[i] = key;
    heap->size++;

    // Fix the Max Heap property if it is violated
    while (i != 0 && heap->array[(i - 1) / 2] < heap->array[i]) {
        swap(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to perform heap sort (sorts in descending order)
void heapSort(int arr[], int n) {
    MaxHeap heap;
    heap.size = 0;

    // Build the Max Heap with all elements
    for (int i = 0; i < n; i++) {
        insert(&heap, arr[i]);
    }

    // Extract elements one by one and store them in descending order
    for (int i = n - 1; i >= 0; i--) {
        arr[i] = extractMax(&heap);
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

    printf("Sorted array in descending order:\n");
    printArray(arr, n);

    return 0;
}
