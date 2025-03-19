/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:04:36 by syukna            #+#    #+#             */
/*   Updated: 2025/03/19 14:55:49 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	let_inc(char letter, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (letter == str[i])
			return (1);
		i++;
	}
	return (0);
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
	if (nbr == 2)
	{
		if (j >= 1)
			return (1);
	}
	else if (j == nbr)
		return (1);
	return (0);
}
