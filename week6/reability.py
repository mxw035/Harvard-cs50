# calls python libraries string and re also gets get_string from cs50 library
import string
import re

from cs50 import get_string


def main():
    # defines main fxn
    x = get_string("Text: ")
    # gets var x from user
    # based on user input for x determines letters, words and sentences by looking for alpha chars, whitespace and puc in x
    letters = len(re.findall('[a-zA-z]', x))
    words = len(x.split())
    sentences = len(re.findall(r'[!.?]+', x))
    # moves on to fxn index with input letters, words, sentences and output of index = g
    g = index(letters, words, sentences)
    # moves on to fxn grade with input int g
    grade(g)


def index(letters, words, sentences):
    # defines index fxn
    # gets words per 100
    w100 = words / 100
    # gets letters per 100 words
    L = letters / w100
    # gets sentences per 100 words
    S = sentences / w100
    # applys to the Coleman-Liau index
    index = round(0.0588 * L - 0.296 * S - 15.8)
    # returns the value of index to main fxn
    return index


def grade(g):
    # defines grade fxn with input of g
    # if g is < 1 then consider it below first grade reading level
    if g < 1:
        print("Before Grade 1")
    elif g >= 16:
        # if over 16 consider 16 +
        print("Grade 16+")
    else:
        # else consider it the grade as stated, ex g = 5 means grade 5 reading level
        print(f"Grade {g}")


main()
