/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:31:26 by syukna            #+#    #+#             */
/*   Updated: 2025/03/19 13:50:50 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_sprites(t_game *game)
{
	t_textures	*text;
	int			x;
	int			y;

	text = game->textures;
	text->player = mlx_xpm_file_to_image(game->mlx, S_PLAYER, &x, &y);
	text->player_trap = mlx_xpm_file_to_image(game->mlx, S_PLAYER_TRAP, &x, &y);
	text->player_b = mlx_xpm_file_to_image(game->mlx, S_PLAYER_DRINK, &x, &y);
	text->floor = mlx_xpm_file_to_image(game->mlx, S_FLOOR, &x, &y);
	text->beer = mlx_xpm_file_to_image(game->mlx, S_BEER, &x, &y);
	text->bush = mlx_xpm_file_to_image(game->mlx, S_BUSH, &x, &y);
	text->table_h = mlx_xpm_file_to_image(game->mlx, S_TABLE_H, &x, &y);
	text->table_v = mlx_xpm_file_to_image(game->mlx, S_TABLE_V, &x, &y);
	text->wall_up_l = mlx_xpm_file_to_image(game->mlx, S_WALL_UP_L, &x, &y);
	text->wall_up = mlx_xpm_file_to_image(game->mlx, S_WALL_UP, &x, &y);
	text->wall_up_r = mlx_xpm_file_to_image(game->mlx, S_WALL_UP_R, &x, &y);
	text->wall_l = mlx_xpm_file_to_image(game->mlx, S_WALL_L, &x, &y);
	text->wall_r = mlx_xpm_file_to_image(game->mlx, S_WALL_R, &x, &y);
	text->wall_down_l = mlx_xpm_file_to_image(game->mlx, S_WALL_DOWN_L, &x, &y);
	text->wall_down = mlx_xpm_file_to_image(game->mlx, S_WALL_DOWN, &x, &y);
	text->wall_down_r = mlx_xpm_file_to_image(game->mlx, S_WALL_DOWN_R, &x, &y);
	text->trap_closed = mlx_xpm_file_to_image(game->mlx, S_TRAP_CLOSED, &x, &y);
	text->trap_open = mlx_xpm_file_to_image(game->mlx, S_TRAP_OPEN, &x, &y);
}
// BONUS

void	init_sprites_bonus(t_game *game)
{
	t_textures	*text;
	int			x;
	int			y;

	text = game->textures;
	text->ghost = mlx_xpm_file_to_image(game->mlx, S_GHOST, &x, &y);
	text->ghost_bush = mlx_xpm_file_to_image(game->mlx, S_GHOST_BUSH, &x, &y);
	text->ghost_th = mlx_xpm_file_to_image(game->mlx, S_GHOST_TABLE_H, &x, &y);
	text->ghost_tv = mlx_xpm_file_to_image(game->mlx, S_GHOST_TABLE_V, &x, &y);
}

void	init_textures(t_game *game)
{
	game->textures = ft_calloc(1, sizeof(t_textures));
	if (!game->textures)
	{
		ft_printf("Error\nFailed to allocate memory for textures.\n");
		close_game(game);
	}
	init_sprites(game);
	init_sprites_bonus(game);
}
