#include <stdio.h>
void main()
{
    int a[10][10],tran[10][10],r,c;
    printf("Enter rows & columns : ");
    scanf("%d%d",&r,&c);
    printf("\nEnter matrix elements : \n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("The resultant matrix after transpose of A is : \n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            tran[i][j] = a[j][i];
            printf("%d ",tran[i][j]);
        }
        printf("\n");
    }
}