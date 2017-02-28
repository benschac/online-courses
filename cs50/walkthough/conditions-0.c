#include <cs50.h>
#include <stdio.h>

int main(void) {
    printf("Give me int: ");
    int x = GetInt();
    
    if(x > 0) {
        printf("Positive \n");
    } else if( x == 0) {
        printf("Number is zero! \n");    
    } else {
        printf("Negative \n");
    }


}
