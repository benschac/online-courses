#include <cs50.h>
#include <stdio.h>

int plusOne(int x);

int main(void) {
    int q = 5;    
    q = plusOne(q);
    
    for(int i = 0; i < 5; i++) {
        
        printf("%i\n", plusOne(i)); 
    }
    
       

}

int plusOne (int x) {
    return x * x;
}
