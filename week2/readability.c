#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

//calculate index

int main(void)
{
    //get input
    string text = get_string("Text: ");

    //set int to 0
    int letters = 0 ;
    int words = 0 ;
    int sentences = 0 ;

    int l = strlen(text);

    //for loop to look at char
    for (int x = 0; x < l; x++)
    {
        char c = text[x];
        if (isalpha(c) != 0)
        {
            letters++;
        }
        if (c == '.' || c == '?' || c == '!')
        {
            sentences++;
        }
        if (c == ' ')
        {
            words++;
        }
    }
    //add 1 to words
    words = words + 1;

    //check results before calc
    //printf("Letters:%i\n", letters);
    //printf("Words: %i\n", words);
    //printf("Sentences:%i\n", sentences);


    //math for L letters per 100 words.
    float a = (float)letters / (float)words;
    //printf("a: %f\n", a);
    float L = a * 100;
    //printf("L: %f\n", L);

    //math for S sentences per 100 words
    float b = (float)sentences / (float)words;
    //printf("b:%f\n", b);
    float S = b * 100;
    //printf("S:%f\n", S);

    //complete equation with L and S for index

    float t = 0.0588 * L;
    float u = 0.296 * S;
    float index = t - u - 15.8;
    index = round(index);

    //before grade1
    if (index < 1)
    {
        printf("Before Grade 1");
    }
    //after grade 16
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) index);
    }



}
