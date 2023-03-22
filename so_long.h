/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:56:18 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/22 15:10:01 by ivan-mel         ###   ########.fr       */
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

// # include "../Libft/libft.h"
// # include "../Libft/ft_printf.h"
// # include "../Libft/get_next_line.h"

typedef struct s_error
{
	int	error_rec;
	int	error_walls;
	int	error_one_each;
}	t_error;

typedef struct s_map
{
	char **content;
	int	length_x;
	int	length_y;
}	t_map;

// --------------------------MAP---------------------------------------
//
// -----------------------create_map-----------------------------------
char	**read_map(int fd);
int		get_file(int argc, char **argv);
// ---------------------create_map_utils-------------------------------
int		count_lines(char **content);
// ------------------------PARSING-------------------------------------
//
// -----------------------map_parsing----------------------------------


#endif