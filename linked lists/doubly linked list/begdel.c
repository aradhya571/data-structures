#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* deletionatbeg(struct node* head)
{
    struct node* ptr = head;
    head = head->next;
    free(ptr);
    ptr=NULL;
    head->prev=NULL;
    return(head);
}

void traversal(struct node* head)
{
    struct node* ptr = head;
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

    head = deletionatbeg(head);
    traversal(head);

}