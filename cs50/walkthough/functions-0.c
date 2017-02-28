#include <cs50.h>
#include <stdio.h>

void PrintName(string name);

int main(void) {
    printf("What's your name?");
    string s = GetString();
    
    
    PrintName(s);

}

void PrintName(string name) {
    printf("Hello, %s\n", name);
}
