#include <cs50.h>// gets cs50 libarary
#include <stdio.h>// get std i and o libaray

int main(void)// starts code lile click green flag in scratch
{
    string answer = get_string("What is your name?\n");// gets user name

    printf("Hello, %s", answer);// greets user
    printf("\n");// makes new line
}
