/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 11:56:47 by syukna            #+#    #+#             */
/*   Updated: 2025/03/22 11:57:29 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	animate_drink(t_game *game)
{
	static int	frame_delay = 0;
	static int	current_frame = 0;
	t_data		*animation[4];

	animation[0] = game->textures->player_bef;
	animation[1] = game->textures->player_b;
	animation[2] = game->textures->player_b;
	animation[3] = game->textures->player_aft;
	if (game->drinking == 1)
	{
		print_sprite(game, animation[current_frame], game->player->pos);
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
