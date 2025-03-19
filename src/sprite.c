/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:01:02 by syukna            #+#    #+#             */
/*   Updated: 2025/03/19 13:01:10 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_data	*get_sprite_wall(t_game *game, char letter)
{
	
	if (letter == '6')
		return (game->textures->wall_up_l);
	else if (letter == '7')
		return (game->textures->wall_up_r);
	else if (letter == '8')
		return (game->textures->wall_down_l);
	else if (letter == '9')
		return (game->textures->wall_down_r);
	else if (letter == 'U')
		return (game->textures->wall_up);
	else if (letter == 'D')
		return (game->textures->wall_down);
	else if (letter == 'L')
		return (game->textures->wall_l);
	else if (letter == 'R')
		return (game->textures->wall_r);
	else
		return (game->textures->floor);
}
t_data	*get_sprite_content(t_game *game, char letter)
{
	if (letter == 'P')
		return (game->textures->floor);
	else if (letter == 'C')
		return (game->textures->beer);
	else if (letter == 'H')
		return (game->textures->table_h);
	else if (letter == 'V')
		return (game->textures->table_v);
	else if (letter == 'B')
		return (game->textures->bush);
	else if (letter == 'E')
		return (game->textures->trap_closed);
	else if (letter == 'O')
		return (game->textures->trap_open);
	else
		return (game->textures->floor);
}