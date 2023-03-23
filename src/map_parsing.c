/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:51:17 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/23 19:08:47 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	struct_map(t_error *error)
{
	check_map = ft_calloc(sizeof(t_map), 1);
	if (!map)
		exit (EXIT_FAILURE);
	check_map.error_walls = 0;
	check_map.error_rec = 0;
	check_map.error_one_each = 0;
}

int	check_errors(t_error *error, t_map *map)
{
	struct_map(error);
	if (check_walls == 1)
		check_map.error_walls = 1;
}