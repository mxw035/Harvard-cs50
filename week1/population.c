#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start; //input for start size
    {
        do
        {
        start = get_int("Start size: ");
        }
        while (start <9);
    }

    int end; // intput for end size
    {
        do
        {
            end = get_int("End Size: ");
        }
        while (end < start);
    }
    // keep track of years
    int years = 0;

    while (start < end)
    {
        start= start + (start/3) - (start/4); // add to population
        years++;
    }
// print years
    printf("Years: %i\n", years);
}
