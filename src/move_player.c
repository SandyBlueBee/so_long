/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:04:21 by syukna            #+#    #+#             */
/*   Updated: 2025/03/21 13:56:56 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_player(t_game *game, int current, int next)
{
	t_data	*sprite;

	move_ghosts(game);
	game->drinking = 0;
	sprite = get_sprite_content(game, game->map[current]);
	print_sprite(game, sprite, current);
	print_sprite(game, game->textures->floor, next);
	game->player->pos = next;
	if (game->map[next] == 'C')
	{
		game->map[next] = '0';
		game->drinking = 1;
		print_sprite(game, game->textures->player_b, next);
		add_ghost(game);
	}
	else if (game->map[next] == 'E')
		print_sprite(game, game->textures->player_trap, next);
	else
		print_player(game);
	game->moves++;
	print_step(game);
	print_ghosts(game);
}

void	move_up(t_game *game)
{
	int	i;
	int	line;

	i = game->player->pos;
	line = game->width + 1;
	if (let_inc(game->map[i - line], "0CPE"))
		move_player(game, i, i - line);
	else if (game->map[i - line] == 'O')
		close_game(game);
	end_move(game);
}

void	move_left(t_game *game)
{
	int	i;

	i = game->player->pos;
	if (let_inc(game->map[i - 1], "0CPE"))
		move_player(game, i, i - 1);
	else if (game->map[i - 1] == 'O')
		close_game(game);
	end_move(game);
}

void	move_down(t_game *game)
{
	int	i;
	int	line;

	i = game->player->pos;
	line = game->width + 1;
	if (let_inc(game->map[i + line], "0CPE"))
		move_player(game, i, i + line);
	else if (game->map[i + line] == 'O')
		close_game(game);
	end_move(game);
}

void	move_right(t_game *game)
{
	int	i;

	i = game->player->pos;
	if (let_inc(game->map[i + 1], "0CPE"))
		move_player(game, i, i + 1);
	else if (game->map[i + 1] == 'O')
		close_game(game);
	end_move(game);
}
