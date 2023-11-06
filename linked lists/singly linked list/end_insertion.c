#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* insertatend(int data, struct node* head)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node*));
    struct node* p=head;
    ptr->data=data;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;

    return head;
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
    struct node* third;

    head = (struct node*)malloc(sizeof(struct node*));
    second =(struct node*) malloc(sizeof(struct node*));
    third=(struct node *)malloc(sizeof(struct node *));

    head->data=23;
    head->next=second;

    second->data=24;
    second->next=third;

    third->data=25;
    third->next=NULL;

    head = insertatend(269,head);
    traverse(head);
}