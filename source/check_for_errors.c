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
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] != ' ' && buffer[i] != '#'
        && buffer[i] != 'P' && buffer[i] != 'O'
        && buffer[i] != '\n')
            return 1;
    }
    return 0;
}
