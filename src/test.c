/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:04:36 by syukna            #+#    #+#             */
/*   Updated: 2025/03/19 13:05:45 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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