#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node *head = NULL, *tail = NULL;

// a) Create a doubly linked list.
void createList(int n) {
    int i, data;
    struct Node *newNode;

    for (i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->prev = newNode->next = NULL;

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
}



// b) Insert  a new node to the left of a given node.
void insertToLeftOfNode(int newData, int existingData) {
    struct Node *temp = head;
    struct Node *newNode;

    // Find the node with data == existingData
    while (temp != NULL && temp->data != existingData) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with value %d not found.", existingData);
        return;
    }

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;

    newNode->next = temp;
    newNode->prev = temp->prev;

    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    } else {
        // temp is head
        head = newNode;
    }

    temp->prev = newNode;
}



// c) Delete the node based on a specific value.
void deleteByValue(int value) {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty!");
        return;
    }

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value not found!");
        return;
    }

    if (temp == head) {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        else
            tail = NULL;
        free(temp);
    }
    else if (temp == tail) {
        tail = tail->prev;
        if (tail != NULL)
            tail->next = NULL;
        else
            head = NULL;
        free(temp);
    }
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}



// d) Display the contents of the list (forward).
void displayForward() {
    struct Node *temp = head;
    printf("List (Forward): ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}




int main() {
    int n, newData, existingData, value;

    printf("Enter number of nodes to create: ");
    scanf("%d", &n);
    createList(n);

    printf("Initial list: \n");
    displayForward();

    printf("\nEnter the value to insert: ");
    scanf("%d", &newData);
    printf("Enter the value of the node to insert to the left of: ");
    scanf("%d", &existingData);
    insertToLeftOfNode(newData, existingData);

    printf("List after insertion:\n");
    displayForward();

    printf("\nEnter value to delete: ");
    scanf("%d", &value);
    deleteByValue(value);

    printf("List after deletion: \n");
    displayForward();
    return 0;
}
