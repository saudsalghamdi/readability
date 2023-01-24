#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
int letters = 0;
int words = 1; // set at 1 because it won't calculate the first word
int sentences = 0;
int index = 0;
string text = get_string("Text: ");


// this loop will go throw the given text letter by letter to count number of words, sentences and letters.
for (int i = 0; i < strlen(text); i++)
{
    if (isalpha(text[i]))
    {
        letters++;
    }
    else if (text[i] == ' ')
    {
        words++;
    }
    else if (text[i] == '!' || text[i] == '?' || text[i] == '.')
    {
        sentences++;
    }
}
//printf("%i \n", letters);
//printf("%i \n", words);
//printf("%i \n", sentences);

float L = letters / (float)words * 100;
float S = sentences / (float)words * 100;

index = round(0.0588 * L - 0.296 * S - 15.8);

if (index < 1)
{
    printf("Before Grade 1\n");
}
else if (index > 16)
{
    printf("Grade 16+");
}
else
{
    printf("Grade %i\n", index);
}

}