/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:56:18 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/04/07 20:01:57 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>

# include <MLX42.h>
# include <libft.h>
# include <get_next_line.h>
# include <ft_printf.h>

typedef struct s_game
{
	mlx_texture_t	*char_tx;
	mlx_image_t		*char_img;
	mlx_texture_t	*wall_tx;
	mlx_image_t		*wall_img;
	mlx_texture_t	*col_tx;
	mlx_image_t		*col_img;
	mlx_texture_t	*end_tx;
	mlx_image_t		*end_img;
	mlx_texture_t	*backgr_tx;
	mlx_image_t		*backgr_img;
	int				char_y;
	int				char_x;
}	t_game;

// typedef struct s_sprites
// {
// 	mlx_texture_t	*char_tx;
// 	mlx_image_t		*char_img;
// 	mlx_texture_t	*wall_tx;
// 	mlx_image_t		*wall_img;
// 	mlx_texture_t	*col_tx;
// 	mlx_image_t		*col_img;
// 	mlx_texture_t	*end_tx;
// 	mlx_image_t		*end_img;
// 	mlx_texture_t	*backgr_tx;
// 	mlx_image_t		*backgr_img;
// 	int				char_y;
// 	int				char_x;
// }	t_sprites;

// typedef struct x_game
// {
// 	t_sprites	*sprites;

// }	n_game;

typedef struct s_map
{
	char	**content;
	char	**dup_content;
	int		length_x;
	int		length_y;
	int		e_count;
	int		p_count;
	int		c_count;
	int		player_x;
	int		player_y;
	mlx_t	*mlx;
	t_game	*game;
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
char	**create_dup_map(t_map *map);
// --------------------------WINDOW------------------------------------
//
// ---------------------------window-----------------------------------
void	place_images(t_map *map, t_game *game);
void	images_init(t_map *map, t_game *game);
void	delete_textures(t_game *game);
void	create_window(t_map *map, t_game *game);
void	keyboard_button(mlx_key_data_t key, void *param);
// ---------------------------FREE-------------------------------------
//
// ---------------------------free-------------------------------------
void	exit_one(char *ptr);
// --------------------------MOVING------------------------------------
//
// -------------------------moving-------------------------------------
void	check_tiles(t_map *map);
// -------------------------images-------------------------------------
void	place_background(t_map *map, t_game *game);
void	place_walls(t_map *map, t_game *game);
void	place_col_exit(t_map *map, t_game *game);
void	place_player(t_map *map, t_game *game);

#endif