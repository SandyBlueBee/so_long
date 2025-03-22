/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:58:23 by syukna            #+#    #+#             */
/*   Updated: 2025/03/22 12:00:40 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

/* ************************************************************************** */
/* *******************************INCLUDES*********************************** */
/* ************************************************************************** */

# include "structures.h"

/* ************************************************************************** */
/* *******************************FUNCTIONS********************************** */
/* ************************************************************************** */

char	*is_map_valid(int fd);
int		check_error(char *map);
int		included_char(char *str, char c, int nbr);
int		is_rect(char *map);
int		is_closed(char *map);
void	init_game(int argc, char **argv, t_game *game);
void	init_textures(t_game *game);
void	open_screen(t_game *game);
void	print_sprite(t_game *game, t_data *sprite, int pos);
void	print_player(t_game *game);
t_data	*get_sprite(t_game *game, char letter);
void	improve_map(t_game *game);
int		close_game(t_game *game);
int		key_hook(int keycode, t_game *game);
void	move_up(t_game *game);
void	move_left(t_game *game);
void	move_down(t_game *game);
void	move_right(t_game *game);
void	open_trap(t_game *game);
void	end_move(t_game *game);
int		let_inc(char letter, char *str);
t_data	*get_sprite_content(t_game *game, char letter);
t_data	*get_sprite_wall(t_game *game, char letter);
void	exit_unvalid(char *str);

/* ************************************************************************** */
/* *********************************BONUS************************************ */
/* ************************************************************************** */

void	add_ghost(t_game *game);
void	print_ghost(t_game *game, t_character *ghost, int i);
void	print_ghosts(t_game *game);
void	move_ghosts(t_game *game);
int		get_rand(int max);
int		count_letter(char *map, char letter);
void	test_bonus_map(t_game *game);
int		print_step(t_game *game);
int		animate_drink(t_game *game);
void	print_square_steps(t_game *game);
void	reset_square_steps(t_game *game);
int		animate_drink(t_game *game);

#endif // FUNCTIONS_H