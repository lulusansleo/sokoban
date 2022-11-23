/*
** EPITECH PROJECT, 2022
** my sokoban
** File description:
** check for errors
*/

#include "my.h"
#include "sokoban.h"

int check_map(char *buffer)
{
    int o_count = 0;
    int p_count = 0;
    int x_count = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] != ' ' && buffer[i] != '#' && buffer[i] != 'P' &&
        buffer[i] != 'O' && buffer[i] != '\n' && buffer[i] != 'X')
            return 1;
        if (buffer[i] == 'P')
            p_count++;
        if (buffer[i] == 'O')
            o_count++;
        if (buffer[i] == 'X')
            x_count++;
    }
    if (p_count != 1)
        return 1;
    if (o_count > x_count)
        return 1;
    return 0;
}
