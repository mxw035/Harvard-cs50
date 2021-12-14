#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name)) // calls on the voter fxn to check to make sure name matches
            {
                printf("Invalid vote.\n"); //if name dosent match produces invalid vote
                return 4;
            }
        }

        printf("\n"); //prints new line
    }

    // Keep holding runoffs until winner exists
    while (true) //while vote fxn returns true meaning a match happens continue on to tabulate fxn
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner(); //setting a bool varible to the outcome of the print winner fxn if it is one so p _w returned
        //true then stop program
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie) // if true return from tie fxn
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    bool exist = false; // set the bool varibale of exist to flase
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            preferences[voter][rank] = i;
            exist = true; // if matches changes exist to tru
            break;
        }
    }
    return exist; // returns exist to main fxn what is with exist?
}

// Tabulate votes for non-eliminated candidates
void tabulate(void) // tabulate fxn takes no input returns no values
{
    for (int i = 0; i < voter_count; i++) //setting int i to the for the preferences found in global why we need noo input
    {
        for (int j = 0; j < candidate_count; j++) // setting j for the rank of the global preferences fxn
        {
            if (candidates[preferences[i][j]].eliminated == false) //makes sure candidate is still in the running
            {
                candidates[preferences[i][j]].votes += 1; // adds one to the vote counts
                break; //need this so the program is not stuck in a forever loop
            }
        }
    }
    // TODO
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void) //looking of bool output true or false

{
    //look at candidates vote totals
    for (int i = 0; i < candidate_count; i ++) // sets i array for the length of candidate count
    {
        string most = candidates[i].name; // makes the variable of a string that looks at the array of candidates names
        //then compares the votes of those candidates to see if over 50 % of the votes
        if (candidates[i].votes > (voter_count / 2)) // checks to see if equal to 50 % of the voter count
            //if so prints winner and returns true :)
        {
            printf("%s\n", most);
            return true;
        }
    }
    // TODO
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void) //looking to int output int the form of samllest number of votes
{
    int min = voter_count; //makes the min equal to the voter_count which is the number of votes

    for (int i = 0; i < candidate_count; i ++) // sets the array to look through based on number of candidates should it be voters?
    {
        if (candidates[i].eliminated == false && candidates[i].votes < min) // looks to see if eliminated if not compares

            //candidate votes to min votes if less than min
        {
            min = candidates[i].votes; //resets min to the minimum candidate votes
            //return min; // returns the min int to the main fxn
        }
    }
    return min;

    // TODO
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min) // this is a fxn called tie with an input of main and and output of bool
{
    //takes in int min
    for (int i = 0; i < candidate_count; i++) //sets array for int i the length of candidate count
    {
        if (candidates[i].eliminated == false && candidates[i].votes != min) //cant be seperate like i had them needs to be both to
            //be returned true. changed == to != indicating that only if the votes where not equal to min did we move on
        {
            return false; //if both things are met, candidate is not elinimated and votes do not equal min return false or not tied
        }
    }

    //compares min to the votes
    //if left over candidates have same votes = tie and returns true
    // TODO
    return true; // other wise return true
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min) // is the eliminate fxn takes input of int min from main fxn and min fxn provides no output
//should update global value of eliminated
{
    for (int i = 0; i < candidate_count; i ++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
            //break;
        }
    }
    // TODO
    return;
}
