/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_steps_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 10:43:35 by syukna            #+#    #+#             */
/*   Updated: 2025/03/21 15:27:03 by syukna           ###   ########.fr       */
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
	int	x;
	int	y;

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
	mlx_string_put(game->mlx, game->mlx_win, x, y, 0x00FFFFFF, ft_itoa(game->moves));
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
