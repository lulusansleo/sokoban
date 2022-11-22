/*
** EPITECH PROJECT, 2022
** my sokoban
** File description:
** map
*/

#include "my.h"
#include "sokoban.h"

char **buffer_to_map(char *buffer)
{
    int x = 0;
    int y = 0;
    char **map;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            y++;
    }
    y++;
    for (x = 0; buffer[x] != '\n'; x++);
    map = malloc(sizeof(char *) * (y + 1));
    for (int i = 0; i < y; i++) {
        map[i] = malloc(sizeof(char) * (x + 1));
        my_strncpy(map[i], buffer + i * (x + 1), x);
    }
    map[y] = NULL;
    return map;
}

void free_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
}
