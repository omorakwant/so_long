/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odahriz <odahriz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:45:19 by odahriz           #+#    #+#             */
/*   Updated: 2025/03/26 17:45:22 by odahriz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map, int rows)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (i < rows && map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_player_image(t_data *data)
{
	if (data->player_up[0])
		mlx_destroy_image(data->mlx, data->player_up[0]);
	if (data->player_up[1])
		mlx_destroy_image(data->mlx, data->player_up[1]);
	if (data->player_down[0])
		mlx_destroy_image(data->mlx, data->player_down[0]);
	if (data->player_down[1])
		mlx_destroy_image(data->mlx, data->player_down[1]);
	if (data->player_left[0])
		mlx_destroy_image(data->mlx, data->player_left[0]);
	if (data->player_left[1])
		mlx_destroy_image(data->mlx, data->player_left[1]);
	if (data->player_right[0])
		mlx_destroy_image(data->mlx, data->player_right[0]);
	if (data->player_right[1])
		mlx_destroy_image(data->mlx, data->player_right[1]);
}

void	free_image(t_data *data)
{
	free_player_image(data);
	if (data->enemy_img[0])
		mlx_destroy_image(data->mlx, data->enemy_img[0]);
	if (data->enemy_img[1])
		mlx_destroy_image(data->mlx, data->enemy_img[1]);
	if (data->coin_img)
		mlx_destroy_image(data->mlx, data->coin_img);
	if (data->exit_img)
		mlx_destroy_image(data->mlx, data->exit_img);
	if (data->floor_img)
		mlx_destroy_image(data->mlx, data->floor_img);
	if (data->wall_img)
		mlx_destroy_image(data->mlx, data->wall_img);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
	free_image(data);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map(data->map, data->rows);
	exit(0);
	return (0);
}

int	close_x_window(void *ptr)
{
	t_data	*data;

	data = (t_data *)ptr;
	mlx_destroy_window(data->mlx, data->window);
	free_image(data);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map(data->map, data->rows);
	exit(0);
}
