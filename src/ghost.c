#include "../inc/so_long.h"

int get_start_ghost(t_game *game, char *map)
{
    int r;
    int i;

    r = get_rand(game->bushes - 1) + 1;
    i = 0;
    while (map[i] != '\0')
    {
        if (map[i] == 'B')
            r--;
        if (r == 0)
            return (i);
        i++;
    }
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

int gh_pres(int pos, t_game *game)
{
    t_character *ghost;

    if (game->ghost)
    {
        ghost = game->ghost;
        while (ghost->next)
        {
            if (ghost->pos == pos)
                return (1);
            ghost = ghost->next;
        }
        if (ghost->pos == pos)
            return (1);
    }
    return (0);
}

void    move_ghost(int r, t_game *game, t_character *ghost)
{
    t_data      *sprite;

    sprite = get_sprite(game, game->map[ghost->pos]);
    print_sprite(game, sprite, ghost->pos);
    r = get_rand(4);
    if (r == 1 && !gh_pres(ghost->pos + 1, game) && !is_letter(game->map[ghost->pos + 1], "UDLR"))
        ghost->pos++;
    else if (r == 2 && !gh_pres(ghost->pos + game->width + 1, game) && !is_letter(game->map[ghost->pos + (game->width + 1)], "UDLR"))
        ghost->pos = ghost->pos + game->width + 1;
    else if (r == 3 && !gh_pres(ghost->pos - 1, game) && !is_letter(game->map[ghost->pos - 1], "UDLR"))
        ghost->pos--;
    else if (r == 0 && !gh_pres(ghost->pos - game->width - 1, game) && !is_letter(game->map[ghost->pos - (game->width + 1)], "UDLR"))
        ghost->pos = ghost->pos - game->width - 1;
    else
        move_ghost(get_rand(4), game, ghost);
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
    print_player(game);
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
        game->ghost->pos = get_start_ghost(game, game->map);
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
        ghost->pos = get_start_ghost(game, game->map);
        print_ghost(game, ghost, ghost->pos);
    }
}
