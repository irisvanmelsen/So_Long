/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:22:59 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/31 17:24:50 by ivan-mel         ###   ########.fr       */
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
		i++;
	}
	return (map->dup_content);
}
