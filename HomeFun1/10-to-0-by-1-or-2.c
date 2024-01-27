#include <stdio.h>
#include <stdlib.h>

#include "10-to-0-by-1-or-2.h"

int do_move(int position, int move)
{
    // check all illegal moves
    if (!(0 < move && move < 3) || !(0 < position && position <= 10) || (position == 1 && move == 2))
    {
        return -1;
    }
    return position - move;
}

int *generate_moves(int position)
{
    // first elemnt of moves
    int *moves = malloc(3 * sizeof(int));
    if (!(0 < position && position <= 10))
    {
        moves[0] = -1;
    }
    else if (position == 1)
    {
        moves[0] = 1;
        moves[1] = 1;
    }
    else
    {
        moves[0] = 2;
        moves[1] = 1;
        moves[2] = 2;
    }

    return moves;
}

int primitive_value(int position)
{

    // win: 0, tie: 1, lose: 2, not_primitive: 3
    if (position == 0)
    {
        return 2;
    }
    else
    {
        return 3;
    }
}

// int main(int argc, char *argv[])
// {
//     printf("do_move(1, 2): %d\n", do_move(1, 2));

//     int *moves = generate_moves(3);
//     printf("Calling generate_moves(3): \n");
//     if (moves[0] == -1)
//     {
//         printf("no moves available, primitive values \n");
//     }
//     else
//     {
//         for (int i = 1; i <= moves[0]; i++)
//         {
//             printf("move %d: %d\n", i, moves[i]);
//         }
//     }
//     free(moves);

//     printf("primitive_value(0): %d\n", primitive_value(0));
//     printf("primitive_value(5): %d\n", primitive_value(5));

//     return 0;
// }