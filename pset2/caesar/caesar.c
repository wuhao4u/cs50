#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void encipher(string originText, int k);

int main(int argc, char* argv[]) {
    char* plainTxt;
    int k = 0;

    // read arguments
    // USAGE: ./caesar k
    if (argc != 2) {
        printf("USAGE: ./caesar k\n");
        return 1;
    } else {
        k = atoi(argv[1]) % 26;
    }
    
    printf("plaintext: ");
    do {
        plainTxt = get_string();
    } while (plainTxt == NULL);
    
    encipher(plainTxt, k);
    
    return 0;
}

void encipher(string ot, int k) {
    if(k <= 0) {
        return;
    }

    // placeholder for the return value
    char ret[128];
    int pos, i;

    for (i = 0; i < strlen(ot); ++i) {
        pos = 0;

        if(isalpha(ot[i]))
        {
            pos = ot[i] + k;

            if (isupper(ot[i])) {
                // upper case A->65, Z->90
                if (pos > 90) {
                    pos = pos % 90 + 64;
                }
                ret[i] = pos;
            } else if (islower(ot[i])) {
                // lower case a->97, z->122
                if (pos > 122) {
                    pos = pos % 122 + 96;
                }
                ret[i] = pos;
            }
        } 
        else
        {
            ret[i] = ot[i];
        }
    }
    ret[i] = '\0';

    printf("ciphertext: %s\n", ret);
}