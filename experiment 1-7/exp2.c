// Write a menu-based program to perform operations on Linear Array: 
// i) Insert an element at the Kth Position. 
// ii) Delete an element from the Kth Position. 
// iii) Traverse an array element. 


#include <stdio.h>

void main()
{
    int A[]={2,4,6,7,9,10,12,15,17};
    int newA[20];
    int i=0, ins ;
    int k1,k2,count=0;
    int choice;
    int len = sizeof(A)/sizeof(int);
    printf("Enter 1 to insert an element at the Kth Position.\nEnter 2 to delete an element from the Kth Position.\nEnter 3 to traverse an array element.\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d",&ins);
            printf("Enter the position to be inserted at : ");
            scanf("%d",&k1);
            for(i=0;i<len+1;i++)
            {
                if(i==(k1-1)){
                    newA[i]=ins;
                    }
                else{
                    newA[i]=A[count];
                    count++;}
            }
             for(i=0;i<len+1;i++)
            {
                printf("%d ",newA[i]);
            }
            break;
        case 2:
            printf("Enter the position of the element to be deleted : ");
            scanf("%d",&k2);
            for(i=0;i<len-1;i++)
            {
                if(i>=(k2-1)){
                    newA[i]=A[count+1];
                    count++;}
                else{
                    newA[i]=A[count];
                    count++;}
            }
            for(i=0;i<len-1;i++)
            {
                printf("%d ",newA[i]);
            }
            break;
        case 3:
            for(i=0;i<len;i++)
            {
                printf("%d ",A[i]);
            }
            break;
        default:
            printf("Invalid choice");
    }
}
