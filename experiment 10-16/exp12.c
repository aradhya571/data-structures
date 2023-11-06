#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 3

int queue[MAX_SIZE];
int front = -1, rear = -1;

void insert(int data) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue Overflow: Cannot insert %d\n",data);
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = data;
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue is empty, cannot delete\n");
        return;
    }
    front++;

    if (front > rear) {
        front = rear = -1;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Displaying Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
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
