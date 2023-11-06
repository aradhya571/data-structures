 #include<stdio.h>
#include<stdlib.h>

// int fact(int n , int a)
// {
//     if(n==0 || n==1)
//     {
//         return a;
//     }
//     else{
//         return fact(n-1,n*a);
//     }
// }

// void main()
// {
//     int n  =6 ,a =1;
//     printf("fact = %d",fact(n,a));

// }

int fib(int n , int a,int b )
{
    if(n==0)
    {
        return a;
    }
    else if(n==1)
    {
        return b;
    }
    else{
        return fib(n-1,b,a+b);
    }
}

void main()
{
    int n = 6 , a=0 , b=1;
    printf("fib : %d",fib(n,a,b));
}