/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 19:32:40 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/04/13 12:32:06 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	place_background(t_map *map, t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (map->content [y])
	{
		x = 0;
		while (map->content [y][x])
		{
			mlx_image_to_window(map->mlx, game->backgr_img, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void	place_walls(t_map *map, t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (map->content [y])
	{
		x = 0;
		while (map->content [y][x])
		{
			if (map->content [y][x] == '1')
				mlx_image_to_window(map->mlx, game->wall_img, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void	place_col_exit(t_map *map, t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (map->content [y])
	{
		x = 0;
		while (map->content [y][x])
		{
			if (map->content [y][x] == 'C')
				mlx_image_to_window(map->mlx, game->col_img, x * 32, y * 32);
			if (map->content [y][x] == 'E')
				mlx_image_to_window(map->mlx, game->end_img, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void	place_player(t_map *map, t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (map->content [y])
	{
		x = 0;
		while (map->content [y][x])
		{
			if (map->content [y][x] == 'P')
			{
				mlx_image_to_window(map->mlx, game->char_img, x * 32, y * 32);
				return ;
			}
			x++;
		}
		y++;
	}
}

void	place_enemies(t_map *map, t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (map->content [y])
	{
		x = 0;
		while (map->content [y][x])
		{
			if (map->content [y][x] == 'F')
				mlx_image_to_window(map->mlx, game->fire_img, x * 32, y * 32);
			x++;
		}
		y++;
	}
}
