// Write a program to check whether the matrix is a sparse matrix or not. 
#include<stdio.h>
#include<stdlib.h>

void main()
{
    int i,j,c1=0,n1=0;
    int rows=0 , col=0;
    printf("Enter rows and columns : \n");
    scanf("%d",&rows);
    scanf("%d",&col);
    int A[rows][col] ;
    printf("Enter matrix elements : \n");
    for(i=0;i<rows;i++)
    {
        for(j=0;j<col;j++)
        {
            scanf("%d",&A[i][j]);
            if (A[i][j]==0)
            { 
                c1=c1+1;  
            }
            else{
                n1 = n1+1;
            }
        }
    }
 
    if(c1>n1){
    printf("Yes, A is a sparse matrix\n");
    }
    else{
    printf("No, A is not a sparse matrix\n");
}
}
