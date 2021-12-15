def main():  # defines main fxn
    # runs both get_height and draw fxn
    height = get_height()
    draw(height, height)

# defines the draw fxn


def draw(height, h):
    # if the height is 0 is the base case consider complete
    if height == 0:
        return
    # calls recurision of the draw fxn till height is 0
    draw(height - 1, h)
    # prints spaces x the height - h which would be 0 and then stops the making of a new line
    print(" " * (h - height), end="")
    # prints '#' times the amount of hieght
    print("#" * height)

# defines the get_height fxn


def get_height():
    # while true
    while True:
        # should try
        try:
            # get height value from user
            height = int(input("Height: "))
            # make sure height is between 0 - 9
            if height > 0 and height < 9:
                # if the height is 0 -9 then break the true loop this is the base case
                break
        # else continue
        except ValueError:
            None
    # return height to main fxn
    return height


main()
