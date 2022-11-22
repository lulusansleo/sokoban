/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** sokoban open file
*/

#include "my.h"
#include "sokoban.h"

static void print_usage(void)
{
    write(1, "USAGE\n      ./my_sokoban map\n", 30);
    write(1, "DESCRIPTION\n", 13);
    write(1, "     map file representing the map,", 36);
    write(1, "containing '#' for walls,\n", 27);
    write(1, "     'P' for the player, 'X' for boxes", 39);
    write(1, "and '0' for storage locations.\n", 32);
}

int open_sokoban(char const *filepath)
{
    int fd = 0;
    char *buffer;
    struct stat st;

    if (my_strcmp(filepath, "-h") == 0) {
        print_usage();
        return 0;
    }
    if ((fd = open(filepath, O_RDONLY)) == -1)
        return -1;
    stat(filepath, &st);
    buffer = malloc(sizeof (char) * (st.st_size + 1));
    read(fd, buffer, st.st_size);
    if (check_map(buffer))
        return -1;
    sokoban(buffer);
    return 0;
}
