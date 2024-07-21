#include <stdio.h>
#include <stdlib.h>

#define SIZE 9 

typedef struct Game
{
    int ** puzzle;
} Game;

int ** createPuzzle(Game * game){
    int ** puzzle;
    int i, j;
    int array[SIZE][SIZE] = {
        {0, 1, 9,    0,0,2,  0,0,0},
        {4, 7, 0,    6,9,0,  0,0,1},
        {0, 0, 0,     4,0,0,  0,9,0},

        {8, 9, 4,    5,0,7,  0,0,0},
        {0, 0, 0,    0,9,0,  0,0,0},
        {0, 0, 0,    2,0,1,  9,5,8},

        {0, 5, 0,    0,0,6,  0,0,0},
        {6, 0, 0,    0,2,8,  0,7,9},
        {0, 0, 0,    1,0,0,  8,6,0},
    };

    puzzle = (int**) malloc (sizeof(int*)* SIZE);
    for (size_t i = 0; i < SIZE; i++)
    {
        puzzle[i] = (int *) malloc(sizeof(int) * SIZE);
        for (size_t j = 0; i < SIZE; i++)
        {
            puzzle[i][j] = array[i][j];
        }
        
    }
    return puzzle;
}

void freePuzzle(Game * game){
    int ** puzzle = game->puzzle;
    for (size_t i = 0; i < SIZE; i++)
    {
        // puzzle[i] = (int *) malloc(sizeof(int) * SIZE);
        free(puzzle[i]);
    }
    free(puzzle);
}

void PrintPuzzle(Game * game){
    int ** puzzle = game->puzzle;
    for (size_t i = 0; i < SIZE; i++)
    {
        // printf("");
        for (size_t j = 0; i < SIZE; i++){
                
                if(i % 3 == 0){
                    printf("   %d", puzzle[i][j]);
                } else {
                    printf(" %d", puzzle[i][j]);
                }
                
        }
        printf("\n");
    
    }
    
    
}

int main(){
    printf("This is Game.c class. \n");
    Game   game;// = (Game *) malloc(sizeof(Game));
    createPuzzle(&game);
    // PrintPuzzle(&game);
    // freePuzzle(&game);

    return 0;
}
