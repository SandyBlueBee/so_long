#include "../inc/so_long.h"

int get_start(char *map)
{
    int i;

    i = 0;
    while (map[i] != 'P')
        i++;
    return (i);
}

void	print_ghost(t_game *game, t_character *ghost, int i)
{
    if (game->map[i] == 'B')
	    print_sprite(game, game->textures->ghost_bush, ghost->pos);
    else if (game->map[i] == 'H')
	    print_sprite(game, game->textures->ghost_table_h, ghost->pos);
    else if (game->map[i] == 'V')
	    print_sprite(game, game->textures->ghost_table_v, ghost->pos);
    else
	    print_sprite(game, game->textures->ghost, ghost->pos);
}

int is_letter(char letter, char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (letter == str[i])
            return (1);
        i++;
    }
    return (0);
}

int get_rand(int max)
{
    return (rand() % max);
}

void    move_ghost(int r, t_game *game, t_character *ghost)
{
    t_data      *sprite;

    sprite = get_sprite(game, game->map[ghost->pos]);
    print_sprite(game, sprite, ghost->pos);
    r = get_rand(4);
    if (r == 1 && !is_letter(game->map[ghost->pos + 1], "UDLR"))
        ghost->pos++;
    else if (r == 2 && !is_letter(game->map[ghost->pos + (game->width + 1)], "UDLR"))
        ghost->pos = ghost->pos + game->width + 1;
    else if (r == 3 && !is_letter(game->map[ghost->pos - 1], "UDLR"))
        ghost->pos--;
    else if (r == 0 && !is_letter(game->map[ghost->pos - (game->width + 1)], "UDLR"))
        ghost->pos = ghost->pos - game->width - 1;
    else
        move_ghosts(game);
    print_ghost(game, ghost, ghost->pos);
    if (ghost->pos == game->player->pos)
        close_game(game);
}

void    move_ghosts(t_game *game)
{
    t_character *ghost;
    int r;

    if (game->ghost)
    {
        ghost = game->ghost;
        while(ghost->next)
        {
            r = get_rand(4);
            move_ghost(r, game, ghost);
            ghost = ghost->next;
        }
    }
}

void    add_ghost(t_game *game)
{
    if (game->ghost == NULL)
    {
         game->ghost = ft_calloc(1, sizeof(t_character));
        if (!game->ghost) // Check allocation
        {
            ft_printf("Failed to allocate memory for ghost\n");
            return;
        }
        game->ghost->pos = get_start(game->map);
        print_ghost(game, game->ghost, game->ghost->pos);
    }
    else
    {
        t_character *ghost;
        t_character *prev;
        ghost = ft_calloc(1, sizeof(t_character));
        if (!ghost) // Check allocation
        {
            ft_printf("Failed to allocate memory for ghost\n");
            return;
        }
        prev = game->ghost;
        while(prev->next)
            prev = prev->next;
        prev->next = ghost;
        ghost->pos = get_start(game->map);
        print_ghost(game, ghost, ghost->pos);
    }
}