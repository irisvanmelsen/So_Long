/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:26:34 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/04/11 17:29:38 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	keyboard_button(mlx_key_data_t key, void *param)
{
	t_map	*map;
	int		i;

	i = 0;
	map = param;
	if (key.action != MLX_PRESS)
		return ;
	if (key.key == MLX_KEY_ESCAPE)
		mlx_close_window(map->mlx);
	keyboard_down(key, map);
	keyboard_up(key, map);
	keyboard_right(key, map);
	keyboard_left(key, map);
	check_tiles(map);
}

void	keyboard_down(mlx_key_data_t key, t_map *map)
{
	if (key.key == MLX_KEY_S
		&& map->content[map->game.char_y + 1][map->game.char_x] != '1')
	{
		map->game.steps++;
		ft_printf("crow steps: %d\n", map->game.steps);
		map->game.char_y++;
		map->game.char_img->instances[0].y += 32;
	}
}

void	keyboard_up(mlx_key_data_t key, t_map *map)
{
	if (key.key == MLX_KEY_W
		&& map->content[map->game.char_y - 1][map->game.char_x] != '1')
	{
		map->game.steps++;
		ft_printf("crow steps: %d\n", map->game.steps);
		map->game.char_y--;
		map->game.char_img->instances[0].y -= 32;
	}
}

void	keyboard_right(mlx_key_data_t key, t_map *map)
{
	if (key.key == MLX_KEY_D
		&& map->content[map->game.char_y][map->game.char_x + 1] != '1')
	{
		map->game.steps++;
		ft_printf("crow steps: %d\n", map->game.steps);
		map->game.char_x++;
		map->game.char_img->instances[0].x += 32;
	}
}

void	keyboard_left(mlx_key_data_t key, t_map *map)
{
	if (key.key == MLX_KEY_A
		&& map->content[map->game.char_y][map->game.char_x - 1] != '1')
	{
		map->game.steps++;
		ft_printf("crow steps: %d\n", map->game.steps);
		map->game.char_x--;
		map->game.char_img->instances[0].x -= 32;
	}
}
