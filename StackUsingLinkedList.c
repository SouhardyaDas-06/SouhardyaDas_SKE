#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

// PUSH
void push(int value) {
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// POP
void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
    } else {
        struct node *temp = top;
        printf("Popped element = %d\n", top->data);
        top = top->next;
        free(temp);
    }
}

// DISPLAY
void display() {
    struct node *temp = top;

    if (temp == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements:\n");
        while (temp != NULL) {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1.Push 2.Pop 3.Display 4.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
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