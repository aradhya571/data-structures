// Write a program to compute minimum/maximum of a given array

#include <stdio.h>

void main()
{
    int A[]={2,4,6,7,9,10,12,15,17};
    int i=0, min=A[0] ,max =0;
    int len = sizeof(A)/sizeof(int);
    for(i=0;i<len;i++)
    {
        if(A[i]<min)
            min = A[i];
        else if(A[i]>max)
            max = A[i];
    }
    printf("Min = %d\nMax = %d",min,max);
}