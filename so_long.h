/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:56:18 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/29 18:23:26 by ivan-mel         ###   ########.fr       */
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
	int		player_x;
	int		player_y;
}	t_map;

// --------------------------MAP---------------------------------------
//
// -----------------------create_map-----------------------------------
char	**read_map(int fd);
int		get_file(int argc, char **argv);
int		count_lines(char **content);
// ------------------------PARSING-------------------------------------
//
// -----------------------map_parsing----------------------------------
void	check_map_init(t_map *map);
int		check_errors(t_map *map);
int		check_sides_wall(t_map *map);
int		check_first_last_walls(t_map *map);
int		check_rectangle(t_map *map);
// -----------------------map_parsing2---------------------------------
int		check_characters(t_map *map);
int		map_strlen(char *s);
char	**floodfill(char **content, int y, int x);
void	find_player(t_map *map);
int		check_map_after_ff(char **map_after_ff);
// -----------------------map_parsing3---------------------------------
// ---------------------------FREE-------------------------------------
//
// ---------------------------free-------------------------------------
void	exit_one(char *ptr);

#endif