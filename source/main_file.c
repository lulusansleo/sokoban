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
    if (ac != 2)
        return 84;
    if (open_sokoban(av[1]) == -1)
        return 84;
    return 0;
}
