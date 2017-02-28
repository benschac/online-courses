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


void printChar(int k, int i, char toEncode);
int main(int argc, string argv[]) 
    
{   
    // Error handling if argc is not 1
    if(argc != 2 || argc == 1) 
    {
        printf ("Usage: /home/cs50/pset2/caesar <key>\n");
        return 1;
    } 
    else 
    {
     // command line arg and string for conversion.
     int k = atoi(argv[1]);
     string p = GetString();
     // loop through string.
        for(int i = 0, n = strlen(p); i < n; i++)
        {
            // this whole else block handles argc larger than 25 with remainer
            if(k > 25)
            {
                k = k % 26;
                printChar(k, i, p[i]);
                 
            }
            else
            {
                printChar(k, i, p[i]);
            }
         }
         printf("\n");
         return 0;
     }
}

void printChar(int k, int i, char toEncode)
{
        // handles argv < 25
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
