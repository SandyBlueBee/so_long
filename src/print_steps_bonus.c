/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_steps_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 10:43:35 by syukna            #+#    #+#             */
/*   Updated: 2025/03/21 18:31:49 by syukna           ###   ########.fr       */
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
int	animate_drink(t_game *game)
{
	static int	frame_delay = 0;
	static int	current_frame = 0; 
	t_data *animation[4];

	animation[0] = game->textures->player_bef;
	animation[1] = game->textures->player_b;
	animation[2] = game->textures->player_b;
	animation[3] = game->textures->player_aft;
	if (game->drinking == 1)
	{
		print_sprite(game, animation[current_frame],game->player->pos);
		if (frame_delay++ < 10000)
			return (0);
		if (current_frame == 3)
			current_frame = 0;
		else
			current_frame++;
		frame_delay = 0;
	}
	return (0);
}

void	print_square_steps(t_game *game)
{
	int		pos;
	int		line;
	t_data	*move;
	t_data	*move_beer;

	pos = game->player->pos;
	line = game->width + 1;
	move = game->textures->move;
	move_beer = game->textures->move_beer;
	if (game->map[pos - 1] == '0')
		print_sprite(game, move, pos - 1);
	if (game->map[pos - line] == '0')
		print_sprite(game, move, pos - line);
	if (game->map[pos + 1] == '0')
		print_sprite(game, move, pos + 1);
	if (game->map[pos + line] == '0')
		print_sprite(game, move, pos + line);
	if (game->map[pos - 1] == 'C')
		print_sprite(game, move_beer, pos - 1);
	if (game->map[pos - line] == 'C')
		print_sprite(game, move_beer, pos - line);
	if (game->map[pos + 1] == 'C')
		print_sprite(game, move_beer, pos + 1);
	if (game->map[pos + line] == 'C')
		print_sprite(game, move_beer, pos + line);
}

void	reset_square_steps(t_game *game)
{
	int		pos;
	int		line;
	t_data	*floor;
	t_data	*beer;

	pos = game->player->pos;
	line = game->width + 1;
	floor = game->textures->floor;
	beer = game->textures->beer;
	if (game->map[pos - 1] == '0')
		print_sprite(game, floor, pos - 1);
	if (game->map[pos - line] == '0')
		print_sprite(game, floor, pos - line);
	if (game->map[pos + 1] == '0')
		print_sprite(game, floor, pos + 1);
	if (game->map[pos + line] == '0')
		print_sprite(game, floor, pos + line);
	if (game->map[pos - 1] == 'C')
		print_sprite(game, beer, pos - 1);
	if (game->map[pos - line] == 'C')
		print_sprite(game, beer, pos - line);
	if (game->map[pos + 1] == 'C')
		print_sprite(game, beer, pos + 1);
	if (game->map[pos + line] == 'C')
		print_sprite(game, beer, pos + line);
}
