// Write a program to perform following operations in matrix: 
// a. Addition 
// b. Subtraction 
// c. Multiplication 
// d. Transpose 

#include <stdio.h>
void main()
{
    int A[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int B[3][3]={{1,2,3},{4,1,6},{7,8,0}};
    int C[3][3] , D[3][3] , E[3][3] , F[3][3] ;
    int i,j,k;
    int sum=0 ,mul=0 , sub=0 , trans=0;
    int len = sizeof(A)/sizeof(int);
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            mul=0;
            sum=0;
            sub=0;
            sum = sum + A[i][j]+B[i][j];
            sub = sub + A[i][j]-B[i][j];
            for(k=0;k<3;k++)
            {
                mul = mul+ A[i][k]*B[k][j];
                
            }
            C[i][j]=mul;
            D[i][j]=sum;
            E[i][j]=sub;
            F[i][j]=A[j][i];
        }
    }
    printf("The resultant matrix after addition is : \n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",D[i][j]);
        }
        printf("\n");
    }
    printf("The resultant matrix after subtraction is : \n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",E[i][j]);
        }
        printf("\n");
    }
    printf("The resultant matrix after multiplication is : \n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        { 
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }
    printf("The resultant matrix after transpose of A is : \n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",F[i][j]);
        }
        printf("\n");
    }
}