/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:00:31 by syukna            #+#    #+#             */
/*   Updated: 2025/03/11 14:37:20 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	get_dimensions(t_game *game)
{
	int	i;
	int	height;

	i = 0;
	height = 0;
	while (game->map[i] != '\n')
		i++;
	game->width = i;
	i = 0;
	while (game->map[i] != '\0')
	{
		if (game->map[i] == '\n')
			height++;
		i++;
	}
	game->height = height + 1;
}

char	get_table(void)
{
	int	r;
	char	letter;

	r = rand() % 2;
	if (r == 1)
		letter = 'H';
	else
		letter = 'V';
	return (letter);
}
void	add_panel(int i, int len, t_game *game)
{
	game->map[i] = '8';
	i++;
	while (i < (len - 1))
		game->map[i++] = 'D';
	game->map[len - 1] = '9';
}


void	add_borders(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	game->map[i++] = '6';
	while (i < game->width - 1)
		game->map[i++] = 'U';
	game->map[i++] = '7';
	len = ft_strlen(game->map);
	while (i < (len - game->width - 1))
	{
		if (game->map[i] == '\n')
			i++;
		if (i % (game->width + 1) == 0)
			game->map[i] = 'L';
		else if ((i + 2) % (game->width + 1) == 0)
			game->map[i] = 'R';
		else if (game->map[i] == '1')
			game->map[i] = get_table();
		i++;
	}
	i++;
	add_panel(i, len, game);
}

void	improve_map(t_game *game)
{
	get_dimensions(game);
	add_borders(game);
	game->beers = ft_countchar(game->map, 'C');
}