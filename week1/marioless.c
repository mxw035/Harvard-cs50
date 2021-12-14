#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //get int fxn for user input for height

    int h;
    {



            h = get_int("Height:");

            if (h <=8 && h >=1)
            ;

            else h = get_int("Height:")
            ;

    switch(h)
        {
            case 1:
            printf("#\n");
            break;
            case 2:
            printf(" #\n##\n");
            break;
            case 3:
            printf("  #\n ##\n###\n");
            break;
            case 4:
            printf("   #\n  ##\n ###\n####\n");
            break;
            case 5:
            printf("    #\n   ##\n  ###\n ####\n####\n");
            break;
            case 6:
            printf("     #\n    ##\n   ###\n  ####\n #####\n######\n");
            break;
            case 7:
            printf("      #\n     ##\n    ###\n   ####\n  #####\n ######\n#######\n");
            break;
            case 8:
            printf("       #\n      ##\n     ###\n    ####\n   #####\n  ######\n #######\n########\n");
        }
        }


    }

