/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:31:26 by syukna            #+#    #+#             */
/*   Updated: 2025/03/12 18:55:45 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_sprites(t_game *game)
{
	t_textures *text;
	int		img_width;
	int		img_height;
	
	text = &game->textures;
	text->player = mlx_xpm_file_to_image(game->mlx, S_PLAYER, &img_width, &img_height);
	text->floor = mlx_xpm_file_to_image(game->mlx, S_FLOOR, &img_width, &img_height);
	text->beer = mlx_xpm_file_to_image(game->mlx, S_BEER, &img_width, &img_height);
	text->bush = mlx_xpm_file_to_image(game->mlx, S_BUSH, &img_width, &img_height);
	text->table_h = mlx_xpm_file_to_image(game->mlx, S_TABLE_H, &img_width, &img_height);
	text->table_v = mlx_xpm_file_to_image(game->mlx, S_TABLE_V, &img_width, &img_height);
	text->wall_up_l = mlx_xpm_file_to_image(game->mlx, S_WALL_UP_L, &img_width, &img_height);
	text->wall_up = mlx_xpm_file_to_image(game->mlx, S_WALL_UP, &img_width, &img_height);
	text->wall_up_r = mlx_xpm_file_to_image(game->mlx, S_WALL_UP_R, &img_width, &img_height);
	text->wall_l = mlx_xpm_file_to_image(game->mlx, S_WALL_L, &img_width, &img_height);
	text->wall_r = mlx_xpm_file_to_image(game->mlx, S_WALL_R, &img_width, &img_height);
	text->wall_down_l = mlx_xpm_file_to_image(game->mlx, S_WALL_DOWN_L, &img_width, &img_height);
	text->wall_down = mlx_xpm_file_to_image(game->mlx, S_WALL_DOWN, &img_width, &img_height);
	text->wall_down_r = mlx_xpm_file_to_image(game->mlx, S_WALL_DOWN_R, &img_width, &img_height);
	text->stairs = mlx_xpm_file_to_image(game->mlx, S_STAIRS, &img_width, &img_height);
	text->trap_closed = mlx_xpm_file_to_image(game->mlx, S_TRAP_CLOSED, &img_width, &img_height);
	text->trap_open = mlx_xpm_file_to_image(game->mlx, S_TRAP_OPEN, &img_width, &img_height);
}

void	init_textures(t_game *game)
{
	init_sprites(game);
}