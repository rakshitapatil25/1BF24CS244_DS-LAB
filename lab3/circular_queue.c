#include<stdio.h>
#define N 100
int queue[N];
int front= -1;
int rear= -1;

void enqueue(int x){
    if(front==0 && rear==N-1 || front>rear){
        printf("Queue Overflow\n");
        return;
    }
    else if(front==-1){
        front=0;
    }
    rear=(rear+1)%N;
    queue[rear]=x;
    printf("Inserted %d\n",x);
}

void dequeue(){
    if(front==-1 && rear==-1){
        printf("Queue Underflow\n");
        return;
    }
    else{
        printf("Dequeued element : %d ",queue[front]);
        front=(front+1)%N;

    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % N;
    }
    printf("\n");
}


int main() {
    int choice, x;
    while (1) {
        printf("\n1. Insert  2. Delete  3. Display  4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &x);
            enqueue(x);
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
            printf("Invalid Choice\n");
        }
    }
}

