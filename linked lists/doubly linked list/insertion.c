#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

void traversal(struct node* head)
{
    struct node* ptr = head;
    while(ptr!=NULL)
    {
        printf("Element : %d\n",ptr->data);
        ptr=ptr->next;
    }
}

struct node* insertFront(struct node* head, int data) 
{
    struct node* newNode;
    newNode = (struct node*)malloc(sizeof(struct node*));
    newNode->data = data;
    newNode->next = head;
    newNode->prev = NULL;
    return newNode;
}


struct node* insert_mid(struct node* head, int data,int index) 
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node*));
    struct node* p = head;
    int i = 0;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    newNode->data = data;
    newNode->next = p->next;
    newNode->prev=p;
    p->next=newNode;
    return head;
}

struct node* insertatend(int data, struct node* head)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node*));
    struct node* p=head;
    newNode->data=data;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=newNode;
    newNode->next=NULL;
    newNode->prev=p;

    return head;
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
    head->prev=NULL;

    second->data=2;
    second->next=third;
    second->prev=head;

    third->data=3;
    third->next=NULL;
    third->prev=second;

    head = insertFront(head,54);
    head = insert_mid(head,34,2);
    head = insertatend(444,head);
    traversal(head);

}