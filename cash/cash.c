#include <cs50.h>
#include <stdio.h>

 int get_cents(void);
 int calculate_quarters(int c);
 int calculate_dimes(int c);
 int calculate_nickels(int c);
 int calculate_pennies(int c);


int main(void)
{
    // Ask how many cents the customer is owed
    int c = get_cents();

    // Calculate the number of quarters to give the customer
    int q = calculate_quarters(c);
    c = c - q * 25;

    // Calculate the number of dimes to give the customer
    int d = calculate_dimes(c);
    c = c - d * 10;

    // Calculate the number of nickels to give the customer
    int n = calculate_nickels(c);
    c = c - n * 5;

    // Calculate the number of pennies to give the customer
    int p = calculate_pennies(c);
    c = c - p * 1;

    // Sum coins
    int sum = q + d + n + p;

    // Print total number of coins to give the customer
    printf("%i\n", sum);
}

int get_cents(void)
{
    int cent;
    do
    {
    cent = get_int("how many cents? ");
    }
    while (cent<1);
    return cent;
}



int calculate_quarters(int c)
{
    int q;
    if (c>=25)
    {
       q = c/25;
    }
    else {
        q=0;
    }
    return q;

}

int calculate_dimes(int c)
{
    int d;
    if (c>=10)
    {
        d = c/10;
    }
    else{
        d=0;
    }
    return d;
}

int calculate_nickels(int c)
{
    int n;
    if (c>=5)
    {
        n = c/5;
    }
    else {
        n=0;
    }
    return n;
}

int calculate_pennies(int c)
{
    int p;
    if (c>=1)
    {
        return p = c;
    }
    else{
    return p=0;
    }
    return p;
}
