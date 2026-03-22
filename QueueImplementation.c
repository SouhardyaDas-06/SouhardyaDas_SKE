#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// ENQUEUE
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1) front = 0;
        rear++;
        queue[rear] = value;
    }
}

// DEQUEUE
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
    } else {
        printf("Deleted element = %d\n", queue[front]);
        front++;
    }
}

// DISPLAY
void display() {
    int i;
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}