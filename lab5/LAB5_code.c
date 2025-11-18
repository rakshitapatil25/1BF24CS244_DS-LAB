#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void createList(int n) {
    struct node *newNode, *temp;
    int data, i;

    head = (struct node*)malloc(sizeof(struct node));
    printf("Enter data of node 1: ");
    scanf("%d", &data);
    head->data = data;
    head->next = NULL;
    temp = head;

    for(i = 2; i <= n; i++) {
        newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data of node %d: ", i);
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;
        temp->next = newNode;
        temp = temp->next;
    }
}

void deleteAtBeginning() {
    struct node *temp;
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    temp = head;
    head = head->next;
    free(temp);
}

void deleteAtEnd() {
    struct node *temp, *prev;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    if(head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

void deleteAtPosition(int pos) {
    struct node *temp, *del;
    int i;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;

    if(pos == 1) {
        head = head->next;
        free(temp);
        return;
    }

    for(i = 1; i < pos-1; i++) {
        temp = temp->next;
        if(temp == NULL) {
            printf("Invalid Position\n");
            return;
        }
    }

    del = temp->next;
    temp->next = del->next;
    free(del);
}

void displayList() {
    struct node *temp = head;
    printf("Linked List: ");
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n, choice, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    
    createList(n);

    while(1) {
        printf("\n1. Delete at Beginning\n2. Delete at End\n3. Delete at Position\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                deleteAtBeginning();
                break;
            case 2:
                deleteAtEnd();
                break;
            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 4:
                displayList();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

