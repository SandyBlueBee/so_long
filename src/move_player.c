/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:04:21 by syukna            #+#    #+#             */
/*   Updated: 2025/03/19 14:17:02 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// void	move_player(t_game *game, int	pos)
// {
	
// }

void	move_up(t_game *game)
{
	int	i;
	int line;
	t_data *sprite;

	i = game->player->pos;
	line = game->width + 1;
	if (game->map[i - line] == '0' || game->map[i - line] == 'C' || game->map[i - line] == 'P' || game->map[i - line] == 'E')
	{
		sprite = get_sprite_content(game, game->map[i]);
		print_sprite(game, sprite, i);
		print_sprite(game, game->textures->floor, i-line);
		game->player->pos = i - line;
		if (game->map[i - line] == 'C')
		{
			game->map[i - line] = '0';
			ft_printf("drinkin\n");
			print_sprite(game, game->textures->player_b, i - line);
			add_ghost(game);
		}
		else if (game->map[i - line] == 'E')
			print_sprite(game, game->textures->player_trap, i - line);
		else
		{
			print_player(game);
			ft_printf("not drinkin\n");
		}
		game->moves++;
		ft_printf("%d\n", game->moves);
		move_ghosts(game);
	}
	else if (game->map[i - line] == 'O')
		close_game(game);
	end_move(game);
}

void	move_left(t_game *game)
{
	int	i;
	t_data *sprite;

	i = game->player->pos;
	if (game->map[i - 1] == '0' || game->map[i - 1] == 'C' || game->map[i - 1] == 'P'  || game->map[i  - 1] == 'E')
	{
		sprite = get_sprite_content(game, game->map[i]);
		print_sprite(game, sprite, i);
		print_sprite(game, game->textures->floor, i - 1);
		game->player->pos = i - 1;
		if (game->map[i - 1] == 'C')
		{
			game->map[i - 1] = '0';
			ft_printf("drinkin\n");
			print_sprite(game, game->textures->player_b, i - 1);
			add_ghost(game);
		}
		else if (game->map[i - 1] == 'E')
			print_sprite(game, game->textures->player_trap, i - 1);
		else
		{
			print_player(game);
			ft_printf("not drinkin\n");
		}
		game->moves++;
		ft_printf("%d\n", game->moves);
		move_ghosts(game);
	}
	else if (game->map[i - 1] == 'O')
		close_game(game);
	end_move(game);
}

void	move_down(t_game *game)
{
	int	i;
	int line;
	t_data *sprite;

	i = game->player->pos;
	line = game->width + 1;
	if (game->map[i + line] == '0' || game->map[i + line] == 'C' || game->map[i + line] == 'P'  || game->map[i  + line] == 'E')
	{
		sprite = get_sprite_content(game, game->map[i]);
		print_sprite(game, sprite, i);
		print_sprite(game, game->textures->floor, i + line);
		game->player->pos = i + line;
		if (game->map[i + line] == 'C')
		{
			game->map[i + line] = '0';
			ft_printf("drinkin\n");
			print_sprite(game, game->textures->player_b, i + line);
			add_ghost(game);
		}
		else if (game->map[i + line] == 'E')
			print_sprite(game, game->textures->player_trap, i + line);
		else
		{
			print_player(game);
			ft_printf("not drinkin\n");
		}
		game->moves++;
		ft_printf("%d\n", game->moves);
		move_ghosts(game);
	}
	else if (game->map[i + line] == 'O')
		close_game(game);
	end_move(game);
}

void	move_right(t_game *game)
{
	int	i;
	t_data *sprite;

	i = game->player->pos;
	if (game->map[i + 1] == '0' || game->map[i  + 1] == 'C' || game->map[i  + 1] == 'P' || game->map[i  + 1] == 'E')
	{
		sprite = get_sprite_content(game, game->map[i]);
		print_sprite(game, sprite, i);
		print_sprite(game, game->textures->floor, i + 1);
		game->player->pos = i + 1;
		if (game->map[i + 1] == 'C')
		{
			game->map[i + 1] = '0';
			ft_printf("drinkin\n");
			print_sprite(game, game->textures->player_b, i + 1);
			add_ghost(game);
		}
		else if (game->map[i + 1] == 'E')
			print_sprite(game, game->textures->player_trap, i + 1);
		else
		{
			print_player(game);
			ft_printf("not drinkin\n");
		}
		game->moves++;
		ft_printf("%d\n", game->moves);
		move_ghosts(game);
	}
	else if (game->map[i + 1] == 'O')
		close_game(game);
	end_move(game);
}