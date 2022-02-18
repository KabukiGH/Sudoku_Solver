#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "sudoku.h"

/* Global variables */
char POSSIBLE= 0x1FF;

Square ***setUpPuzzle(int ** puzzle)
{
    Square ***sudoku;
    //sudoku = (Square***)malloc(PUZZLE_DIMENSION * sizeof(Square**));
    sudoku = (Square***)malloc(sizeof(Square**));

    int currentNumber = 0;

    /* loop through rows */
    for(int i = 0; i<PUZZLE_DIMENSION; i++)
    {
        sudoku[i] = (Square**)malloc(sizeof(Square*));

        /* loop through columns */
        for(int j=0; j<PUZZLE_DIMENSION; j++)
        {
            sudoku[i][j] = (Square*)malloc(sizeof(Square));

            sudoku[i][j] -> number = puzzle[i][j];

            sudoku[i][j] -> row = i;
            sudoku[i][j] -> column = j;

            currentNumber =sudoku[i][j] -> number;
            if(currentNumber != 0){
                sudoku[i][j] -> code = POSSIBLE;}
            else{
                sudoku[i][j] -> code = 0x0;}
        }
    }

    return sudoku;
}

    int **createPuzzle(void)
    {

        int **puzzle = NULL;

        int array[9][9] =  {    {0, 1, 9,    0, 0, 2,    0, 0, 0},
            {4, 7, 0,    6, 9, 0,    0, 0, 1},
            {0, 0, 0,    4, 0, 0,    0, 9, 0},

            {8, 9, 4,    5, 0, 7,    0, 0, 0},
            {0, 0, 0,    0, 0, 0,    0, 0, 0},
            {0, 0, 0,    2, 0, 1,    9, 5, 8},

            {0, 5, 0,    0, 0, 6,    0, 0, 0},
            {6, 0, 0,    0, 0, 0,    0, 7, 9},
            {0, 0, 0,    1, 0, 0,    8, 6, 0}
        };

        puzzle = (int**)malloc(PUZZLE_DIMENSION*sizeof(int*));

        for(int i = 0; i<PUZZLE_DIMENSION; i++)
        {
            puzzle[i] = (int*)malloc(PUZZLE_DIMENSION*sizeof(int));

            for(int j=0; j<PUZZLE_DIMENSION; j++)
            {
                puzzle[i][j] = array[i][j];
            }
        }

        return puzzle;
    }


    void printPuzzle(int **puzzle)
    {
        printf(" -----------------------------\n");
        for(int rows =0; rows<9; rows++)
        {
            printf("|");
            for(int colms=0; colms<9; colms++)
            {
                printf(" %d ", puzzle[rows][colms]);

                if(( (colms+1) %3) == 0)
                {
                    printf("|");
                }
            }
            printf("\n");
            if(((rows +1) % 3) ==0)
            {
                printf(" -----------------------------\n");
            }
        }
    }

