/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:51:45 by syukna            #+#    #+#             */
/*   Updated: 2025/03/13 12:42:30 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

#define DESTROY_NOTIFY 17  // Event code for window close
#define NO_MASK 0

int	main(int argc, char **argv)
{
	t_game	game;

	init_game(argc, argv, &game);
	improve_map(&game);
	game.mlx_win = mlx_new_window(game.mlx, game.width * 100, game.height * 100, "Oktoberfest");
	open_screen(&game);

	mlx_key_hook(game.mlx_win, key_hook, &game);
	mlx_hook(game.mlx_win, DESTROY_NOTIFY, NO_MASK, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
