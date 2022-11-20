#include <cs50.h>
#include <stdio.h>

int main(void)
{
//ask value from user
    int h;
    do
    {
        h = get_int("How tall is your pyramid? ");
    }
    while(h < 1);

//build pyramids
for (int i=1; i<=h; i++)
{
    for (int x = 1; x <= h-i; x++)
    {
        printf(" ");
    }
    for (int x = 1; x <= i; x++)
    {
        printf("#");
    }
    printf("\n");
}
}