/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_ghost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:42:25 by syukna            #+#    #+#             */
/*   Updated: 2025/03/19 15:44:20 by syukna           ###   ########.fr       */
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
