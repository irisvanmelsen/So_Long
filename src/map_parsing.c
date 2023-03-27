/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:51:17 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/27 17:57:32 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_errors(t_map *map)
{
	map->e_count = 0;
	map->p_count = 0;
	map->c_count = 0;
	if (check_rectangle(map) == 1)
		return (ft_printf("Wall is not Rectangular\n"));
	if (check_sides_wall(map) == 1)
		return (ft_printf("Invalid Wall Error\n"));
	if (check_first_last_walls(map) == 1)
		return (ft_printf("Invalid Wall Error\n"));
	if (check_characters(map) == 1)
		return (ft_printf("Invalid amount of characters\n"));
	return (0);
}

int	check_sides_wall(t_map *map)
{
	int	y;

	y = 0;
	while (map->content[y])
	{
		if (map->content[y][0] != '1' ||
			map->content[y][map->length_x - 1] != '1')
			return (1);
		y++;
	}
	return (0);
}

int	check_first_last_walls(t_map *map)
{
	int	x;

	x = 0;
	while (map->content[0][x])
	{
		if (map->content[0][x] != '1')
			return (1);
		x++;
	}
	x = 0;
	while (map->content[map->length_y - 1][x])
	{
		if (map->content[map->length_y - 1][x] != '1')
			return (1);
		x++;
	}
	return (0);
}

int	check_rectangle(t_map *map)
{
	int	i;

	i = 0;
	while (map->content[i])
	{
		if (map_strlen(map->content[i]) != map->length_x)
			return (1);
		i++;
	}
	return (0);
}

int	check_characters(t_map *map)
{
	int x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	while (map->content[y][x])
	{
		if (map->content[i] == 'E')
			map->e_count++;
		if (map->content[i] == 'P')
			map->p_count++;
		if (map->content[i]) == 'C')
			map->c_count[i];

		x++;
	}
	if (map->e_count != 1 || map->p_count != 1 || map->c_count < 1 )
		return (1);
}