#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


int main(void)
{
//get a sample from user
string sample = get_string("sample text: ");



//number of letters in sample
int character = strlen(sample);
float letter = 0;
for (int i = 0; i < character; i++)
{
    if (sample[i]<=90 && sample[i] >= 65){
        letter += 1;
    }
    if (sample[i]<= 122 && sample[i]>=97){
        letter += 1;
    }
}



//number of words in sample
float number_of_space = 0.0;
for (int i = 0; i < character; i++)
{
    if (sample[i] == 32){
        number_of_space += 1.0;
    }
}
float word = number_of_space + 1;




//number of sentences in sample
int number_of_period = 0;
for (int i = 0; i < character; i++)
{
    if (sample[i] == 46 || sample[i] == 33 || sample[i] == 63){
        number_of_period += 1.0;
    }
}
float sentence = number_of_period;



// get L
float L = (letter * (100 / word));
//get S
float S = (sentence * (100 / word));
float index = 0.0588 * L - 0.296 * S - 15.8;


//print answer
if (index < 1)
{
    printf("Before Grade 1\n");
}
else if (index > 16)
{
    printf("Grade 16+\n");
}
else
{
    printf("Grade %i\n", (int) round(index));}
}