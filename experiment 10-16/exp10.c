#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 2

int stack[MAX_SIZE];
int top = -1;

void push(int data) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow: Cannot push, the stack is full.\n");
        return;
    }
    stack[++top] = data;
    printf("%d pushed to the stack.\n", data);
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow: Cannot pop, the stack is empty.\n");
        return;
    }
    printf("%d popped from the stack.\n", stack[top--]);
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Displaying Stack elements: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void main() {
    int  data,n;
    printf("Enter no. of elements to push: ");
    scanf("%d",&n);
    printf("Enter data to push: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d", &data);
        push(data);
    }
    printf("Enter no. of elements to pop: ");
    scanf("%d",&n);
    for(int i =0;i<n;i++)
        pop();
    display();
}

