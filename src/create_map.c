/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:35:22 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/22 17:59:30 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**read_map(int fd)
{
	char	*map;
	char	*tmp;
	char	*line;
	char	**result;

	line = get_next_line(fd);
	if (!line)
		exit(1);
	map = ft_strdup(line);
	free(line);
	line = get_next_line(fd);
	if (!line)
		exit(1);
	while (line)
	{
		tmp = ft_strjoin(map, line);
		if (!tmp)
			exit(1);
		free(line);
		free(map);
		map = tmp;
		line = get_next_line(fd);
		if (!tmp)
			exit(1);
	}
	result = ft_split(map, '\n');
	if (!result)
		exit(1);
	free(map);
	if (!result)
		return (NULL);
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

