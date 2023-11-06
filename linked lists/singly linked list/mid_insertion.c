#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

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

void traversal(struct node* ptr)
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

    head = (struct node*)malloc(sizeof(struct node*));
    second = (struct node*)malloc(sizeof(struct node*));
    third =(struct node*) malloc(sizeof(struct node*));


    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=NULL;

    head = insertmid(43,1,head);
    traversal(head);
}