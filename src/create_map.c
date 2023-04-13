/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:35:22 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/04/13 14:36:07 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static size_t	ft_strlen_protect(char *s)
{
	int	length;

	length = 0;
	if (s == NULL)
		return (0);
	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}

static char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*str3;
	int		lengths1;
	int		lengths2;

	lengths1 = ft_strlen_protect(s1);
	lengths2 = ft_strlen_protect(s2);
	str3 = ft_calloc(sizeof(char), (lengths1 + lengths2 + 1));
	if (!str3)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	ft_strlcpy_protect(str3, s1, lengths1 + 1);
	ft_strlcat(str3 + lengths1, s2, lengths2 + 1);
	free(s1);
	free(s2);
	return (str3);
}

char	**read_map(int fd)
{
	char	*map;
	char	*line;
	char	**result;

	line = NULL;
	map = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map = ft_strjoin_free(map, line);
		if (!map)
			return (NULL);
	}
	if (map == NULL)
		return (NULL);
	result = ft_split(map, '\n');
	free(map);
	if (!result)
		return (NULL);
	return (result);
}

int	get_file(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		ft_printf("Missing Arguments\n");
		exit (EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("No File Found\n");
		exit (EXIT_FAILURE);
	}
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
	{
		ft_printf("Incorrect File\n");
		exit (EXIT_FAILURE);
	}
	return (fd);
}

int	count_lines(char **content)
{
	int	i;

	i = 0;
	while (content[i] != '\0')
		i++;
	return (i);
}
