/**
*
* caesar.c (pset2)
* Benjamin Schachter
* benschac@gmail.com
* 
* This program will take a command line argument (a number)
* and will encrypt a string based off the command line arg.
* based off the number in the command line the string will be encrypted.
* ex. 1 a -> b, c -> d
*/

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



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
                // handle lower case chars.
                if(p[i] >= 'a' && p[i] <= 'z')
                {   
                    // convert chars if not in range.
                    if((p[i] + k) > 'z')
                    {
                        printf("%c", ((p[i]+ k) % 'z') + 'a'- 1);
                    }
                    // convert if chars in range.
                    else 
                    {
                        printf("%c", (p[i] + k));
                    }
                }
                // handle uppercase.
                else if(p[i] >= 'A' && p[i] <= 'Z')
                {
                    // convert chars if not in range.
                    if((p[i] + k) > 'Z')
                    {
                        printf("%c", ((p[i]+ k) % 'Z') + 'A'- 1);
                    } 
                    else
                    {
                        // convert chars if in range.
                        printf("%c", (p[i] + k));
                    }
                }
                // handles special chars that are not converted.
                else
                {
                    printf("%c", p[i]);
                } 
            }
            else
            {
                // handles argv < 25
                if(p[i] >= 'a' && p[i] <= 'z')
                { 
                    // handles lowercase wrap around
                    if((p[i] + k) > 'z')
                    {
                        printf("%c", ((p[i]+ k) % 'z') + 'a'- 1);
                    }
                    else 
                    {   // handles non-wrap around
                        printf("%c", (p[i] + k));
                    }
                }
                // handles uppercase.
                else if(p[i] >= 'A' && p[i] <= 'Z')
                {
                    // wrapping solution
                    if((p[i] + k) > 'Z')
                    {
                        printf("%c", ((p[i]+ k) % 'Z') + 'A'- 1);
                    }
                    // non-wrapping 
                    else
                    {
                        printf("%c", (p[i] + k));
                    }
                }
                // all special chars that aren't changed.
                else
                {
                    printf("%c", p[i]);
                }
            }
         }
         printf("\n");
         return 0;
     }
}
