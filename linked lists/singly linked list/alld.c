#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* deletionatbeg(struct node* head)
{
    struct node* ptr = head;
    head = head->next;
    free(ptr);
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

    free(q);
    return(head);
}

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
    struct node* fifth;

    head = (struct node*)malloc(sizeof(struct node*));
    second = (struct node*)malloc(sizeof(struct node*));
    third = (struct node*)malloc(sizeof(struct node*));
    fourth = (struct node*)malloc(sizeof(struct node*));
    fifth = (struct node*)malloc(sizeof(struct node*));

    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=fourth;

    fourth->data=4;
    fourth->next=fifth;

    fifth->data=5;
    fifth->next=NULL;

    head = deletionatbeg(head);
    head = deletionatmid(head,1);
    head = deletionatend(head);
    traverse(head);

}