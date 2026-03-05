#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

#define NUM_SIDES 6
#define NUM_MARBLES 3

const char* MARBLES[] = {"Red", "Yellow", "Blue"};

// Custom probability weights for dice rolls (modify to rig the dice)
double diceWeights[NUM_SIDES] = {1, 2, 3, 2, 1, 1}; // Example: favoring roll 3

// Custom probability weights for marble draws (modify to rig the marbles)
double marbleWeights[NUM_MARBLES] = {1, 1, 2}; // Example: favoring Blue marble

// Function to normalize weights so they sum to 1
void normalizeWeights(double weights[], int size, double normalized[]) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += weights[i];
    }
    for (int i = 0; i < size; i++) {
        normalized[i] = weights[i] / sum;
    }
}

int main() {
    printf("Rolling a rigged 6-sided die and drawing a rigged marble...\n");

    double diceProb[NUM_SIDES];
    double marbleProb[NUM_MARBLES];

    // Normalize the probabilities
    normalizeWeights(diceWeights, NUM_SIDES, diceProb);
    normalizeWeights(marbleWeights, NUM_MARBLES, marbleProb);

    for (int die = 0; die < NUM_SIDES; die++) {
        for (int marble = 0; marble < NUM_MARBLES; marble++) {
            pid_t pid = fork();

            if (pid < 0) {
                perror("Fork failed!");
                return 1;
            } 
            else if (pid == 0) { // Child process
                double outcomeProb = diceProb[die] * marbleProb[marble] * 100;
                printf("Rolled %d, Drew %s\t- Rigged Probability: %.2f%%\n",
                       die + 1, MARBLES[marble], outcomeProb);
                exit(0); // Terminate child process
            }
        }
    }

    // Parent process waits for all child processes to complete
    for (int i = 0; i < NUM_SIDES * NUM_MARBLES; i++) {
        wait(NULL);
    }

    printf("All rigged outcomes displayed. Exiting program.\n");
    return 0;
}
