/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:13:58 by syukna            #+#    #+#             */
/*   Updated: 2025/03/13 19:19:29 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_textures_walls(t_game *game)
{
	if (game->textures->wall_up_l)
		mlx_destroy_image(game->mlx, game->textures->wall_up_l);
	if (game->textures->wall_up)
		mlx_destroy_image(game->mlx, game->textures->wall_up);
	if (game->textures->wall_up_r)
		mlx_destroy_image(game->mlx, game->textures->wall_up_r);
	if (game->textures->wall_l)
		mlx_destroy_image(game->mlx, game->textures->wall_l);
	if (game->textures->wall_r)
		mlx_destroy_image(game->mlx, game->textures->wall_r);
	if (game->textures->wall_down_l)
		mlx_destroy_image(game->mlx, game->textures->wall_down_l);
	if (game->textures->wall_down)
		mlx_destroy_image(game->mlx, game->textures->wall_down);
	if (game->textures->wall_down_r)
		mlx_destroy_image(game->mlx, game->textures->wall_down_r);
}

void	free_textures_content(t_game *game)
{
	if (game->textures->player)
		mlx_destroy_image(game->mlx, game->textures->player);
	if (game->textures->player_trap)
		mlx_destroy_image(game->mlx, game->textures->player_trap);
	if (game->textures->player_drink)
		mlx_destroy_image(game->mlx, game->textures->player_drink);
	if (game->textures->beer)
		mlx_destroy_image(game->mlx, game->textures->beer);
	if (game->textures->floor)
		mlx_destroy_image(game->mlx, game->textures->floor);
	if (game->textures->bush)
		mlx_destroy_image(game->mlx, game->textures->bush);
	if (game->textures->table_h)
		mlx_destroy_image(game->mlx, game->textures->table_h);
	if (game->textures->table_v)
		mlx_destroy_image(game->mlx, game->textures->table_v);
	if (game->textures->trap_closed)
		mlx_destroy_image(game->mlx, game->textures->trap_closed);
	if (game->textures->trap_open)
		mlx_destroy_image(game->mlx, game->textures->trap_open);
}

int	close_game(t_game *game)
{
	if (game->textures)
	{
		free_textures_walls(game);
		free_textures_content(game);
		free(game->textures);
	}
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map)
		free(game->map);
	if (game->player)
		free(game->player);
	exit(EXIT_SUCCESS);
	return (0);
}
