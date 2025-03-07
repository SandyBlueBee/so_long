/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:53:51 by syukna            #+#    #+#             */
/*   Updated: 2025/03/07 19:36:53 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	my_mlx_pixel_put(t_data	*data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x *(data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	print_img(void *mlx, void *mlx_win)
{
	void	*img;
	int		img_width;
	int		img_height;
	char	*relative_path;

	// img_width = 600;
	// img_height = 557;
	relative_path = "textures/wall_up.xpm";
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	relative_path = "textures/wall_up.xpm";
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	mlx_put_image_to_window(mlx, mlx_win, img, 100, 0);
	mlx_put_image_to_window(mlx, mlx_win, img, 200, 0);
	mlx_put_image_to_window(mlx, mlx_win, img, 300, 0);
	mlx_put_image_to_window(mlx, mlx_win, img, 400, 0);
	relative_path = "textures/table_v.xpm";
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	if (!img)
	{
		perror("Error: Failed to load image\n");
		return;
	}
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 100);
	relative_path = "textures/beer.xpm";
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	if (!img)
	{
		perror("Error: Failed to load image\n");
		return;
	}
	mlx_put_image_to_window(mlx, mlx_win, img, 100, 100);
	relative_path = "textures/table_h.xpm";
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	if (!img)
	{
		perror("Error: Failed to load image\n");
		return;
	}
	mlx_put_image_to_window(mlx, mlx_win, img, 200, 100);
	relative_path = "textures/floor.xpm";
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	if (!img)
	{
		perror("Error: Failed to load image\n");
		return;
	}
	mlx_put_image_to_window(mlx, mlx_win, img, 300, 100);
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 200);
	mlx_put_image_to_window(mlx, mlx_win, img, 100, 200);
	mlx_put_image_to_window(mlx, mlx_win, img, 200, 200);
	mlx_put_image_to_window(mlx, mlx_win, img, 300, 200);
	mlx_put_image_to_window(mlx, mlx_win, img, 400, 200);
	relative_path = "textures/char.xpm";
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	if (!img)
	{
		perror("Error: Failed to load image\n");
		return;
	}
	mlx_put_image_to_window(mlx, mlx_win, img, 400, 100);
}

void	open_screen(void *mlx, void *mlx_win)
{
	t_data	img;
	img.img = mlx_new_image(mlx, 100, 100);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);

	for (int y = 0; y < 100; y++) {
		for (int x = 0; x < 100; x++) {
			my_mlx_pixel_put(&img, x, y, 0x00FF0000); // Red Square
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 300,300);
	print_img(mlx, mlx_win);

}