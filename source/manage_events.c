/*
** EPITECH PROJECT, 2022
** my sokoban
** File description:
** events
*/

#include "my.h"
#include "sokoban.h"

int is_a_wall(char c)
{
    if (c == '#' || c == 'X')
        return 1;
    return 0;
}

int push_block(pos_t *block_pos, char **map, pos_t move)
{
    pos_t cpy = *block_pos;
    if (map[block_pos->y][block_pos->x] == 'X') {
        if (map[block_pos->y + move.y][block_pos->x + move.x] == '#' ||
        map[block_pos->y + move.y][block_pos->x + move.x] == 'X')
            return 1;
        map[block_pos->y][block_pos->x] = ' ';
        map[block_pos->y + move.y][block_pos->x + move.x] = 'X';
        if (check_adjacent(cpy, map, move))
            return -1;
    }
    return 0;
}

static int count_o(char const *str, char const *check)
{
    int o_count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (check[i] == 'O' && str[i] != 'X')
            o_count++;
    return o_count;
}

int won(char **map, char **cpy)
{
    int o_count = 0;

    for (int i = 0; map[i] != NULL; i++)
        o_count += count_o(map[i], cpy[i]);
    if (o_count == 0)
        return 1;
    return 0;
}

int move_player(pos_t *player_pos, char **map, pos_t move, char **copy)
{
    char tmp = map[player_pos->y][player_pos->x];
    int push_state;
    pos_t block_pos = {0, 0};
    block_pos.x = player_pos->x + move.x;
    block_pos.y = player_pos->y + move.y;
    push_state = push_block(&block_pos, map, move);
    if (push_state == -1)
        return 1;
    if (map[player_pos->y + move.y][player_pos->x + move.x] != '#'
    && push_state == 0) {
        map[player_pos->y][player_pos->x] = ' ';
        map[player_pos->y + move.y][player_pos->x + move.x] = tmp;
        if (copy[player_pos->y][player_pos->x] == 'O')
            map[player_pos->y][player_pos->x] = 'O';
        player_pos->x += move.x;
        player_pos->y += move.y;
    }
    return 0;
}
