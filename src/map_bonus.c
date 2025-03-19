/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:56:06 by syukna            #+#    #+#             */
/*   Updated: 2025/03/19 11:13:26 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	count_letter(char *map, char letter)
{
	int i;
    int count;

    i = 0;
    count = 0;
    while (map[i] != '\0')
    {
        if (map[i] == letter)
            count++;
        i++;
    }
	return (count);
}

void	ratio_beer_floor(t_game *game)
{
    int beers;
    int floors;

    beers = count_letter(game->map, 'C');
    floors = count_letter(game->map, '0');
    ft_printf("beers = %d floor = %d, divi %d \n", beers, floors,floors/beers);
	if ((floors/beers) < 5)
    {
        ft_printf("Error\nThere are too many beers in this map\n");
        close_game(game);
    }
}
void	is_there_bush(t_game *game)
{
    if (count_letter(game->map, 'B') >= 1)
        return ;
    ft_printf("Error\nThere are too may beers in this map\n");
    close_game(game);
}

void	test_bonus_map(t_game *game)
{
    ratio_beer_floor(game);
    is_there_bush(game);
}