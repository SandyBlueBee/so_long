/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:58:23 by syukna            #+#    #+#             */
/*   Updated: 2025/03/06 15:03:24 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

/* ************************************************************************** */
/* *******************************FUNCTIONS********************************** */
/* ************************************************************************** */

char	*is_map_valid(int fd);
int		check_error(char *map);
int		included_char(char *str, char c, int nbr);
int		is_rect(char *map);
int		is_closed(char *map);

void	open_screen(void *mlx, void *mlx_win);

#endif // FUNCTIONS_H