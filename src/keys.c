/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:49:57 by syukna            #+#    #+#             */
/*   Updated: 2025/03/11 15:53:07 by syukna           ###   ########.fr       */
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
		game->map[i] = 'O';
}

void	check_trap(t_game *game)
{
	game->beers = ft_countchar(game->map, 'C');
	if (game->beers == 0)
		open_trap(game);
	open_screen(game);
}

void	move_up(t_game *game)
{
	int	i;
	int line;

	i = 0;
	line = game->width + 1;
	while (game->map[i] != 'P')
		i++;
	if (game->map[i - line] == '0' || game->map[i  - line] == 'C')
	{
		game->map[i] = '0';
		game->map[i - line] = 'P';
	}
	else if (game->map[i - line] == 'O')
		close_game(game);
	check_trap(game);
}

void	move_left(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] != 'P')
		i++;
	if (game->map[i - 1] == '0' || game->map[i - 1] == 'C')
	{
		game->map[i] = '0';
		game->map[i - 1] = 'P';
	}
	else if (game->map[i - 1] == 'O')
		close_game(game);
	check_trap(game);
}

void	move_down(t_game *game)
{
	int	i;
	int line;

	i = 0;
	line = game->width + 1;
	while (game->map[i] != 'P')
		i++;
	if (game->map[i + line] == '0' || game->map[i  + line] == 'C')
	{
		game->map[i] = '0';
		game->map[i + line] = 'P';
	}
	else if (game->map[i + line] == 'O')
		close_game(game);
	check_trap(game);
}

void	move_right(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] != 'P')
		i++;
	if (game->map[i + 1] == '0' || game->map[i + 1] == 'C')
	{
		game->map[i] = '0';
		game->map[i + 1] = 'P';
	}
	else if (game->map[i + 1] == 'O')
		close_game(game);
	check_trap(game);
}

int	key_hook(int keycode, t_game *game)
{
	// XK_Left Xk_W
	// printf("Hello from key_hook!\nCurrent key is %d\n\n%s\n", keycode, game->map);
	if (keycode == 119 || keycode == 65362 ) 
		move_up(game);
	else if (keycode == 97 || keycode == 65361 )
		move_left(game);
	else if (keycode == 115 || keycode == 65364 )
		move_down(game);
	else if (keycode == 100 || keycode == 65363)
		move_right(game);
	else if (keycode == 65307)
		close_game(game);
	open_screen(game);
	return (0);
}