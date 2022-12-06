/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** check for loss
*/

#include "sokoban.h"

static int check_for_block(char c)
{
    if (c == 'X')
        return 1;
    return 0;
}

int check_for_stuck(char **map, int y, int x)
{
    int adjacent_count = 0;
    if (check_for_block(map[y][x])) {
        if (is_a_wall(map[y - 1][x]))
            adjacent_count++;
        if (is_a_wall(map[y + 1][x]))
            adjacent_count++;
        if (is_a_wall(map[y][x - 1]))
            adjacent_count++;
        if (is_a_wall(map[y][x + 1]))
            adjacent_count++;
    }
    if (adjacent_count >= 2)
        return 1;
    return 0;
}

static int is_a_slot(char c)
{
    if (c == 'O')
        return 1;
    return 0;
}

int check_for_loss(char **map, char **copy)
{
    int box_count = 0;
    int stuck_count = 0;
    int slots = 0;

    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            box_count += check_for_block(map[i][j]);
            stuck_count += check_for_stuck(map, i, j);
            slots += is_a_slot(copy[i][j]);
        }
    }
    if (box_count - stuck_count < slots)
        return 1;
    return 0;
}
