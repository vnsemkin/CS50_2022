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
    // Print winner
    print_winner();
}

//Count votes
bool vote(string name)
{
    //Iteerate candidate.name array
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    //Create and variable and set it to 0
    int vote_count = 0;

    //iterate over list of candidate
    for (int i = 0; i < candidate_count; i++)
    {
        //check for candidate votes that are  greater than maximum_vote and set them to maximum_vote
        if (candidates[i].votes > vote_count)
        {
            vote_count = candidates[i].votes;
        }
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == vote_count)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}



