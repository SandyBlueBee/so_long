/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:51:45 by syukna            #+#    #+#             */
/*   Updated: 2025/03/18 19:12:24 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		h;
	int		w;

	init_game(argc, argv, &game);
	improve_map(&game);
	test_bonus_map(&game);
	h = game.height * 100;
	w = game.width * 100;
	game.mlx_win = mlx_new_window(game.mlx, w, h, "Oktoberfest");
	open_screen(&game);
	mlx_key_hook(game.mlx_win, key_hook, &game);
	mlx_hook(game.mlx_win, DESTROY_NOTIFY, NO_MASK, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
