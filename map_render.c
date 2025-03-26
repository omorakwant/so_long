/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odahriz <odahriz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:44:25 by odahriz           #+#    #+#             */
/*   Updated: 2025/03/26 17:44:28 by odahriz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_player_image(t_data *data)
{
	data->player_up[0] = mlx_xpm_file_to_image(data->mlx,
			"sprites/player_up.xpm", &data->width, &data->height);
	data->player_up[1] = mlx_xpm_file_to_image(data->mlx,
			"sprites/player_up_mv.xpm", &data->width, &data->height);
	data->player_down[0] = mlx_xpm_file_to_image(data->mlx,
			"sprites/player_down.xpm", &data->width, &data->height);
	data->player_down[1] = mlx_xpm_file_to_image(data->mlx,
			"sprites/player_down_mv.xpm", &data->width, &data->height);
	data->player_left[0] = mlx_xpm_file_to_image(data->mlx,
			"sprites/player_left.xpm", &data->width, &data->height);
	data->player_left[1] = mlx_xpm_file_to_image(data->mlx,
			"sprites/player_left_mv.xpm", &data->width, &data->height);
	data->player_right[0] = mlx_xpm_file_to_image(data->mlx,
			"sprites/player_right.xpm", &data->width, &data->height);
	data->player_right[1] = mlx_xpm_file_to_image(data->mlx,
			"sprites/player_right_mv.xpm", &data->width, &data->height);
	if (!data->player_up[0] || !data->player_up[1] || !data->player_down[0]
		|| !data->player_down[1] || !data->player_left[0]
		|| !data->player_left[1] || !data->player_right[0]
		|| !data->player_right[1])
	{
		ft_putstr("Error loading player textures\n");
		close_window(data);
	}
}

void	load_enemy_image(t_data *data)
{
	data->enemy_img[0] = mlx_xpm_file_to_image(data->mlx, "sprites/enemy.xpm",
			&data->width, &data->height);
	data->enemy_img[1] = mlx_xpm_file_to_image(data->mlx,
			"sprites/enemy_mv.xpm", &data->width, &data->height);
	if (!data->enemy_img[0] || !data->enemy_img[1])
	{
		ft_putstr("Error loading textures\n");
		close_window(data);
	}
}

void	load_image(t_data *data)
{
	load_player_image(data);
	load_enemy_image(data);
	data->coin_img = mlx_xpm_file_to_image(data->mlx, "sprites/coin.xpm",
			&data->width, &data->height);
	data->wall_img = mlx_xpm_file_to_image(data->mlx, "sprites/wall.xpm",
			&data->width, &data->height);
	data->floor_img = mlx_xpm_file_to_image(data->mlx, "sprites/floor.xpm",
			&data->width, &data->height);
	data->exit_img = mlx_xpm_file_to_image(data->mlx, "sprites/exit.xpm",
			&data->width, &data->height);
	if (!data->wall_img || !data->coin_img || !data->exit_img
		|| !data->floor_img)
	{
		ft_putstr("Error loading textures\n");
		close_window(data);
	}
}

void	render_image_norm(t_data *data, int y)
{
	int	x;

	x = 0;
	while (x < data->columns)
	{
		if (data->map[y][x] == '1')
			mlx_put_image_to_window(data->mlx, data->window, data->wall_img, x
				* 32, y * 32);
		else if (data->map[y][x] == '0')
			mlx_put_image_to_window(data->mlx, data->window, data->floor_img, x
				* 32, y * 32);
		else if (data->map[y][x] == 'C')
			mlx_put_image_to_window(data->mlx, data->window, data->coin_img, x
				* 32, y * 32);
		else if (data->map[y][x] == 'E')
			mlx_put_image_to_window(data->mlx, data->window, data->exit_img, x
				* 32, y * 32);
		else if (data->map[y][x] == 'X')
			mlx_put_image_to_window(data->mlx, data->window,
				data->enemy_img[data->enemy_frame], x * 32, y * 32);
		mlx_put_image_to_window(data->mlx, data->window, data->floor_img, x
			* 32, (data->rows) * 32);
		x++;
	}
}

void	render_image(t_data *data)
{
	int	y;

	y = 0;
	while (y < data->rows)
	{
		render_image_norm(data, y);
		y++;
	}
	if (data->player_dir == 0)
		mlx_put_image_to_window(data->mlx, data->window,
			data->player_up[data->player_frame], data->player_y * 32,
			data->player_x * 32);
	else if (data->player_dir == 1)
		mlx_put_image_to_window(data->mlx, data->window,
			data->player_down[data->player_frame], data->player_y * 32,
			data->player_x * 32);
	else if (data->player_dir == 2)
		mlx_put_image_to_window(data->mlx, data->window,
			data->player_left[data->player_frame], data->player_y * 32,
			data->player_x * 32);
	else if (data->player_dir == 3)
		mlx_put_image_to_window(data->mlx, data->window,
			data->player_right[data->player_frame], data->player_y * 32,
			data->player_x * 32);
}
