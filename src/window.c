/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:08:44 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/04/13 12:48:34 by ivan-mel         ###   ########.fr       */
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

bool	images_init(t_game *game)
{
	game->char_tx = mlx_load_png("assets/Crow.png");
	game->wall_tx = mlx_load_png("assets/Tree.png");
	game->col_tx = mlx_load_png("assets/Drink.png");
	game->end_tx = mlx_load_png("assets/Chest.png");
	game->backgr_tx = mlx_load_png("assets/Background.png");
	game->fire_tx = mlx_load_png("assets/Fire.png");
	game->gameover_tx = mlx_load_png("assets/CrowFire.png");
	if (!game->char_tx || !game->wall_tx || !game->col_tx
		|| !game->end_tx || !game->backgr_tx || !game->fire_tx
		|| !game->gameover_tx)
		return (false);
	return (true);
}

bool	create_window(t_map *map, t_game *game)
{
	map->game.steps = 0;
	map->mlx = mlx_init(map->length_x * 32, map->length_y * 32, "42", false);
	if (!map->mlx)
		ft_printf("Error map->mlx");
	if (!images_init(game))
	{
		delete_textures(game);
		mlx_terminate(map->mlx);
		return (false);
	}
	push_images_window(map, game);
	place_images(map, game);
	game->char_y = map->player_y;
	game->char_x = map->player_x;
	map->game.dead = 0;
	mlx_key_hook(map->mlx, keyboard_button, map);
	mlx_loop(map->mlx);
	mlx_terminate(map->mlx);
	delete_textures(game);
	return (true);
}

void	push_images_window(t_map *map, t_game *game)
{
	game->char_img = mlx_texture_to_image(map->mlx, game->char_tx);
	game->wall_img = mlx_texture_to_image(map->mlx, game->wall_tx);
	game->col_img = mlx_texture_to_image(map->mlx, game->col_tx);
	game->end_img = mlx_texture_to_image(map->mlx, game->end_tx);
	game->backgr_img = mlx_texture_to_image(map->mlx, game->backgr_tx);
	game->fire_img = mlx_texture_to_image(map->mlx, game->fire_tx);
	game->gameover_img = mlx_texture_to_image(map->mlx, game->gameover_tx);
}

void	place_images(t_map *map, t_game *game)
{
	place_background(map, game);
	place_walls(map, game);
	place_col_exit(map, game);
	place_player(map, game);
	place_enemies(map, game);
}

void	delete_textures(t_game *game)
{
	if (game->char_tx)
		mlx_delete_texture(game->char_tx);
	if (game->wall_tx)
		mlx_delete_texture(game->wall_tx);
	if (game->col_tx)
		mlx_delete_texture(game->col_tx);
	if (game->end_tx)
		mlx_delete_texture(game->end_tx);
	if (game->fire_tx)
		mlx_delete_texture(game->fire_tx);
	if (game->gameover_tx)
		mlx_delete_texture(game->gameover_tx);
	if (game->backgr_tx)
		mlx_delete_texture(game->backgr_tx);
}
