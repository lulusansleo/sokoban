/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** game file
*/

#include "my.h"
#include "sokoban.h"

void print_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        printw(map[i]);
        printw("\n");
    }
}

void reset_map(char **map, char **copy, pos_t *pos)
{
    for (int i = 0; map[i] != NULL; i++)
        for (int j = 0; map[i][j] != '\0'; j++)
            map[i][j] = copy[i][j];
    *pos = get_pos(copy);
}

int manage_input(WINDOW *stdscr, pos_t *player_pos, char **map, char **copy)
{
    int c = 0;
    while ((c = getch()) != 27) {
        if (c == KEY_UP)
            move_player(player_pos, map, get_vect(0, -1), copy);
        if (c == KEY_DOWN)
            move_player(player_pos, map, get_vect(0, 1), copy);
        if (c == KEY_LEFT)
            move_player(player_pos, map, get_vect(-1, 0), copy);
        if (c == KEY_RIGHT)
            move_player(player_pos, map, get_vect(1, 0), copy);
        if (c == ' ')
            reset_map(map, copy, player_pos);
        if (won(map, copy) == 1)
            return 0;
        if (check_for_loss(map, copy))
            return 1;
        wclear(stdscr);
        print_map(map);
    }
    return 0;
}

int sokoban(char *buffer)
{
    char **map = buffer_to_map(buffer);
    char **copy = buffer_to_map(buffer);
    int ret = 0;

    for (int i = 0; map[i] != NULL; i++)
        printf ("%s\n", map[i]);
    pos_t player_pos = get_pos(map);
    initscr();
    raw();
    noecho();
    refresh();
    print_map(map);
    keypad(stdscr, true);
    ret = manage_input(stdscr, &player_pos, map, copy);
    endwin();
    free_map(map);
    free_map(copy);
    return ret;
}
