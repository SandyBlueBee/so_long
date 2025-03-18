/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:21:28 by syukna            #+#    #+#             */
/*   Updated: 2025/03/18 13:12:15 by syukna           ###   ########.fr       */
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
	int i;

	i = 0;
	while (s[i] != 'P')
		i++;
	return (i);
}

void	init_game(int argc, char **argv, t_game *game)
{
	int		fd;

	if (argc != 2 || not_ber_file(argv[1]))
	{
		if (not_ber_file(argv[1]))
			ft_printf("Error\nFile File is not in .ber format!");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nFile does not exist!");
		close(fd);
		exit(EXIT_FAILURE);
	}
	game->map = is_map_valid(fd);
	close(fd);
	game->mlx = mlx_init();
	game->player = ft_calloc(1, sizeof(t_character));
	if (!game->player)
		close_game(game);
	game->player->next = NULL;
	game->player->pos = get_player_pos(game->map);
	game->moves = 0;

	// BONUS
	game->ghost = NULL;
}
