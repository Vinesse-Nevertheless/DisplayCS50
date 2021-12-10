//NOT SOLVED

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Max voters and candidates. #define makes a macro that allows you to define constants used in your program
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
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }


    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
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
   for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    
 //   for (int i = 0; i < voter_count; i++)
 //   {
 //       for (int j = 0; j < candidate_count; j++)
 //       {
  //          printf("%i", preferences[i][j]);
 //       }
 //   }
    
    //person(s) dropped from race
        int pos = 0;
        for (int i = 0; i < candidate_count; i++)
        {
            if (candidates[i].eliminated == false)
            {
            pos = preferences[i][0];
            candidates[pos].votes++;
           // printf("Name %s and votes %i", candidates[i].name, candidates[i].votes);
            }
            else
            {
                 for (int j = 1; j < candidate_count; j++)
                    {
                       pos = preferences[i][j];
                        candidates[pos].votes++;
                    }
            }
        
        
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{

   float majority = (float) voter_count / 2;
   for (int i = 0; i < candidate_count; i++)
    {
        int count = candidates[i].votes;
      //  printf("Count: %i\n", count);
      //  printf("Majority: %f\n", majority);
        if(candidates[i].votes > majority)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
   //sort
   int votes[candidate_count];
       for (int i = 0; i < candidate_count; i++)
        {
            if(candidates[i].eliminated == true)
            {
                i++;
            }
            else
            {
            votes[i] = candidates[i].votes;
            }
        }
   
    for (int k = 0; k < candidate_count; k++)
        {
            for (int j = 1; j < candidate_count; j++)
            {
                if(votes[k] > votes[j])
                {
                    int temp = votes[j];
                    votes[j] = votes[k];
                    votes[k] = temp;
                }
            }
        }  
   
  //  printf("Min is %i\n", votes[0]);
    return votes[0];
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 1; j < candidate_count; j++)
         {
           if(candidates[i].eliminated == false && candidates[j].eliminated == false)
            {
                if(candidates[i].votes != candidates[j].votes)
                {
                    return false;
                }
            }
         }
    }
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int i = 0; i <= candidate_count; i++)
    {
       // printf("Candidate %i: votes currently: %i\n", i, candidates[i].votes);
        if(candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
          //  printf("%s has been marked eliminated\n", candidates[i].name);
        }
    }
    return;
}
