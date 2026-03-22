#include <stdio.h>

int heap[100];
int size = 0;

// INSERT into Max Heap
void insert(int value) {
    int i = size;
    heap[i] = value;
    size++;

    // Heapify Up
    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// DISPLAY
void display() {
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
}

int main() {
    insert(10);
    insert(30);
    insert(20);
    insert(5);

    printf("Max Heap: ");
    display();

    return 0;
}