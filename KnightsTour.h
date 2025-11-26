#ifndef KNIGHTSTOUR_H
#define KNIGHTSTOUR_H

#include <stdio.h>
#include <stdbool.h>

#define SIZE 8
#define MOVE_COUNT 8

// Function declarations
void generate_and_print_board(bool board[SIZE][SIZE]);
bool make_a_move(size_t move_id, int x, int y, bool board[SIZE][SIZE]);
int tour_greedy(size_t start_x, size_t start_y, bool board[SIZE][SIZE]);
void greedy_tour_from_each_square(void);

#endif