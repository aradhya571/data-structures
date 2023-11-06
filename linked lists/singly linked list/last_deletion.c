#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* deletionatend(struct node* head)
{
    struct node* ptr = head;
    struct node* qtr = head->next;
    while(qtr->next!=NULL)
    {
        ptr=ptr->next;
        qtr=qtr->next;
    }
    ptr->next=NULL;    
    free(qtr);
    return(head); 
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
    struct node* fourth;

    head = (struct node*)malloc(sizeof(struct node*));
    second = (struct node*)malloc(sizeof(struct node*));
    third = (struct node*)malloc(sizeof(struct node*));
    fourth = (struct node*)malloc(sizeof(struct node*));

    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=fourth;

    fourth->data=4;
    fourth->next=NULL;

    head = deletionatend(head);
    traverse(head);

}