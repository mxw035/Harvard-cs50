from cs50 import get_float


def main():
    # defines the main fxn
    # sets var coins to 0; can py have gloabal vars?
    coins = 0
    cents = change()
    # need to call cashier fxn
    if cents >= 1:
        while cents >= 1:
            # set cents = to the out put of cashier
            # add to the coin counter
            coins += 1
            cents = cashier(cents)
            # also get the new coin value from cashier fxn
            if cents == 0:
                break

    else:
        return change()

    print(coins)


def change():
    # x is the float input provided by user
    x = get_float("Change owed: ")
    # y is x multiplied by 100 to change it from dollars to cents
    y = x * 100
    # cents is the var that is rounded y
    cents = round(y)
    return cents


def cashier(cents):

    if cents > 24:
        cents = cents - 25
        return cents

    elif cents > 9:
        cents = cents - 10
        return cents

    elif cents > 4:
        cents = cents - 5
        return cents

    elif cents > 0:
        cents = cents - 1
        return cents
    else:
        return cents


main()
