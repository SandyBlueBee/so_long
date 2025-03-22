/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_ghost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:42:25 by syukna            #+#    #+#             */
/*   Updated: 2025/03/22 11:53:54 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	get_start_ghost(t_game *game, char *map)
{
	int	r;
	int	i;

	r = get_rand(game->bushes) + 1;
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

void	add_first_ghost(t_game *game)
{
	game->ghost = ft_calloc(1, sizeof(t_character));
	if (!game->ghost)
	{
		ft_printf("Failed to allocate memory for ghost\n");
		return ;
	}
	game->ghost->pos = get_start_ghost(game, game->map);
	print_ghost(game, game->ghost, game->ghost->pos);
}

void	add_ghost(t_game *game)
{
	t_character	*ghost;
	t_character	*prev;

	if (game->ghost == NULL)
		add_first_ghost(game);
	else
	{
		ghost = ft_calloc(1, sizeof(t_character));
		if (!ghost)
		{
			ft_printf("Failed to allocate memory for ghost\n");
			return ;
		}
		prev = game->ghost;
		while (prev->next)
			prev = prev->next;
		prev->next = ghost;
		ghost->pos = get_start_ghost(game, game->map);
		print_ghost(game, ghost, ghost->pos);
	}
}

void	print_ghost(t_game *game, t_character *ghost, int i)
{
	t_data	*ghost_data;
	int		p_pos;
	int		line;

	p_pos = game->player->pos;
	line = game->width + 1;
	if (p_pos == i - 1 || p_pos == i - line)
		ghost_data = game->textures->move_ghost;
	else if (p_pos == i + line || p_pos == i + 1)
		ghost_data = game->textures->move_ghost;
	else
		ghost_data = game->textures->ghost;
	if (game->map[i] == 'B')
		print_sprite(game, game->textures->ghost_bush, ghost->pos);
	else if (game->map[i] == 'H')
		print_sprite(game, game->textures->ghost_th, ghost->pos);
	else if (game->map[i] == 'V')
		print_sprite(game, game->textures->ghost_tv, ghost->pos);
	else
		print_sprite(game, ghost_data, ghost->pos);
}

void	print_ghosts(t_game *game)
{
	t_character	*ghost;

	if (game->ghost)
	{
		ghost = game->ghost;
		while (ghost->next)
		{
			print_ghost(game, ghost, ghost->pos);
			ghost = ghost->next;
		}
		print_ghost(game, ghost, ghost->pos);
	}
}
