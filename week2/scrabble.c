#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet what if i changed the
// elements to look like a = 1
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!");
    }
    else
    {
        printf("Tie!");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int score = 0; //setting the score to 0 to start

    for (int i = 0, len = strlen(word); i < len; i++) // sets i to 0, sets len to strlen, than one adds one
        // by add one does it look at the next char in the string?
        //i represents the index of the char.
    {
        if (isupper(word[i])) // states that if the given word is an upper case follow this fxn
        {
            score += POINTS[word[i] - 'A']; // score which is 0 +- the points from word minus the 'A' which is? 65
            //we need to translate the ascii values into 0 1 2 ?


        }
        else if (islower(word[i])) // follow this if lower case
        {
            score += POINTS[word[i] - 'a'];
        }
    }
    return score;
}
