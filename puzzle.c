
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 9

typedef struct {
    int puzzle[SIZE][SIZE];
} Game;

// Function declarations
void createPuzzle(Game* game);

int main() {
    Game game;
    createPuzzle(&game);

    // // Print the puzzle to verify
    for (int i = 0; i < SIZE; i++)
    {
        // printf("");
        for (int j = 0; i < SIZE; j++){
                
                // printf("%d %d\n",i,j);
                if(j % 3 == 0){
                    printf("   %d", game.puzzle[i][j]);
                } else {
                    printf(" %d",  game.puzzle[i][j]);
                }
                
        }
        printf("\n");
    
    }
    PrintPuzzle(&game);
    return 0;
}

void createPuzzle(Game* game) {
    // Initialize the puzzle with zeros
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            game->puzzle[i][j] = 0;
        }
    }

    // Seed random number generator
    srand(time(NULL));

    // Fill the diagonal 3x3 boxes to ensure the puzzle is solvable
    for (int i = 0; i < SIZE; i += 3) {
        fillBox(game, i, i);
    }

    // Further logic to ensure the rest of the board is filled can be added here
}

void PrintPuzzle(Game * game){
    printf("This is PrintPuzzle.\n");
    int ** puzzle = game->puzzle;
    for (int i = 0; i < SIZE; i++)
    {
        // printf("");
        for (int j = 0; i < SIZE; i++){
                
                if(i % 3 == 0){
                    printf("   %d", puzzle[i][j]);
                } else {
                    printf(" %d", puzzle[i][j]);
                }
                
        }
        printf("\n");
    
    }
    
    
}

// Helper function to fill a 3x3 box
void fillBox(Game* game, int row, int col) {
    int num;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            do {
                num = (rand() % 9) + 1;
            } while (!isSafeToPlace(game, row + i, col + j, num));
            game->puzzle[row + i][col + j] = num;
        }
    }
}

// Function to check if it's safe to place a number in a given cell
int isSafeToPlace(Game* game, int row, int col, int num) {
    for (int x = 0; x < SIZE; x++) {
        if (game->puzzle[row][x] == num || game->puzzle[x][col] == num) {
            return 0;
        }
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (game->puzzle[i + startRow][j + startCol] == num) {
                return 0;
            }
        }
    }
    return 1;
}
