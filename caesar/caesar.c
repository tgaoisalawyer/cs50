#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
//check command-line arguement
if (argc != 2 ){
    printf("wrong command-line arguement!\n");
    return 1;
}

for (int i = 0; i<strlen(argv[1]); i++)
    if (!isdigit(argv[1][i])){
        printf("Usage: ./caesar key");
        return 1;
    }

//get the correct inputs
int key = atoi(argv[1]);
string plaintext = get_string("plaintext: \n");

//convert plaintext to cipher text
for (int i = 0; i <strlen(plaintext); i++)
{
        if (isupper(plaintext[i])){
            printf("%c", (plaintext[i] - 65 + key)%26 + 65);
            }
        else if (islower(plaintext[i])){
            printf("%c", (plaintext[i] - 97 + key)%26 + 97);
        }
        else{
            printf("%c", plaintext[i]);
        }
        }
printf("\n");
}


