/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_steps_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 10:43:35 by syukna            #+#    #+#             */
/*   Updated: 2025/03/22 11:56:41 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	print_sign(t_game *game)
{
	int			x;
	int			y;
	t_data		*spr;

	spr = game->textures->sign;
	x = game->width * 50 - 124;
	y = (game->height - 1) * 100 + 22;
	mlx_put_image_to_window(game->mlx, game->mlx_win, spr, x, y);
}

int	print_step(t_game *game)
{
	int		x;
	int		y;
	char	*count;

	x = game->width * 50 + 80;
	y = (game->height - 1) * 100 + 43;
	if (game->moves >= 10000)
		x -= 20;
	else if (game->moves >= 1000)
		x -= 15;
	else if (game->moves >= 100)
		x -= 10;
	else if (game->moves >= 10)
		x -= 5;
	print_sign(game);
	count = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->mlx_win, x, y, 0x00FFFFFF, count);
	free(count);
	return (0);
}

t_data	*get_move_sprite(t_game *game, char letter)
{
	if (letter == 'C')
		return (game->textures->move_beer);
	else if (letter == 'E')
		return (game->textures->move_tc);
	else if (letter == 'O')
		return (game->textures->move_to);
	else
		return (game->textures->move);
}

void	print_square_steps(t_game *game)
{
	int		line;
	t_data	*move;

	line = game->width + 1;
	if (let_inc(game->map[game->player->pos - 1], "PC0EO"))
	{
		move = get_move_sprite(game, game->map[game->player->pos - 1]);
		print_sprite(game, move, game->player->pos - 1);
	}
	if (let_inc(game->map[game->player->pos + 1], "PC0EO"))
	{
		move = get_move_sprite(game, game->map[game->player->pos + 1]);
		print_sprite(game, move, game->player->pos + 1);
	}
	if (let_inc(game->map[game->player->pos - line], "PC0EO"))
	{
		move = get_move_sprite(game, game->map[game->player->pos - line]);
		print_sprite(game, move, game->player->pos - line);
	}
	if (let_inc(game->map[game->player->pos + line], "PC0EO"))
	{
		move = get_move_sprite(game, game->map[game->player->pos + line]);
		print_sprite(game, move, game->player->pos + line);
	}
}

void	reset_square_steps(t_game *game)
{
	int		line;
	t_data	*sprite;

	line = game->width + 1;
	if (let_inc(game->map[game->player->pos - 1], "PC0EO"))
	{
		sprite = get_sprite_content(game, game->map[game->player->pos - 1]);
		print_sprite(game, sprite, game->player->pos - 1);
	}
	if (let_inc(game->map[game->player->pos + 1], "PC0EO"))
	{
		sprite = get_sprite_content(game, game->map[game->player->pos + 1]);
		print_sprite(game, sprite, game->player->pos + 1);
	}
	if (let_inc(game->map[game->player->pos - line], "PC0EO"))
	{
		sprite = get_sprite_content(game, game->map[game->player->pos - line]);
		print_sprite(game, sprite, game->player->pos - line);
	}
	if (let_inc(game->map[game->player->pos + line], "PC0EO"))
	{
		sprite = get_sprite_content(game, game->map[game->player->pos + line]);
		print_sprite(game, sprite, game->player->pos + line);
	}
}
