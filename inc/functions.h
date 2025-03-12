/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:58:23 by syukna            #+#    #+#             */
/*   Updated: 2025/03/12 19:40:04 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

/* ************************************************************************** */
/* *******************************INCLUDES*********************************** */
/* ************************************************************************** */

#include "structures.h"

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

#endif // FUNCTIONS_H