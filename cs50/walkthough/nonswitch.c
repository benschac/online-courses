#include <cs50.h>
#include <stdio.h>

int main(void) {

    printf("Give me an intiger between 1-10: ");
    int n = GetInt();
    
    if(n >= 1 && n <=3) {
    
    printf("You picked a small value\n");

    } else if(n >=4 && n <= 7) {
    
    printf("You picked a larger value\n");
    
    } else if(n >= 8 && n <= 10) {
    printf("You picked the largest values\n");
    } else {
    
    printf("That's invalid, try again\n");
    }

}


