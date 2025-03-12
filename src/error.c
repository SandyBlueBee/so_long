/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:46:43 by syukna            #+#    #+#             */
/*   Updated: 2025/03/12 20:04:57 by syukna           ###   ########.fr       */
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
	if (!included_char(map, 'C', 2))
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

void	filler(char *map, int i, int len)
{
	if ((i - len) >= 0)
		if (map[i - len] == '0' || map[i - len] == 'C' || map[i - len] == 'E')
		{
			map[i - len] = 'F';
			filler(map, i - len, len);
		}
	if ((i - 1) >= 0)
		if (map[i - 1] == '0' || map[i - 1] == 'C' || map[i - 1] == 'E')
		{
			map[i - 1] = 'F';
			filler(map, i - 1, len);
		}
	if ((i + len) <= (int)ft_strlen(map))
		if (map[i + len] == '0' || map[i + len] == 'C' || map[i + len] == 'E')
		{
			map[i + len] = 'F';
			filler(map, i + len, len);
		}
	if ((i + 1) <= (int)ft_strlen(map))
		if (map[i + 1] == '0' || map[i + 1] == 'C' || map[i + 1] == 'E')
		{
			map[i + 1] = 'F';
			filler(map, i + 1, len);
		}
}

int	flood_fill(char *map)
{
	char *map_copy;
	int i;
	int len;

	map_copy = ft_calloc(ft_strlen(map) + 1, 1);
	ft_strlcpy(map_copy, map, ft_strlen(map) + 1);
	i = 0;
	len = 0;
	while (map[i] != 'P')
		i++;
	while (map[len] != '\n')
		len++;
	filler(map_copy, i, len + 1);
	if (!included_char(map_copy, 'C', 0))
		return (0);
	if (!included_char(map_copy, 'E', 0))
		return (0);
	return (1);
}

int check_error(char *map)
{
	if (!is_rect(map))
	{
		ft_printf("%s", "Error \nThis map is not a rectangle.");
		return (1);
	}
	if (!flood_fill(map))
	{
		ft_printf("%s", "Error \nThis map does not have a valid path.");
		return (1);
	}
	if (!are_all_there(map))
		return (1);
	if (!is_closed(map))
	{
		ft_printf("%s", "Error \nThis map is not surrounded by walls.%s", map);
		return (1);
	}
	if (!only_known_chars(map))
		return (1);
	return (0);
}