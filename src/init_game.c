/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:21:28 by syukna            #+#    #+#             */
/*   Updated: 2025/03/19 14:54:09 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	not_ber_file(char *s)
{
	int	len;

	len = ft_strlen(s);
	return (ft_strncmp(&s[len - 4], ".ber", 4));
}

int	get_player_pos(char *s)
{
	int	i;

	i = 0;
	while (s[i] != 'P')
		i++;
	return (i);
}

int	check_file(int argc, char **argv, t_game *game)
{
	int		fd;

	if (argc != 2 || not_ber_file(argv[1]))
	{
		if (not_ber_file(argv[1]))
			ft_printf("Error\nFile File is not in .ber format!");
		close_game(game);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nFile does not exist!");
		close(fd);
		close_game(game);
	}
	return (fd);
}

void	init_game(int argc, char **argv, t_game *game)
{
	int		fd;

	fd = check_file(argc, argv, game);
	game->textures = NULL;
	game->mlx_win = NULL;
	game->map = is_map_valid(fd);
	close(fd);
	game->mlx = mlx_init();
	game->player = ft_calloc(1, sizeof(t_character));
	if (!game->player)
		close_game(game);
	game->player->next = NULL;
	game->player->pos = get_player_pos(game->map);
	game->moves = 0;
	game->ghost = NULL;
}
