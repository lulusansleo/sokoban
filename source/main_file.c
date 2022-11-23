/*
** EPITECH PROJECT, 2022
** my sokoban
** File description:
** sokoban main file
*/

#include "my.h"
#include "sokoban.h"

int main(int ac, char **av)
{
    int ret = 0;
    if (ac != 2)
        return 84;
    ret = open_sokoban(av[1]);
    if (ret == -1)
        return 84;
    if (ret == 0)
        return 0;
    if (ret == 1)
        return 1;
    return 0;
}
