/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:53:51 by syukna            #+#    #+#             */
/*   Updated: 2025/03/10 20:13:34 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/**
 * @brief returns the right sprite
 * @param mlx which was initiated
 * @param mlx_win to add to window
 */
void	printing_sprite(t_game *game, t_sprite*sprite)
{
	t_data	*img;
	int		img_width;
	int		img_height;
	char	*relative_path;

	relative_path = sprite->sprite_location;
	img = mlx_xpm_file_to_image(game->mlx, relative_path, &img_width, &img_height);
	if (!img)
		{
			perror("Error: Failed to load image\n");
			return;
		}
	mlx_put_image_to_window(game->mlx, game->mlx_win, img, sprite->x, sprite->y);
}
/**
 * @brief prints 1 sprite at a time
 * @param mlx which was initiated
 * @param mlx_win to add to window
 */
void	get_sprint_loc(t_sprite *sprite, char letter)
{
	if (letter == 'P') 
        sprite->sprite_location = S_PLAYER;
	else if (letter == 'C') 
        sprite->sprite_location = S_BEER;
	else if (letter == '6') 
        sprite->sprite_location = S_WALL_UP_L;
	else if (letter == 'U') 
        sprite->sprite_location = S_WALL_UP;
	else if (letter == '7') 
        sprite->sprite_location = S_WALL_UP_R;
	else if (letter == 'L') 
        sprite->sprite_location = S_WALL_L;
	else if (letter == 'R') 
        sprite->sprite_location = S_WALL_R;
	else if (letter == '8') 
        sprite->sprite_location = S_WALL_DOWN_L;
	else if (letter == '9') 
        sprite->sprite_location = S_WALL_DOWN_R;
	else if (letter == 'D') 
        sprite->sprite_location = S_WALL_DOWN;
	else if (letter == 'H') 
		sprite->sprite_location = S_TABLE_H;
	else if (letter == 'V') 
		sprite->sprite_location = S_TABLE_V;
	else if (letter == 'E') 
		sprite->sprite_location = S_TRAP_OPEN;
	else 
		sprite->sprite_location = S_FLOOR;
}

/**
 * @brief prints 1 sprite at a time
 * @param mlx which was initiated
 * @param mlx_win to add to window
 */
void	print_sprite(t_game *game, char letter, int x, int y)
{
	t_sprite	*sprite;

	sprite = malloc(sizeof(t_sprite));
	if (sprite == NULL)  // Always check if malloc succeeds
    {
        printf("Memory allocation failed\n");
        return;
    }
	get_sprint_loc(sprite, letter);
	sprite->x = x;
	sprite->y = y;
	printing_sprite(game, sprite);
	free(sprite);
}
/**
 * @brief Prints full map by sending the right locations to be printed
 * @param mlx which was initiated
 * @param mlx_win to add to window
 */
void	print_screen(t_game *game)
{
	printf("%s",game->map);
	int	i;
	int	x;
	int	y;
	
	i = 0;
	x = 0;
	y = 0;
	while (game->map[i] != '\0')
	{
		print_sprite(game, game->map[i], x, y);
		x += 100;
		i++;
		if (game->map[i] == '\n')
		{
			i++;
			x = 0;
			y += 100;
		}
	}
}


/**
 * @brief reconfigure map and prints first map
 * @param mlx which was initiated
 * @param mlx_win to add to window
 */
void	open_screen(t_game *game)
{
	print_screen(game);
}

// void	open_screen(void *mlx, void *mlx_win)
// {
// 	t_data	img;
// 	img.img = mlx_new_image(mlx, 100, 100);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// 	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);

// 	for (int y = 0; y < 100; y++) {
// 		for (int x = 0; x < 100; x++) {
// 			my_mlx_pixel_put(&img, x, y, 0x00FF0000); // Red Square
// 		}
// 	}
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 300,300);
// 	print_img(mlx, mlx_win);

// }


// void	my_mlx_pixel_put(t_data	*data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x *(data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }