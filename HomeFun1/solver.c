#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// choose one to include from and comment out the other one
#include "10-to-0-by-1-or-2.h"
// #include "25-to-0-by-1-or-3-or-4.h"

int solve(int position)
{
    // win: 0, tie: 1, lose: 2
    int mem[position + 1];
    int prim;
    int status;
    int *moves;
    int temppos;

    for (int i = 0; i <= position; i++) // go from 0 to the position to dp the problem
    {
        prim = primitive_value(i);
        if (prim != 3) // check if prim val
        {
            mem[i] = prim;
        }
        else // not a prim val
        {
            moves = generate_moves(i); // generate possible moves from current posision, number of moves is stored in moves[0]
            if (moves[0] == -1)
            {
                free(moves);
                return -1;
            }

            status = 2;

            for (int j = 1; j <= moves[0]; j++) // collect all the new positions generated by the moves
            {
                temppos = do_move(i, moves[j]);

                if (mem[temppos] == 2) // at least one lose child == winning
                {
                    status = 0;
                    break;
                }
                else if (mem[temppos] == 1) // at least one tie child wout a lose child == tie
                {
                    status = 1;
                }
            }

            mem[i] = status;

            free(moves);
        }
    }

    return mem[position];
}

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        int max = atoi(argv[1]);
        int code;
        char *sol;
        for (int i = max; i >= 0; i--)
        {
            code = solve(i);
            if (code == -1)
            {
                sol = "error";
            }
            else if (code == 0)
            {
                sol = "win";
            }
            else if (code == 1)
            {
                sol = "tie";
            }
            else if (code == 2)
            {
                sol = "lose";
            }
            else
            {
                sol = "N/A";
            }
            printf("%d: %s\n", i, sol);
        }
    }
    else
    {
        printf("Please enter a max value!");
    }

    return 0;
}