#include <cs50.h>
#include <stdio.h>

int main(void) {
    printf("Give me int");
    
    int n = GetInt();
    
    switch (n) {
        case 1:
        case 2:
        case 3: 
            printf("small int\n");
            break;
        case 4:
        case 5:
        case 6:
        case 7:
            printf("medium\n");
            break;
        case 8:
        case 9:
        case 10:
            printf("Large\n");
            break;
            
        default:
            printf("You picked an invalid int!\n");
    }
}
