/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:29:47 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/04/13 12:32:20 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	remove_col(t_map *map)
{
	const int		x = map->game.char_x * 32;
	const int		y = map->game.char_y * 32;
	int				i;
	mlx_instance_t	*check;

	i = 0;
	while (1)
	{
		check = &map->game.col_img->instances[i];
		if (check->x == x && check->y == y)
		{
			check->enabled = false;
			return ;
		}
		i++;
	}
}

static void	game_over(t_map *map)
{
	const int		x = map->game.char_x * 32;
	const int		y = map->game.char_y * 32;
	mlx_instance_t	*player;

	player = &map->game.char_img->instances[0];
	player->enabled = false;
	mlx_image_to_window(map->mlx, map->game.gameover_img, x, y);
	map->game.steps = 0;
	map->game.dead = 1;
}

void	check_tiles(t_map *map)
{
	if (map->content[map->game.char_y][map->game.char_x] == 'C')
	{
		map->c_count--;
		map->content[map->game.char_y][map->game.char_x] = '0';
		remove_col(map);
	}
	if (map->content[map->game.char_y][map->game.char_x] == 'E')
	{
		if (map->c_count != 0)
			return ;
		else
		{
			mlx_close_window(map->mlx);
		}
	}
	if (map->content[map->game.char_y][map->game.char_x] == 'F')
		game_over(map);
}
