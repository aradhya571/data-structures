#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    int expo;
    struct node* next;
};

struct node* insertatend(int data,int expo, struct node* head)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node*));
    struct node* p=head;
    ptr->data=data;
    ptr->expo=expo;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;

    return head;
}

struct node* add(struct node* head1 , struct node* head2)
{
    struct node* new = (struct node*)malloc(sizeof(struct node));
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    struct node* head3;
    while(ptr1!=NULL)
    {
        if(ptr1->expo==ptr2->expo)
        {
            new->data=ptr1->data + ptr2->data;
            new->expo=ptr1->expo;
            head3 = insertatend(new->data,new->expo,head3);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        else if(ptr1->expo > ptr2->expo)
        {
                new->data=ptr1->data;
                new->expo=ptr1->expo;
                head3 = insertatend(new->data,new->expo,head3);
                ptr1=ptr1->next;
        }
        else if(ptr1->expo < ptr2->expo)
        {
                new->data=ptr2->data;
                new->expo=ptr2->expo;
                head3 = insertatend(new->data,new->expo,head3);
                ptr2=ptr2->next;
        }
    }
    do
    {
        new->data=ptr2->data;
        new->expo=ptr2->expo;
        head3 = insertatend(new->data,new->expo,head3);
        ptr2=ptr2->next;
    }while(ptr2!=NULL);

    return new;
}

void traversal(struct node* new)
{
    struct node* ptr = new;
    while(ptr!=NULL)
    {
        printf("%dx%d",ptr->data,ptr->expo);
        ptr=ptr->next;
    }
}

void main()
{
    struct node* new;
    struct node* head1;
    struct node* second1;
    struct node* third1;

    struct node* head2;
    struct node* second2;
    struct node* third2;
    struct node* fourth2;

    head1 = (struct node*)malloc(sizeof(struct node));
    second1 = (struct node*)malloc(sizeof(struct node));
    third1 = (struct node*)malloc(sizeof(struct node));

    head2 = (struct node*)malloc(sizeof(struct node));
    second2 = (struct node*)malloc(sizeof(struct node));
    third2 = (struct node*)malloc(sizeof(struct node));
    fourth2 = (struct node*)malloc(sizeof(struct node));

    head1->data=5;
    head1->expo=6;
    head1->next=second1;
    
    second1->data=6;
    second1->expo=4;
    second1->next=third1;
    
    third1->data=2;
    third1->expo=3;
    third1->next=NULL;

    head2->data=8;
    head2->expo=6;
    head2->next=second2;
    
    second2->data=3;
    second2->expo=2;
    second2->next=third2;
    
    third2->data=4;
    third2->expo=1;
    third2->next=fourth2;
    
    fourth2->data=5;
    fourth2->expo=0;
    fourth2->next=NULL;

    new = add(head1,head2);
    traversal(new);
}