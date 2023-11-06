// Write a program to print Fibonacci series using Recursion?
#include<stdio.h>
#include<stdlib.h>

int fib(int n)
{
    if (n<=1){
        return n;
    }
    else{
        // printf("%d ",(fib(n-1)+fib(n-2)));
        return (fib(n-1) + fib(n-2));
    }
}

void printfib(int n) 
{
    for (int i = 0; i < n; i++)
        printf("%d ", fib(i));
}

void main()
{
    int n ;
    printf("Enter no. of terms : \n");
    scanf("%d",&n);
    printfib(n);
}
