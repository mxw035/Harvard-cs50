#include <cs50.h> //includes all libraries
#include <stdio.h>
#include <math.h>

int coins = 0; //sets coins to 0
int q = 0; //sets q, d, n ,p all to 0 for test counts
int d = 0;
int n = 0;
int p = 0;

int cashier(int cents); //calls fxn cashier
int change(void); //calls fxn change

int main(void) //defines main fxn
{
    int cents = change(); // creates and sets int cents  by calling change fxn

    if (cents <= 0) //if < 0 prints error message and the calls change fxn again
    {
        printf("please enter a postive number\n");
        cents = change();
    }

    while (cents >= 1) // if equal to or greater than 1
    {
        cents = cashier(cents); //runs cashier fxn
    }


    //printf("Q: %i\n", q);
    //printf("D: %i\n", d);
    //printf("N: %i\n", n);
    //printf("P: %i\n", p);
    printf("%i\n", coins); //after cashier fxn runs prints the total coin count

}

int change(void) //defines the change fxn with no input and an int output
{
    float x = get_float("Change Owed: "); // gets user to input a float for x
    float y = x * 100; // changes x from dollars to cents and assigns to y
    float cents = round(y); // creates float cents of a rounded y

    return cents; //returns cents
}

int cashier(int cents) //defines the cashier fxn
{
    if (cents >= 100) // if cent greater than or eqaul to 1 dollar
    {
        cents = cents - 100;
        coins += 4; // adds 4 quaters and coins to count
        q += 4;
        //printf("qcoins %i\n", coins);
        //printf("qq %i\n", q);
    }
    if (cents >= 25) // if over 25 cents takes a q away from cents and adds to coin count
    {
        cents = cents - 25;
        coins++;
        q++;
        return cents;
    }

    if (cents >= 10) //same for dimes or 10 cents
    {
        cents = cents - 10;
        coins++;
        d++;
        return cents;
    }

    if (cents >= 5) //same for nickles
    {
        cents = cents - 5;
        coins++;
        n++;
        return cents;
    }

    if (cents >= 1) // same for pennys
    {
        cents = cents - 1;
        coins++;
        p++;
        return cents;
    }
    return cents; //returns cents to main fxn


}
