#include<stdio.h>
#include<cs50.h>

int main(void)
{
//get value from user
    int h;
    do
    {
        h = get_int("how tall is your pyramid? ");
    }
    while (h<1);

//build the pyramid using a nested loop

for (int i = 0; i<h; i++)
{
    //left side
    for (int x = 0; x<h-i; x++)
    {
        printf(" ");
    }
    for (int x = 0; x <= i; x++)
    {
        printf("#");
    }

    //gap in the middle
    printf("  ");

    //right side
    for (int x = 0; x<=i; x++)
    {
        printf("#");
    }

    //end of line 
    printf("\n");
}
}