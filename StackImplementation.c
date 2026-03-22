#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

// PUSH
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = value;
    }
}

// POP
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("Popped element = %d\n", stack[top]);
        top--;
    }
}

// DISPLAY
void display() {
    int i;
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements:\n");
        for (i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
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