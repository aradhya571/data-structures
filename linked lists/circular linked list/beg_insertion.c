#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* insertion(int data , struct node* head)
{
    struct node* ptr =(struct node*)malloc(sizeof(struct node*));
    ptr->data =data;
    struct node* p = head->next;
    while(p->next!=head)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    head=ptr;

    return head;
}

void traversal(struct node* head)
{
    struct node* ptr = head;
    do{
        printf("Element : %d\n",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
} 

void main()
{
    struct node* head;
    struct node* second;
    struct node* third;

    head = (struct node*)malloc(sizeof(struct node*));
    second = (struct node*)malloc(sizeof(struct node*));
    third = (struct node*)malloc(sizeof(struct node*));

    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=head;

    head = insertion(33,head);
    traversal(head);
}