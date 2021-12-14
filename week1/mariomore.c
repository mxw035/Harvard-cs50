#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h; // defining varialbe

    h = get_int("Height:"); // getting use input

    if (h <= 8 && h >= 1) // setting define range for h
        ;

    else
        h = get_int("Height:") // if not in define range having user re enter
            ;



    switch (h) // making the case allows user input to determine height break; ends program
    {
        case 8:
            printf("       #  #\n      ##  ##\n     ###  ###\n    ####  ####\n   #####  #####\n  ######  ######\n #######  #######\n########  ########\n");
            break;
        case 7:
            printf("      #  #\n     ##  ##\n    ###  ###\n   ####  ####\n  #####  #####\n ######  ######\n#######  ########\n");
            break;
        case 6:
            printf("     #  #\n    ##  ##\n   ###  ###\n  ####  ####\n #####  #####\n######  ######\n");
            break;
        case 5:
            printf("     #  #\n    ##  ##\n   ###  ###\n #####  #####\n######  ######\n");
            break;
        case 4:
            printf("   #  #\n  ##  ##\n ###  ###\n####  ####\n");
            break;
        case 3:
            printf("  #  #\n ##  ##\n###  ###\n");
            break;
        case 2:
            printf(" #  #\n##  ##\n");
            break;
        case 1:
            printf("#  #\n");
            break;
    }
}
