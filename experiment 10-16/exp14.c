#include <stdio.h>
#define MAX_SIZE 5
int cqueue[MAX_SIZE];
int front = -1, rear = -1;

void insert(int data) {
    if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1)) {
        printf("Circular Queue is full, cannot insert\n");
        return;
    }

    if (front == -1) {
        front = 0;
        rear = 0;
    } else {
        if (rear == MAX_SIZE - 1)
            rear = 0;
        else
            rear = rear + 1;
    }
    cqueue[rear] = data;
}

void delete() {
    if (front == -1) {
        printf("Circular Queue is empty, cannot delete\n");
        return;
    }

    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        if (front == MAX_SIZE - 1)
            front = 0;
        else
            front = front + 1;
    }
}

void display() {
    int i;
    if (front == -1) {
        printf("Circular Queue is empty\n");
        return;
    }

    printf("Displaying Circular Queue: ");
    if (rear >= front) {
        for (i = front; i <= rear; i++)
            printf("%d ", cqueue[i]);
    } else {
        for (i = front; i < MAX_SIZE; i++)
            printf("%d ", cqueue[i]);

        for (i = 0; i <= rear; i++)
            printf("%d ", cqueue[i]);
    }
    printf("\n");
}

void main() {
    int data,n,i;
    printf("Enter no. of elements to insert: ");
    scanf("%d",&n);
    if(n>0)
        printf("Enter data to insert: ");
    for(i=0;i<n;i++){
        scanf("%d", &data);
        insert(data);
    }
    printf("Enter no. of elements to delete: ");
    scanf("%d",&n);
        for(i=0;i<n;i++)
            delete();
    display();
}