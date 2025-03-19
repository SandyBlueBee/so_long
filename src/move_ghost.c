/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ghost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:46:18 by syukna            #+#    #+#             */
/*   Updated: 2025/03/19 15:44:32 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	print_ghost(t_game *game, t_character *ghost, int i)
{
	if (game->map[i] == 'B')
		print_sprite(game, game->textures->ghost_bush, ghost->pos);
	else if (game->map[i] == 'H')
		print_sprite(game, game->textures->ghost_th, ghost->pos);
	else if (game->map[i] == 'V')
		print_sprite(game, game->textures->ghost_tv, ghost->pos);
	else
		print_sprite(game, game->textures->ghost, ghost->pos);
}

int	get_rand(int max)
{
	return (rand() % max);
}

int	gh_pres(int pos, t_game *game)
{
	t_character	*ghost;

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

void	move_ghost(int r, t_game *game, t_character *ghost)
{
	t_data	*sprite;
	int		directions[4];
	int		i;
	int		new_pos;
	int		moved;

	directions[0] = ghost->pos + 1;
	directions[1] = ghost->pos + game->width + 1;
	directions[2] = ghost->pos - 1;
	directions[3] = ghost->pos - game->width - 1;
	i = 0;
	moved = 0;
	sprite = get_sprite_content(game, game->map[ghost->pos]);
	print_sprite(game, sprite, ghost->pos);
	while (i < 6 && moved == 0)
	{
		new_pos = directions[(r + i) % 4];
		if (!gh_pres(new_pos, game) && !let_inc(game->map[new_pos], "UDLREO"))
		{
			ghost->pos = new_pos;
			moved = 1;
		}
		i++;
	}
	print_ghost(game, ghost, ghost->pos);
}

void	move_ghosts(t_game *game)
{
	t_character	*ghost;
	int			r;

	if (game->ghost)
	{
		ghost = game->ghost;
		while (ghost->next)
		{
			r = get_rand(4);
			move_ghost(r, game, ghost);
			ghost = ghost->next;
		}
	}
}
