#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
$ ./initials
Regulus Arcturus Black
RAB
*/

int main(void) {
    string name;
    
    do{
        name = get_string();
    } while(name == NULL);
    
    // printf("name: %s\n", name);
    
    if (strlen(name) < 1) exit(1);
    
    char inits[128];
    inits[0] = toupper(name[0]); // assume the first char of the name is a Initial

    int i, j;
    for(i = 1, j = 1; i < strlen(name); i++) {
        if(name[i-1] == ' ') {
            // we got a initial letter
            inits[j] = toupper(name[i]);
            j++;
        }
    }
    inits[j] = '\0';
    printf("%s\n", inits);
    
    return 0;
}