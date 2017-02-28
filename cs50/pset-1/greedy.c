/**
* greedy.c (pset1)
* Benjamin Schachter
* benschac@gmail.com
* 
*
* This program will take a positive floating point int and give you the
* correct number of (USD) you would revieve in change.
*/



#include <cs50.h>
#include <stdio.h>
#include <math.h>
/**
    Handles the whole program.
    1. Valdates input.


*/

int main(void) 
{

    float change;
    
    do 
    {
     printf("Give me some change: ");
     change = GetFloat();
    
    } 
    while( change < 0);
    
    // Change float to int and round.
    change = change * 100;
    int i = (int) round(change);
    int count = 0;
    
    // Count coint while i meets any of these conditions.
    while(i >= 25) 
    {
        count++;
        i -= 25;
    }
    
    while( i >= 10) 
    {
        count++;
        i -= 10;
    }
    
    while(i >= 5) 
    {
        count++;
        i -= 5;
    }
    
    while(i >= 1) 
    {
        count++;
        i -= 1;
    }

   
    
    printf("%i\n", count);
    
  }
 

