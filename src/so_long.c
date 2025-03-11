/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:51:45 by syukna            #+#    #+#             */
/*   Updated: 2025/03/11 17:39:14 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	not_ber_file(char *s)
{
	int	len;

	len = ft_strlen(s);
	return (ft_strncmp(&s[len - 4], ".ber", 4));
}

int	main(int argc, char **argv)
{
	int		fd;
	t_game	*game;

	if (not_ber_file(argv[1]))
		ft_printf("Error\nFile File is not in .ber format!");
	if (argc != 2 || not_ber_file(argv[1]))
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_printf("Error\nFile does not exist!");
	game = malloc(sizeof(t_game));
	game->map = is_map_valid(fd);
	close(fd);
	game->mlx = mlx_init();
	improve_map(game);
	game->mlx_win = mlx_new_window(game->mlx, game->width * 100, game->height * 100, "Oktoberfest");
	open_screen(game);

	mlx_key_hook(game->mlx_win, key_hook, game);
	
	mlx_loop(game->mlx);
	return (0);
}
