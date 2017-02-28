/**
*
* Vesionare.c (pset2)
* Benjamin Schachter
* benschac@gmail.com
* 
* This program will take a command line argument (a word)
* and will encrypt a string based off the command line arg.
* based off the word in the command line the string will be encrypted.

* word to encrypt     =  doggy
* key                 =  bea
* place's switched    =  2,5,0
* output              =  ftgid  
* 
*/

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void printChar(int k, char toEncode);
int main(int argc, string argv[]) 
    
{   
    // Error handling if argc is not 1
    if(argc != 2 || argc == 1) 
    {
        printf ("Usage: /home/cs50/pset2/vigenere <word>\n");
        return 1;
    }
    
    
    else 
    {
     // command line arg and string for conversion.
     string k = argv[1];
     int n = strlen(k);
     int charValues[n];
     // error handing if key has numbers
     for(int i = 0, n = strlen(k); i < n; i++)
     {
        
        if(k[i] >= '0' && k[i] <= '9')
        {   
           printf("Key cannot have numbers\n");
           return 1;
        }  
     }
     
     string p = GetString();
     
     // getting amount of char places to jump.
     for(int i = 0, n = strlen(k); i < n; i++)
     {
       charValues[i] = k[i];
       if(charValues[i] >= 97 && charValues[i] <= 122)
       {
         charValues[i] = k[i] - 97;
       }
       else
       {
         charValues[i] = k[i] - 65;
       }   
        
     }
     
     
        // loop through string.
        for(int i = 0, j = 0, n = strlen(p), q = strlen(k); i < n; i++, j++)
        {   
            // control for array length of key values
            if( j >= q) {
                j = 0;
            }
            
            // control array count space for non-aphla chars
            if (!isalpha(p[i]))
            {
                j = (j - 1);
            }
                printChar(charValues[j], p[i]);
                
            
            
         }
         printf("\n");
         return 0;
     }
}



void printChar(int k, char toEncode)
{
        
                if(toEncode >= 'a' && toEncode <= 'z')
                { 
                    // handles lowercase wrap around
                    if((toEncode + k) > 'z')
                    {
                        printf("%c", ((toEncode + k) % 'z') + 'a'- 1);
                    }
                    else 
                    {   // handles non-wrap around
                      
                        printf("%c", (toEncode + k));
                    }
                }
                // handles uppercase.
                else if(toEncode >= 'A' && toEncode <= 'Z')
                {
                    // wrapping solution
                    if((toEncode + k) > 'Z')
                    {
                        printf("%c", ((toEncode + k) % 'Z') + 'A'- 1);
                    }
                    // non-wrapping 
                    else
                    {
                        printf("%c", (toEncode + k));
                    }
                }
                // all special chars that aren't changed.
                else
                {
                    printf("%c", toEncode);
                }
}
