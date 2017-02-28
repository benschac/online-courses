/**
* mario.c (pset1)
* Benjamin Schachter
* benschac@gmail.com
* 
*
* This program will print a mario style pyramid based off the users input.
*
*       ##
*      ###
*     #### 
*    #####    
*/
#include <cs50.h>
#include <stdio.h>

/**
*    The main function takes input and:
*    1. Validates input.
*    2. Prints spaces based on spec.
*    3. Prints #s based on spec. 
*/

int main(void) 
{
    int height;
    
    do
    {
        printf("Height Please: ");
        height = GetInt();
    } while(height < 0 || height > 23);
    

    
    for(int i = 0; i < height; i++) 
    {
        int width = height - 1;   
        int hash = 0;
        
        while(width > i) {
            printf(" ");
            width--;
        }
        
        while(hash < i + 2) {
            printf("#");
            hash++;
        } 
       
       printf("\n");  
    }
    

}

