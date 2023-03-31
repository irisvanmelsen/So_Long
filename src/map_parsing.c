/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:51:17 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/31 17:29:24 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_map_init(t_map *map)
{
	map->e_count = 0;
	map->p_count = 0;
	map->c_count = 0;
	map->player_x = 0;
	map->player_y = 0;
}

int	check_errors(t_map *map)
{
	char	**map_after_ff;
	char	**dup_map;

	dup_map = create_dup_map(map);
	check_map_init(map);
	if (check_rectangle(map) == 1)
		return (ft_printf("Wall is not Rectangular\n"));
	if (check_sides_wall(map) == 1)
		return (ft_printf("Invalid Wall Error\n"));
	if (check_first_last_walls(map) == 1)
		return (ft_printf("Invalid Wall Error\n"));
	if (check_characters(map) == 1)
		return (ft_printf("Invalid amount of characters\n"));
	find_player(map);
	map_after_ff = floodfill(dup_map, map->player_y, map->player_x);
	if (check_map_after_ff(map_after_ff) == 1)
	{
		free(map_after_ff);
		return (ft_printf("Invalid Path\n"));
	}
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
