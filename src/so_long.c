/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:51:45 by syukna            #+#    #+#             */
/*   Updated: 2025/03/10 20:28:50 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(void)
{
	int		fd;
	t_game	*game;

	game = malloc(sizeof(t_game));
	fd = open("maps/map-test.ber", O_RDONLY);
	game->map = is_map_valid(fd);
	close(fd);
	game->mlx = mlx_init();
	improve_map(game);
	game->mlx_win = mlx_new_window(game->mlx, game->width * 100, game->height * 100, "Current map");
	open_screen(game);
	mlx_loop(game->mlx);
	// ft_printf("%s", mapstr);
	return (0);
}
