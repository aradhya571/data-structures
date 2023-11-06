#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* top = NULL;

void push(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    if (!newNode) {
        printf("Stack Overflow\n");
    }

    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (top == NULL) {
        printf("Stack is empty, cannot pop\n");
    }

    struct node* temp = top;
    top = top->next;
    free(temp);
}

void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
    }

    struct node* temp = top;
    printf("Displaying Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main() {
    int data,n,i;
    printf("Enter no. of elements to push: ");
    scanf("%d",&n);
    printf("Enter data to push: ");
    for(i=0;i<n;i++)
    {
        scanf("%d", &data);
        push(data);
    }
        
    printf("Enter no. of elements to pop: ");
    scanf("%d",&n);
        for(i=0;i<n;i++)
            pop();
               
    display();
}
