/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:19:07 by syukna            #+#    #+#             */
/*   Updated: 2025/03/13 12:54:17 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// /**
//  * @brief prints 1 sprite at a time
//  * @param mlx which was initiated
//  * @param mlx_win to add to window
//  */
// void	get_sprint_wall_loc(char letter)
// {
// 	if (letter == 'P') 
//         sprite->sprite_location = S_STAIRS;
// 	else if (letter == 'C') 
//         sprite->sprite_location = S_BEER;
// 	else if (letter == '6') 
//         sprite->sprite_location = S_WALL_UP_L;
// 	else if (letter == 'U') 
//         sprite->sprite_location = S_WALL_UP;
// 	else if (letter == '7') 
//         sprite->sprite_location = S_WALL_UP_R;
// 	else if (letter == 'L') 
//         sprite->sprite_location = S_WALL_L;
// 	else if (letter == 'R') 
//         sprite->sprite_location = S_WALL_R;
// 	else if (letter == '8') 
//         sprite->sprite_location = S_WALL_DOWN_L;
// 	else if (letter == '9') 
//         sprite->sprite_location = S_WALL_DOWN_R;
// 	else if (letter == 'D') 
//         sprite->sprite_location = S_WALL_DOWN;
// 	else if (letter == 'H') 
// 		sprite->sprite_location = S_TABLE_H;
// 	else if (letter == 'V') 
// 		sprite->sprite_location = S_TABLE_V;
// 	else if (letter == 'B') 
// 		sprite->sprite_location = S_BUSH;
// 	else if (letter == 'E') 
// 		sprite->sprite_location = S_TRAP_CLOSED;
// 	else if (letter == 'O') 
// 		sprite->sprite_location = S_TRAP_OPEN;
// 	else 
// 		sprite->sprite_location = S_FLOOR;
// }

t_data	*get_sprite(t_game *game, char letter)
{
	if (letter == 'P') 
        return (game->textures.floor);
	else if (letter == 'C') 
		return (game->textures.beer);
	else if (letter == '6') 
		return (game->textures.wall_up_l);
	else if (letter == 'U') 
		return (game->textures.wall_up);
	else if (letter == '7') 
		return (game->textures.wall_up_r);
	else if (letter == 'L') 
		return (game->textures.wall_l);
	else if (letter == 'R') 
		return (game->textures.wall_r);
	else if (letter == '8') 
		return (game->textures.wall_down_l);
	else if (letter == 'D') 
		return (game->textures.wall_down);
	else if (letter == '9') 
		return (game->textures.wall_down_r);
	else if (letter == 'H') 
		return (game->textures.table_h);
	else if (letter == 'V') 
		return (game->textures.table_v);
	else if (letter == 'B') 
		return (game->textures.bush);
	else if (letter == 'E') 
		return (game->textures.trap_closed);
	else if (letter == 'O') 
		return (game->textures.trap_open);
	else 
		return (game->textures.floor);
}

void	print_sprite(t_game *game, t_data *sprite, int pos)
{
	int x;
	int y;
	
	if (!sprite || !game->map || pos < 0)
		return;
	if (game->map[pos] == '\n')
		return ;
	x = (pos % (game->width + 1));
	y = (pos / (game->width + 1));
	mlx_put_image_to_window(game->mlx, game->mlx_win, sprite, x * 100, y * 100);
}

void	print_screen(t_game *game)
{
	int	i;
	t_data	*sprite;
	
	i = 0;
	while (game->map[i] != '\0')
	{
		if (game->map[i] != '\n')
		{
			sprite = get_sprite(game, game->map[i]);
			print_sprite(game, sprite, i);
		}
		i++;
	}
	
}

void	print_player(t_game *game)
{
	print_sprite(game, game->textures.player, game->player.pos);
}

/**
 * @brief reconfigure map and prints first map
 * @param mlx which was initiated
 * @param mlx_win to add to window
 */
void	open_screen(t_game *game)
{
	init_textures(game);
	print_screen(game);
	print_player(game);
}