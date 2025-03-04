/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:46:43 by syukna            #+#    #+#             */
/*   Updated: 2025/03/04 17:04:51 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int are_all_there(char *map)
{
	if (!included_char(map, 'E', 1))
	{
		ft_printf("%s", "Error \nThis map does not have 1 exit 'E'.");
		return (0);
	}
	if (!included_char(map, 'C', 1))
	{
		ft_printf("%s", "Error \nThis map does not have 1 collectible 'C'.");
		return (0);
	}
	if (!included_char(map, 'P', 1))
	{
		ft_printf("%s", "Error \nThis map does not have 1 starting position 'P'.");
		return (0);
	}
	return (1);
}

int	only_known_chars(char *map)
{
	ft_printf("%s", map);
	int	i;
	int	j;
	char set[] = "01CEP\n";
	
	i = 0;
	while (map[i])
	{
		j = 0;
		while (set[j])
			{
				if (map[i] == set[j])
					break;
				j++;
			}
		if (j >= 6)
		{
			ft_printf("%s", "Error \nThis map contains unknown elements.");
			return (0);
		}
		i++;
	}
	return (1);
}

int check_error(char *map)
{
	if (!is_rect(map))
	{
		ft_printf("%s", "Error \nThis map is not a rectangle.");
		return (1);
	}
	if (!are_all_there(map))
		return (1);
	if (!is_closed(map))
	{
		ft_printf("%s", "Error \nThis map is not surrounded by walls.");
		return (1);
	}
	if (!only_known_chars(map))
		return (1);
	return (0);
}