#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>



int main(void) 
{
    string name = GetString();
    
    for(int i = 0, n = strlen(name); i < n; i++) 
    {
          if(name[i] == ' ')
          {
            printf("%c", toupper(name[i + 1]));
           }
        
        
        if(i < 1)
        {
        
        printf("%c", toupper(name[i]));
        
        } 
        
        
        
    }
    
    printf("\n");
    
}

