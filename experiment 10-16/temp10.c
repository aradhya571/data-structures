#include <stdio.h>
int MAXSIZE = 3;
int stack[3];
int top = -1;

/* Check if the stack is empty */
int isempty(){
   if(top == -1)
      return 1;
   else
      return 0;
}

/* Check if the stack is full */
int isfull(){
   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

/* Function to delete from the stack */
int pop()
{
    int data;
    if(!isempty()) 
    {
        data = stack[top];
        top = top - 1;
        return data;
    } 
    else 
    {
        printf("Could not retrieve data, Stack is empty.(Underflow)\n");
        return 0;
   }
}

/* Function to insert into the stack */
int push(int data)
{
    if(!isfull()) 
    {
        top = top + 1;
        stack[top] = data;
    } 
    else 
    {
        printf("Could not insert %d, Stack is full.(Overflow)\n",data);
    }
}

void display()
{
    int c =1;
    while(c<6) {
        int data = pop();
        if(data)
            printf("%d\n",data);
        c++;
    }
}

void main()
{
    for(int i=1;i<6;i++)
        push(i);

    printf("Displaying Elements: \n");
    display();
}