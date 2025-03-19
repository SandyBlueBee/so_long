/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:49:57 by syukna            #+#    #+#             */
/*   Updated: 2025/03/19 14:17:26 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	open_trap(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] && game->map[i] != 'E')
		i++;
	if (game->map[i] == 'E')
	{
		game->map[i] = 'O';
		print_sprite(game, game->textures->trap_open, i);
	}
}

void	end_move(t_game *game)
{
	game->beers = ft_countchar(game->map, 'C');
	if (game->beers == 0)
		open_trap(game);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == XK_w || keycode == XK_Up)
		move_up(game);
	else if (keycode == XK_a || keycode == XK_Left)
		move_left(game);
	else if (keycode == XK_s || keycode == XK_Down)
		move_down(game);
	else if (keycode == XK_d || keycode == XK_Right)
		move_right(game);
	else if (keycode == XK_Escape)
		close_game(game);
	return (0);
}
