#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 5

typedef struct {
    char name[50];
    int votes;
} Candidate;

void initializeCandidates(Candidate candidates[], int numCandidates) {
    for (int i = 0; i < numCandidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
}

void displayCandidates(Candidate candidates[], int numCandidates) {
    printf("\nCandidates:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

void vote(Candidate candidates[], int numCandidates) {
    int choice;
    displayCandidates(candidates, numCandidates);
    
    printf("Enter the number of the candidate you want to vote for: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= numCandidates) {
        candidates[choice - 1].votes++;
        printf("Vote recorded for %s.\n", candidates[choice - 1].name);
    } else {
        printf("Invalid choice. Please enter a number between 1 and %d.\n", numCandidates);
    }
}

void displayResults(Candidate candidates[], int numCandidates) {
    printf("\nResults:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int numCandidates;
    
    printf("Enter the number of candidates: ");
    scanf("%d", &numCandidates);

    if (numCandidates <= 0 || numCandidates > MAX_CANDIDATES) {
        printf("Invalid number of candidates. Please enter a number between 1 and %d.\n", MAX_CANDIDATES);
        return 1;
    }

    Candidate candidates[MAX_CANDIDATES];
    initializeCandidates(candidates, numCandidates);

    int numVoters;
    printf("Enter the number of voters: ");
    scanf("%d", &numVoters);

    for (int i = 0; i < numVoters; i++) {
        printf("\nVoter %d:\n", i + 1);
        vote(candidates, numCandidates);
    }

    displayResults(candidates, numCandidates);

    return 0;
}
