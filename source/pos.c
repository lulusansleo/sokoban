/*
** EPITECH PROJECT, 2022
** my sokoban
** File description:
** pos functions
*/

#include "my.h"
#include "sokoban.h"

pos_t change_pos_if(pos_t player_pos, int i, int j, char **map)
{
    if (map[j][i] == 'P') {
        player_pos.x = i;
        player_pos.y = j;
    }
    return player_pos;
}

pos_t get_pos(char **map)
{
    pos_t player_pos = {0, 0};
    for (int j = 0; map[j] != NULL; j++)
        for (int i = 0; map[j][i] != '\0'; i++)
            player_pos = change_pos_if(player_pos, i, j, map);
    return player_pos;
}

pos_t get_vect(int x, int y)
{
    pos_t vect = {0, 0};
    vect.x = x;
    vect.y = y;
    return vect;
}
