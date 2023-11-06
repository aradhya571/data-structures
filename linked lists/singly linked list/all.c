#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* beginsert(int data,struct node* head)
{
    struct node* nhead;
    nhead = (struct node*)malloc(sizeof(struct node*));
    nhead->data=data;
    nhead->next=head;
    return nhead;
}

struct node* insertmid(int data,int index,struct node* head)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node*));
    struct node* p=head;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next = p->next; 
    p->next=ptr;

    return head;
}

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

    head = (struct node*)malloc(sizeof(struct node*));
    second = (struct node*)malloc(sizeof(struct node*));

    head->data=1;
    head->next=second;

    second->data=2;
    second->next=NULL;

    head = beginsert(3,head);
    head = insertmid(4,2,head);
    head = insertatend(5,head);
    traverse(head);

}