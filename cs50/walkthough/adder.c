#include <cs50.h>
#include <stdio.h>

int main(void) {
    printf("Give me an intiger\n");
    int x = GetInt();
    
    printf("Give me another int\n");
    int y = GetInt();
    
    printf("The sum of %d and %d is %d\n",x,y,x+y);
}
