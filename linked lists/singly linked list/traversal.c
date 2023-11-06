#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void linkedlisttraversal(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("Element : %d\n",ptr->data);
        ptr = ptr->next;
    }
}

void main()
{
    struct node* head;
    struct node* second;
    struct node* third;

    // allocate memory for nodes in the linked list in heap
    head = (struct node*)malloc(sizeof(struct node*));
    second = (struct node*)malloc(sizeof(struct node*));
    third = (struct node*)malloc(sizeof(struct node*));

    // link 1st and 2nd nodes
    head->data = 70;
    head->next = second;

    second->data =8;
    second->next =third;

    third->data =67;
    third->next=NULL;

    linkedlisttraversal(head);
}