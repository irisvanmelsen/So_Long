/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:18:29 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/29 18:14:21 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_characters(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->content[y])
	{
		x = 0;
		while (map->content[y][x])
		{
			if (map->content[y][x] == 'E')
				map->e_count++;
			if (map->content[y][x] == 'P')
				map->p_count++;
			if (map->content[y][x] == 'C')
				map->c_count++;
			x++;
		}
		y++;
	}
	if (map->e_count != 1 || map->p_count != 1 || map->c_count < 1)
		return (1);
	return (0);
}

int	map_strlen(char *s)
{
	int	length;

	length = 0;
	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}

char	**floodfill(char **content, int y, int x)
{
	if (content[y][x] != '1')
	{
		if (content[y][x] == 'C' || content[y][x] == '0'
			|| content[y][x] == 'P' || content[y][x] == 'E')
			content[y][x] = '1';
		else
			return (content);
		floodfill(content, y, x + 1);
		floodfill(content, y, x - 1);
		floodfill(content, y + 1, x);
		floodfill(content, y - 1, x);
	}
	return (content);
}

void	find_player(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->content[y])
	{
		x = 0;
		while (map->content[y][x])
		{
			if (map->content[y][x] == 'P')
			{
				map->player_y = y;
				map->player_x = x;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	check_map_after_ff(char **map_after_ff)
{
	int	x;
	int	y;

	y = 0;
	while (map_after_ff[y])
	{
		x = 0;
		while (map_after_ff[y][x])
		{
			if (map_after_ff[y][x] != '1' && map_after_ff[y][x] != '0')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}