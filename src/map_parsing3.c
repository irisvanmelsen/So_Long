/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:22:59 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/04/11 19:03:15 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**create_dup_map(t_map *map)
{
	int	i;

	i = 0;
	map->dup_content = (char **)ft_calloc((map->length_y + 1), sizeof(char *));
	if (!map->dup_content)
		return (0);
	while (i < map->length_y)
	{
		map->dup_content[i] = ft_strdup(map->content[i]);
		if (!map->dup_content[i])
		{
			free_map_2d(map->dup_content);
			return (NULL);
		}
		i++;
	}
	return (map->dup_content);
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
