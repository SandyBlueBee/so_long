/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:49:57 by syukna            #+#    #+#             */
/*   Updated: 2025/03/13 19:26:34 by syukna           ###   ########.fr       */
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

void	move_up(t_game *game)
{
	int	i;
	int line;
	t_data *sprite;

	i = game->player->pos;
	line = game->width + 1;
	if (game->map[i - line] == '0' || game->map[i - line] == 'C' || game->map[i - line] == 'P' || game->map[i - line] == 'E')
	{
		sprite = get_sprite(game, game->map[i]);
		print_sprite(game, sprite, i);
		print_sprite(game, game->textures->floor, i-line);
		game->player->pos = i - line;
		if (game->map[i - line] == 'C')
		{
			game->map[i - line] = '0';
			print_sprite(game, game->textures->player_drink, i - line);
		}
		else if (game->map[i - line] == 'E')
			print_sprite(game, game->textures->player_trap, i - line);
		else
			print_player(game);
		game->moves++;
		ft_printf("%d\n", game->moves);
	}
	else if (game->map[i - line] == 'O')
		close_game(game);
	end_move(game);
}

void	move_left(t_game *game)
{
	int	i;
	t_data *sprite;

	i = game->player->pos;
	if (game->map[i - 1] == '0' || game->map[i - 1] == 'C' || game->map[i - 1] == 'P'  || game->map[i  - 1] == 'E')
	{
		sprite = get_sprite(game, game->map[i]);
		print_sprite(game, sprite, i);
		print_sprite(game, game->textures->floor, i - 1);
		game->player->pos = i - 1;
		if (game->map[i - 1] == 'C')
		{
			game->map[i - 1] = '0';
			print_sprite(game, game->textures->player_drink, i - 1);
		}
		else if (game->map[i - 1] == 'E')
			print_sprite(game, game->textures->player_trap, i - 1);
		else
			print_player(game);
		game->moves++;
		ft_printf("%d\n", game->moves);
	}
	else if (game->map[i - 1] == 'O')
		close_game(game);
	end_move(game);
}

void	move_down(t_game *game)
{
	int	i;
	int line;
	t_data *sprite;

	i = game->player->pos;
	line = game->width + 1;
	if (game->map[i + line] == '0' || game->map[i + line] == 'C' || game->map[i + line] == 'P'  || game->map[i  + line] == 'E')
	{
		sprite = get_sprite(game, game->map[i]);
		print_sprite(game, sprite, i);
		print_sprite(game, game->textures->floor, i + line);
		game->player->pos = i + line;
		if (game->map[i + line] == 'C')
		{
			game->map[i + line] = '0';
			print_sprite(game, game->textures->player_drink, i + line);
		}
		else if (game->map[i + line] == 'E')
			print_sprite(game, game->textures->player_trap, i + line);
		else
			print_player(game);
		game->moves++;
		ft_printf("%d\n", game->moves);
	}
	else if (game->map[i + line] == 'O')
		close_game(game);
	end_move(game);
}

void	move_right(t_game *game)
{
	int	i;
	t_data *sprite;

	i = game->player->pos;
	if (game->map[i + 1] == '0' || game->map[i  + 1] == 'C' || game->map[i  + 1] == 'P' || game->map[i  + 1] == 'E')
	{
		sprite = get_sprite(game, game->map[i]);
		print_sprite(game, sprite, i);
		print_sprite(game, game->textures->floor, i + 1);
		game->player->pos = i + 1;
		if (game->map[i + 1] == 'C')
		{
			game->map[i + 1] = '0';
			print_sprite(game, game->textures->player_drink, i + 1);
		}
		else if (game->map[i + 1] == 'E')
			print_sprite(game, game->textures->player_trap, i + 1);
		else
			print_player(game);
		game->moves++;
		ft_printf("%d\n", game->moves);
	}
	else if (game->map[i + 1] == 'O')
		close_game(game);
	end_move(game);
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
