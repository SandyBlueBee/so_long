/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:51:45 by syukna            #+#    #+#             */
/*   Updated: 2025/03/12 18:21:50 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	init_game(argc, argv, &game);
	improve_map(&game);
	game.mlx_win = mlx_new_window(game.mlx, game.width * 100, game.height * 100, "Oktoberfest");
	open_screen(&game);

	mlx_key_hook(game.mlx_win, key_hook, &game);
	
	mlx_loop(game.mlx);
	return (0);
}
