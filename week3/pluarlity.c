#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    for (int i = 0; i < 9; i++)
    {
        if (strcmp(candidates[0].name, name) == 0)
        {
            //printf("Found\n");
            candidates[0].votes++;
            return true;
        }
        if (strcmp(candidates[1].name, name) == 0)
        {
            //printf("Found\n");
            candidates[1].votes++;
            return true;
        }
        if (strcmp(candidates[2].name, name) == 0)
        {
            //printf("Found\n");
            candidates[2].votes++;
            return true;
        }
        if (candidates[0].name != name && candidates[1].name != name && candidates[2].name != name)
        {
            //printf("Invalid vote");
            return false;
        }

    }
    return false;
}


// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    if (candidates[0].votes > candidates[1].votes && candidates[0].votes > candidates[2].votes)
    {
        printf("%s\n", candidates[0].name);
    }
    else if (candidates[1].votes > candidates[0].votes && candidates[1].votes > candidates[2].votes)
    {
        printf("%s\n", candidates[1].name);
    }
    else if (candidates[2].votes > candidates[0].votes && candidates[2].votes > candidates[1].votes)
    {
        printf("%s\n", candidates[2].name);
    }
    else if (candidates[0].votes == candidates[1].votes && candidates[0].votes > candidates[2].votes)
    {
        printf("%s \n%s \n", candidates[0].name, candidates[1].name);
    }
    else if (candidates[0].votes == candidates[2].votes && candidates[0].votes > candidates[1].votes)
    {
        printf("%s \n%s \n", candidates[0].name, candidates[2].name);
    }
    else if (candidates[1].votes == candidates[2].votes && candidates[1].votes > candidates[0].votes)
    {
        printf("%s \n%s \n", candidates[1].name, candidates[2].name);
    }
    else if (candidates[1].votes == candidates[0].votes && candidates[1].votes > candidates[2].votes)
    {
        printf("%s \n%s \n", candidates[1].name, candidates[0].name);
    }
    else if (candidates[2].votes == candidates[0].votes && candidates[2].votes > candidates[1].votes)
    {
        printf("%s \n%s \n", candidates[2].name, candidates[0].name);
    }
    else if (candidates[2].votes == candidates[1].votes && candidates[2].votes > candidates[0].votes)
    {
        printf("%s \n%s \n", candidates[2].name, candidates[1].name);
    }
    else if (candidates[0].votes == candidates[1].votes && candidates[0].votes == candidates[2].votes &&
             candidates[1].votes == candidates[2].votes)
    {
        printf("%s\n%s\n%s\n", candidates[0].name, candidates[1].name, candidates[2].name);
    }
    return;
}
