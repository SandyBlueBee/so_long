/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:56:06 by syukna            #+#    #+#             */
/*   Updated: 2025/03/18 15:02:19 by syukna           ###   ########.fr       */
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

int	test_bonus_map(char *map)
{
	if (map)
    {
        
    }
		return (1);
	return (0);
}