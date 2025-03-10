/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:15:24 by syukna            #+#    #+#             */
/*   Updated: 2025/03/10 18:02:02 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

/* ************************************************************************** */
/* ******************************STRUCTURES********************************** */
/* ************************************************************************** */

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_sprite
{
	char	*sprite_location;
	int		x;
	int		y;
}				t_sprite;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	char	*map;
	int		height;
	int		width;
}				t_game;

#endif // STRUCTURES_H