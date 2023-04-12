/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:55:19 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/04/12 19:30:16 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;
	int		fd;
	int		i;

	i = 0;
	fd = get_file(argc, argv);
	map.content = read_map(fd);
	if (!map.content)
		return (1);
	if (check_errors(&map) == 1)
		return (free_map_2d(map.content), 1);
	while (map.content[i])
	{
		ft_printf("%s\n", map.content[i]);
		i++;
	}
	if (!create_window(&map, &map.game))
		return (free_map_2d(map.content), 1);
	free_map_2d(map.content);
	// system("leaks so_long");
}
