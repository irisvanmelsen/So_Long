/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:56:18 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/27 17:57:14 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>

# include <libft.h>
# include <get_next_line.h>
# include <ft_printf.h>

// typedef struct s_error
// {
// 	int		error_rec;
// 	int		error_walls;
// 	int		error_one_each;
// }	t_error;

typedef struct s_map
{
	char	**content;
	int		length_x;
	int		length_y;
	int		e_count;
	int		p_count;
	int		c_count;
}	t_map;

// --------------------------MAP---------------------------------------
//
// -----------------------create_map-----------------------------------
char	**read_map(int fd);
int		get_file(int argc, char **argv);
// ---------------------create_map_utils-------------------------------
int		count_lines(char **content);
int		map_strlen(char *s);
// ------------------------PARSING-------------------------------------
//
// -----------------------map_parsing----------------------------------
int		check_errors(t_map *map);
int		check_sides_wall(t_map *map);
int		check_first_last_walls(t_map *map);
int		check_rectangle(t_map *map);
int		check_characters(t_map *map);
// ---------------------------FREE-------------------------------------
//
// ---------------------------free-------------------------------------
void	exit_one(char *ptr);

#endif