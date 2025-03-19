/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:19:07 by syukna            #+#    #+#             */
/*   Updated: 2025/03/19 13:00:44 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	print_sprite(t_game *game, t_data *sprite, int pos)
{
	int	x;
	int	y;

	if (!sprite || !game->map || pos < 0)
		return ;
	if (game->map[pos] == '\n')
		return ;
	x = (pos % (game->width + 1));
	y = (pos / (game->width + 1));
	mlx_put_image_to_window(game->mlx, game->mlx_win, sprite, x * 100, y * 100);
}

void	print_screen(t_game *game)
{
	int		i;
	t_data	*sprite;

	i = 0;
	while (game->map[i] != '\0')
	{
		if (game->map[i] != '\n')
		{
			if (is_letter_included(game->map[i], "6789UDLR"))
				sprite = get_sprite_wall(game, game->map[i]);
			else
				sprite = get_sprite_content(game, game->map[i]);
			print_sprite(game, sprite, i);
		}
		i++;
	}
}

void	print_player(t_game *game)
{
	print_sprite(game, game->textures->player, game->player->pos);
}

/**
 * @brief reconfigure map and prints first map
 * @param mlx which was initiated
 * @param mlx_win to add to window
 */
void	open_screen(t_game *game)
{
	init_textures(game);
	print_screen(game);
	print_player(game);
}
