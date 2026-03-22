#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// INSERT AT BEGINNING
void insertBegin(int value) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// INSERT AT END
void insertEnd(int value) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    struct node *temp = head;

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// DELETE NODE (by value)
void deleteNode(int value) {
    struct node *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    // if first node is to be deleted
    if (temp->data == value) {
        head = temp->next;
        free(temp);
        return;
    }

    // search for node
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// DISPLAY
void display() {
    struct node *temp = head;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1.Insert Begin 2.Insert End 3.Delete 4.Display 5.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBegin(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}