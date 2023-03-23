/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:35:22 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/23 15:59:49 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**read_map(int fd)
{
	char	*map;
	char	*tmp;
	char	*line;
	char	**result;
	int		i;

	i = 0;
	line = get_next_line(fd);
	tmp = ft_strdup(line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line != NULL)
			map = ft_strjoin(tmp, line);
		free(tmp);
		tmp = ft_strdup(map);
	}
	result = ft_split(map, '\n');
	exit_one(*result);
	free(tmp);
	free(map);
	return (result);
}

int	get_file(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		ft_printf("Missing Arguments\n");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_printf("No File Found\n");
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
		ft_printf("Incorrect File\n");
	return (fd);
}

