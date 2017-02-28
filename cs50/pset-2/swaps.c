#include <cs50.h>
#include <stdio.h>


int main(void)
{
 
 printf("Here are some swaps: ");
 int x = GetInt();
 int y = GetInt();
 
 
 printf("%i", x);
 printf("%i", y);
 swaps(1, 2);
 
 printf("%i", x);
 printf("%i", y);   
}

void swaps(int x, int y)
{
    int tmp = x;
     x = y;
     y = x;
    
    printf("x %c, y %c", x, y); 
}



