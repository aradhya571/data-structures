// Write a program which counts number of words, lines and characters in a given text.
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int words=0 , lines=0 , chars=0;
    char ch=' ';
    printf("Enter the string : ");
    while((ch = getchar()) != '\n') 
    {
        if(ch == ' ')
        words++;
        if (ch=='\n')
        {
            lines++;
        }
        chars++;
    }
    printf("\nNumber Of Words: %d\t Number Of Lines:%d \t Number Of Characters:%d",words+1,lines + 1,chars);
    return  0;
}
    
    
