/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:51:28 by syukna            #+#    #+#             */
/*   Updated: 2025/03/06 12:56:19 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	count_char(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == c)
			j++;
		i++;
	}
	return (j);
}

int	full_wall(char *map, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (map[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	partial_wall(char *map, int len)
{
	int	i;

	i = 0;
	if (map[0] != '1')
		return (0);
	if (map[len - 1] != '1')
		return (0);
	return (1);
}

int	is_closed(char *map)
{
	int	lines;
	int	i;
	int	len;

	i = 0;
	len = 0;
	lines = count_char(map, '\n');
	while (map[i] != '\n')
		i++;
	len = i;
	if (!full_wall(map, len))
		return (0);
	i++;
	while (lines > 1)
	{
		if (!partial_wall(&map[i], len))
			return (0);
		i = i + len + 1;
		lines--;
	}
	if (!full_wall(&map[i], len))
		return (0);
	return (1);
}

int	is_rect(char *map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (map[i] != '\n')
		i++;
	len = i;
	while (map[i])
	{
		if (map[i] == '\n')
			i++;
		while (map[i] != '\n' && map[i] != '\0')
		{
			i++;
			j++;
		}
		if (j != len)
			return (0);
		j = 0;
		i++;
	}
	return (1);
}

int	included_char(char *str, char c, int nbr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == c)
			j++;
		i++;
	}
	if (j == nbr)
		return (1);
	return (0);
}

char	*is_map_valid(int fd)
{
	char	*str;
	char	*finalmapstr;

	str = get_next_line(fd);
	finalmapstr = ft_calloc(1, sizeof(char));
	if (!finalmapstr)
		return (NULL);
	while (str)
	{
		finalmapstr = get_current_line(finalmapstr, str);
		if (!finalmapstr)
			return (NULL);
		str = get_next_line(fd);
	}
	if (check_error(finalmapstr))
		exit(EXIT_FAILURE);
	return (finalmapstr);
}