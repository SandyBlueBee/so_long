/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:51:45 by syukna            #+#    #+#             */
/*   Updated: 2025/03/06 15:03:08 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(void)
{
	int		fd;
	char	*mapstr;
	void	*mlx;
	void	*mlx_win;
	// static struct t_game game;

	fd = open("maps/map-test.ber", O_RDONLY);
	mapstr = is_map_valid(fd);
	close(fd);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Current map");
	open_screen(mlx, mlx_win);
	mlx_loop(mlx);
	// ft_printf("%s", mapstr);
	return (0);
}
