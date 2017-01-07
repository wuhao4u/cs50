#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

void crack(string hashed);
void crack_recur(char pool[],char new_str[],int current_len,int n,int len,char hashed[]);

#define POOL "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"

int main(int argc, const string argv[]) {
    if(argc != 2) {
        printf("Usage: ./crack hash\n");
        return 1;
    }
    
    string hashed = argv[1];
    
    crack(hashed);

    return 0;
}

void crack(string hashed) {
    char placeholder[5] = "";
    unsigned int poolSize = strlen(POOL);

    crack_recur(POOL, placeholder, 0, poolSize, 1, hashed);
    crack_recur(POOL, placeholder, 0, poolSize, 2, hashed);
    crack_recur(POOL, placeholder, 0, poolSize, 3, hashed);
    crack_recur(POOL, placeholder, 0, poolSize, 4, hashed);
}

// crack_recur function was inspired by following links:
// http://bit.ly/2iUC8PM
// http://bit.ly/1r01VFY
// http://bit.ly/2i36J9j
void crack_recur(char pool[],char prefix[],int current_len,int n,int len,char hashed[])
{

    /*
    pool=orignal set,
    prefix=empty char array,
    current_len=0(Intially)
    n=no of elements to be used (pool length)
    len=number of positions in the password
    hashed=the given hashing value(to check)*/

    if(current_len==len)
    {
        if (strcmp(crypt(prefix, "50"), hashed) == 0) {
            printf("%s\n",prefix);
            exit(0);
        }
    }
    else
    {
        int i;
        for(i=0;i<n;i++)
        {
            prefix[current_len]=pool[i];
            crack_recur(pool,prefix,current_len+1,n,len,hashed);
        }
    }
}
