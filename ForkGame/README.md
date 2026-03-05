# Game of Chance using ``fork()``

## Overview
This project simulates a simple game of chance in which the player rolls a six-sided die and pulls a marble from a bag containing a red, yellow, and blue marble. The die and bag of marbles are rigged, and the odds of getting a specific outcome can be modified in the ``diceWeights`` and ``marbleWeights`` arrays inside ```my_game.c```. The program uses ``fork()`` to simulate every possible outcome and display the probabilities of achieving them. Parent processes will wait for child processes to finish before they exit.

## How to rig the game
The odds of rolling a certain number or drawing a certain marble can be modified in these arrays found in ``my_game.c``. They are later normalized to a value between 0 and 1 to compute the final outcome probability.
```c
// odds of rolling a {1, 2, 3, 4, 5, 6}:
double diceWeights[NUM_SIDES] = {1, 2, 3, 2, 1, 1}; // example: favor rolling a 3
// odds of drawing a {R, Y, B} marble:
double marbleWeights[NUM_MARBLES] = {1, 1, 2}; // example: blue marble twice as likely
```
## Sample output
A screenshot of a complete run of the program can be found in ``rigged_game.JPG``
```
Rolling a rigged 6-sided die and drawing a rigged marble...
Rolled 1, Drew Red    - Rigged Probability: x.xx%
Rolled 1, Drew Blue   - Rigged Probability: x.xx%
Rolled 1, Drew Yellow - Rigged Probability: x.xx%
...
Rolled 6, Drew Yellow - Rigged Probability: x.xx%
All rigged outcomes displayed. Exiting program.
```

# Running the program
Clone the repository and open the project folder in a container. The ``.devcontainer`` folder contains all necessary Docker configurations
```bash
git clone https://github.com/parkerStacy19/os-pcstacy
cd os-pcstacy/game
```
Use ``make run`` to build and execute the program, and use ``make clean`` to remove object files after execution.

## Refrences 
Conversation with ChatGPT to develop the program: [link](https://chatgpt.com/share/67c20cd4-7ad0-8001-b769-57282293c8bf)

An example game of chance using fork() was provided by Dr. MacEvoy in ``game_example.c``
