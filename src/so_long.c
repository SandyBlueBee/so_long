/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:51:45 by syukna            #+#    #+#             */
/*   Updated: 2025/03/04 16:56:47 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(void)
{
	int		fd;
	char	*mapstr;
	// static struct t_game game;

	fd = open("maps/map-test.ber", O_RDONLY);
	mapstr = is_map_valid(fd);
	close(fd);
	if (!mapstr)
		return (0);
	ft_printf("%s", mapstr);
	return (0);
}