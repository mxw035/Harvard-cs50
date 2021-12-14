#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//get comand line argument
int main(int argc, string argv[])
{
    //if only one argument continue
    if (argc == 2)
    {
        //sets cla to key
        int key = atoi(argv[1]);
        //helps continue loop when it gets over 26
        if (key > 26 && key < 52)
        {
            key = key - 26;
            //return key;
        }
        //helps continue key if over 52
        if (key > 52)
        {
            key = key - 52;
        }

        //gets string from user and prints output
        string p = get_string("plaintext: ");
        printf("ciphertext: ");

        //turns string into array of charecters
        for (int i = 0, n = strlen(p); i < n; i++)
        {
            // sets array to int c
            int c = (char) p[i];

            // tells program what to do if lower case
            if (c > 96 && c < 122)
            {
                // adds key if lower case
                int d = c + key;
                // makes sure output is still lowercase
                if (d > 96 && d < 122)
                {

                //prints new lower case cipher text
                printf("%c", (char) d);

                }
                //when no longer lower case or upper case changes back to beinging of lower case abc loop
                if (d >= 122)
                {
                    d = (c - 26) + key;
                    printf("%c", (char) d);
                }
            }
            if (c >= 122)
            {
                int e = (c - 26) + key;
                printf("%c", (char) e);
            }
            //helps to print out ' '
            if (c == 32)
            {
                printf(" ");
            }
            //allows '!' to print
            if (c == 33)
            {
                printf("!");
            }
            // allows ',' to print
            if (c == 44)
            {
                printf(",");
            }

            //if upper case tells program what to do
            if (c >= 64 && c < 89)
            {
                int f = c + key;
                printf("%c", (char) f);
            }
            if (c > 89 && c < 96)
            {
                int g = (c - 26) + key;
                printf("%c", (char) g);
            }


        }
        //prints new line
        printf("\n");
    }
    //if no cla is given returns error code of 1
    else
    {
        return 1;
    }
}
