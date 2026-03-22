#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

// ENQUEUE
void enqueue(int value) {
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

// DEQUEUE
void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
    } else {
        struct node *temp = front;
        printf("Deleted = %d\n", front->data);
        front = front->next;

        if (front == NULL) rear = NULL;
        free(temp);
    }
}

// DISPLAY
void display() {
    struct node *temp = front;

    if (temp == NULL) {
        printf("Queue is empty\n");
    } else {
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
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
        }
    }
}