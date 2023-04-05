/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:08:44 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/04/05 19:19:10 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// MLX_LOOP: Initializes the rendering of MLX, this function won't return until
// mlx_close_window is called, meaning it will loop until the user requests that
// the window should close.

// MLX_TERMINATE: Terminates MLX and cleans up any of its used resources.
// Using any functions that require mlx afterwards will
// be considered undefined behaviour, beware of segfaults.

// MLX_INIT: Initializes a new MLX42 Instance.

void	create_window(t_map *map, t_game *game)
{
	map->mlx = mlx_init(map->length_y * 32, map->length_x * 32, "test", true);
	if (!map->mlx)
		ft_printf("Error map->mlx");
	images_init(map, game);
	place_images(map, game);
	mlx_loop(map->mlx);
	mlx_terminate(map->mlx);
	delete_textures(game);
}

void	images_init(t_map *map, t_game *game)
{
	game->char_tx = mlx_load_png("Crow.png");
	game->char_img = mlx_texture_to_image(map->mlx, game->char_tx);
	game->wall_tx = mlx_load_png("Tree.png");
	game->wall_img = mlx_texture_to_image(map->mlx, game->wall_tx);
	game->col_tx = mlx_load_png("Drink.png");
	game->col_img = mlx_texture_to_image(map->mlx, game->col_tx);
	game->end_tx = mlx_load_png("Chest.png");
	game->end_img = mlx_texture_to_image(map->mlx, game->end_tx);
	game->backgr_tx = mlx_load_png("Background.png");
	game->backgr_img = mlx_texture_to_image(map->mlx, game->backgr_tx);
}

void	place_images(t_map *map, t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (map->content [y])
	{
		x = 0;
		while (map->content [y][x])
		{
			mlx_image_to_window(map->mlx, game->backgr_img, y * 32, x * 32);
			if (map->content [y][x] == 'P')
				mlx_image_to_window(map->mlx, game->char_img, y * 32, x * 32);
			if (map->content [y][x] == '1')
				mlx_image_to_window(map->mlx, game->wall_img, y * 32, x * 32);
			if (map->content [y][x] == 'C')
				mlx_image_to_window(map->mlx, game->col_img, y * 32, x * 32);
			if (map->content [y][x] == 'E')
				mlx_image_to_window(map->mlx, game->end_img, y * 32, x * 32);
			x++;
		}
		y++;
	}
}

void	delete_textures(t_game *game)
{
	mlx_delete_texture(game->char_tx);
	mlx_delete_texture(game->wall_tx);
	mlx_delete_texture(game->col_tx);
	mlx_delete_texture(game->end_tx);
}