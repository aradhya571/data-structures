#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void insert(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if (!newNode) {
        printf("Queue is full, cannot insert\n");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void delete() {
    if (front == NULL) {
        printf("Queue is empty, cannot delete\n");
        return;
    }

    struct Node* temp = front;

    front = front->next;
    free(temp);

    if (front == NULL) {
        rear = NULL;
    }
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = front;
    printf("Displaying Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
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

        
               
