#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* insert(int data,struct node* head)
{
    struct node* nhead;
    nhead = (struct node*)malloc(sizeof(struct node*));
    nhead->data=data;
    nhead->next=head;
    return nhead;
}

void traverse(struct node* ptr)
{
    while(ptr!=NULL)
    {
        printf("Element : %d\n",ptr->data);
        ptr=ptr->next;
    }
}

void main()
{
    struct node* head;
    struct node* second;

    head = (struct node*)malloc(sizeof(struct node*));
    second = (struct node*)malloc(sizeof(struct node*));

    head->data=3;
    head->next=second;

    second->data=98;
    second->next=NULL;

    head = insert(77,head);
    traverse(head);

}