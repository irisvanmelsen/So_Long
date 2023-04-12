/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:26:34 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/04/12 19:28:42 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	keyboard_button(mlx_key_data_t key, void *param)
{
	t_map	*map;
	char	*steps_str;
	int		i;

	i = 0;
	map = param;
	steps_str = 0;
	if (key.action != MLX_PRESS)
		return ;
	if (key.key == MLX_KEY_ESCAPE)
		mlx_close_window(map->mlx);
	steps_str = ft_itoa(map->game.steps);
	if (map->game.dead != 1)
	{
		keyboard_down(key, map, steps_str);
		keyboard_up(key, map, steps_str);
		keyboard_right(key, map, steps_str);
		keyboard_left(key, map, steps_str);
	}
	free(steps_str);
	check_tiles(map);
}

void	keyboard_down(mlx_key_data_t key, t_map *map, char *steps_str)
{
	if (key.key == MLX_KEY_S
		&& map->content[map->game.char_y + 1][map->game.char_x] != '1')
	{
		map->game.steps++;
		mlx_delete_image(map->mlx, map->game.steps_img);
		map->game.steps_img = mlx_put_string(map->mlx, steps_str, 1, 2);
		map->game.char_y++;
		map->game.char_img->instances[0].y += 32;
	}
}

void	keyboard_up(mlx_key_data_t key, t_map *map, char *steps_str)
{
	if (key.key == MLX_KEY_W
		&& map->content[map->game.char_y - 1][map->game.char_x] != '1')
	{
		map->game.steps++;
		mlx_delete_image(map->mlx, map->game.steps_img);
		map->game.steps_img = mlx_put_string(map->mlx, steps_str, 1, 2);
		map->game.char_y--;
		map->game.char_img->instances[0].y -= 32;
	}
}

void	keyboard_right(mlx_key_data_t key, t_map *map, char *steps_str)
{
	if (key.key == MLX_KEY_D
		&& map->content[map->game.char_y][map->game.char_x + 1] != '1')
	{
		map->game.steps++;
		mlx_delete_image(map->mlx, map->game.steps_img);
		map->game.steps_img = mlx_put_string(map->mlx, steps_str, 1, 2);
		map->game.char_x++;
		map->game.char_img->instances[0].x += 32;
	}
}

void	keyboard_left(mlx_key_data_t key, t_map *map, char *steps_str)
{
	if (key.key == MLX_KEY_A
		&& map->content[map->game.char_y][map->game.char_x - 1] != '1')
	{
		map->game.steps++;
		mlx_delete_image(map->mlx, map->game.steps_img);
		map->game.steps_img = mlx_put_string(map->mlx, steps_str, 1, 2);
		map->game.char_x--;
		map->game.char_img->instances[0].x -= 32;
	}
}
