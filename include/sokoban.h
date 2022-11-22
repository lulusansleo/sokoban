/*
** EPITECH PROJECT, 2022
** my sokoban
** File description:
** -h
*/

#ifndef sokoban_h
    #define sokoban_h

    #include <ncurses.h>
    #include <fcntl.h>
    #include <sys/stat.h>

    int open_sokoban(char const *filepath);
    void sokoban(char *buffer);
    int check_map(char *buffer);

#endif /* !sokoban_h */
