/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** game file
*/

#include "my.h"
#include "sokoban.h"

void move_player(WINDOW *stdscr)
{
    (void) stdscr;
}

void manage_input(WINDOW *stdscr)
{
    int c = 0;
    while (c != 27) {
        c = getch();
        if (c == KEY_UP || c == KEY_DOWN || c == KEY_LEFT || c == KEY_RIGHT)
            move_player(stdscr);
    }
    endwin();
}

void sokoban(char *buffer)
{
    char **map = buffer_to_map(buffer);
    initscr();
    raw();
    noecho();
    refresh();
    keypad(stdscr, true);
    manage_input(stdscr);
    free_map(map);
}
