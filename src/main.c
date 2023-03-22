/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:55:19 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/22 15:20:52 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	int		fd;
	int		i;

	map = ft_calloc(sizeof(t_map), 1);
	if (!map)
		exit (EXIT_FAILURE);
	fd = get_file(argc, argv);
	map->content = read_map(fd);
	map->length_x = ft_strlen(map->content[0]);
	map->length_y = count_lines(map->content);
	i = 0;
	while (map->content[i])
	{
		ft_printf("%s\n", map->content[i]);
		i++;
	}
}