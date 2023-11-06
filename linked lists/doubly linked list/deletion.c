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

struct node* deletionatmid(struct node* head,int index)
{
    struct node* p = head;
    struct node* q = head->next;
    int i=0;
    while(i!=index-1)
    {
        p=p->next; 
        q=q->next;
        i++;
    }
    p->next=q->next;
    p->prev=p->prev;

    free(q);
    return(head);
}


struct node* deletionatend(struct node* head)
{
    struct node* ptr = head;
    struct node* qtr;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    qtr = ptr->prev;
    qtr->next=NULL;    
    free(ptr);
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
    struct node* fourth;

    head = (struct node*)malloc(sizeof(struct node*));
    second = (struct node*)malloc(sizeof(struct node*));
    third = (struct node*)malloc(sizeof(struct node*));
    fourth = (struct node*)malloc(sizeof(struct node*));

    head->data=1;
    head->next=second;
    head->prev=NULL;

    second->data=2;
    second->next=third;
    second->prev=head;

    third->data=3;
    third->next=fourth;
    third->prev=second;
    
    fourth->data=4;
    fourth->next=NULL;
    fourth->prev=third;

    head = deletionatbeg(head);
    head = deletionatmid(head,2);
    head = deletionatend(head);
    traversal(head);

}