/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:21:28 by syukna            #+#    #+#             */
/*   Updated: 2025/03/12 18:21:46 by syukna           ###   ########.fr       */
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
	if (not_ber_file(argv[1]))
		ft_printf("Error\nFile File is not in .ber format!");
	if (argc != 2 || not_ber_file(argv[1]))
		close_game(game);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nFile does not exist!");
		close_game(game);
	}
	game->map = is_map_valid(fd);
	close(fd);
	game->mlx = mlx_init();
	game->player.char_location = S_PLAYER;
	game->player.pos = get_player_pos(game->map);
	printf("player = %d\n\n", game->player.pos);
}