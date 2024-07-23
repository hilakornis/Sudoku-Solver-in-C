#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 9

typedef struct {
    int puzzle[SIZE][SIZE];
} Game;

// Function declarations
void createPuzzle(Game* game);

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
    int count = 0;
    for (int i = 0; i < SIZE; i += 3) {
        fillBox(game, i, i);
        
        
    }

    // Further logic to ensure the rest of the board is filled can be added here
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


int main() {
    printf("Welcome to my Sudoku game - by Hila Kornis\n");
    int fill_boxes = 3;
    printf("Filling %d boxes from the sudoku\n", fill_boxes);
    Game game;
    
    createPuzzle(&game);

    // Print the puzzle to verify
    for (int i = 0; i < SIZE; i++) {
        if(i % 3 == 0) printf("\n");
        for (int j = 0; j < SIZE; j++) {
            if(j % 3 == 0) printf("  ");
            printf("%2d ", game.puzzle[i][j]);
            
        }
        printf("\n");
    }

    return 0;
}


