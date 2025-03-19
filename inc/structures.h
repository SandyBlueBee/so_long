/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:15:24 by syukna            #+#    #+#             */
/*   Updated: 2025/03/19 16:54:38 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

/* ************************************************************************** */
/* ******************************STRUCTURES********************************** */
/* ************************************************************************** */

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_textures
{
	t_data	*player;
	t_data	*player_trap;
	t_data	*player_b;
	t_data	*floor;
	t_data	*beer;
	t_data	*wall_up_l;
	t_data	*wall_up;
	t_data	*wall_up_r;
	t_data	*wall_l;
	t_data	*wall_r;
	t_data	*wall_down_l;
	t_data	*wall_down;
	t_data	*wall_down_r;
	t_data	*table_h;
	t_data	*table_v;
	t_data	*bush;
	t_data	*trap_closed;
	t_data	*trap_open;
	t_data	*sign;
	// BONUS
	t_data	*ghost;
	t_data	*ghost_bush;
	t_data	*ghost_th;
	t_data	*ghost_tv;
}				t_textures;

typedef struct s_sprite
{
	char	*sprite_location;
	int		x;
	int		y;
}				t_sprite;

typedef struct s_character
{
	struct s_character	*next;
	int					pos;
}				t_character;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	char		*map;
	int			beers;
	int			height;
	int			width;
	int			moves;
	t_textures	*textures;
	t_character	*player;

	// BONUS
	t_character	*ghost;
	int			bushes;

}				t_game;

#endif // STRUCTURES_H