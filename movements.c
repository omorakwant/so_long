/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odahriz <odahriz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:41:45 by odahriz           #+#    #+#             */
/*   Updated: 2025/03/26 17:41:49 by odahriz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_normal_move(t_data *data, int new_x, int new_y, char curr)
{
	char	next;

	next = data->map[new_x][new_y];
	if (next == 'C')
		data->collectible--;
	if (curr == 'E')
		data->map[data->player_x][data->player_y] = 'E';
	else
		data->map[data->player_x][data->player_y] = '0';
	data->player_x = new_x;
	data->player_y = new_y;
	data->map[new_x][new_y] = 'P';
}

void	handle_move_outcome(t_data *data, int new_x, int new_y)
{
	char	next;
	char	curr;

	curr = data->map[data->player_x][data->player_y];
	next = data->map[new_x][new_y];
	if (next == 'X')
		ft_lose(data);
	else if (next == 'E')
	{
		if (data->collectible == 0)
			ft_victory(data);
		if (curr != 'E')
			data->map[data->player_x][data->player_y] = '0';
		data->player_x = new_x;
		data->player_y = new_y;
	}
	else
		handle_normal_move(data, new_x, new_y, curr);
}

void	process_move(t_data *data, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = data->player_x + dx;
	new_y = data->player_y + dy;
	if (data->map[new_x][new_y] != '1')
	{
		data->moves_count++;
		handle_move_outcome(data, new_x, new_y);
	}
}

void	movement_handle(int keycode, t_data *data)
{
	if (keycode == 65362 || keycode == 119)
	{
		data->player_dir = 0;
		process_move(data, -1, 0);
		data->player_frame = (data->player_frame + 1) % 2;
	}
	else if (keycode == 65364 || keycode == 115)
	{
		data->player_dir = 1;
		process_move(data, 1, 0);
		data->player_frame = (data->player_frame + 1) % 2;
	}
	else if (keycode == 65361 || keycode == 97)
	{
		data->player_dir = 2;
		process_move(data, 0, -1);
		data->player_frame = (data->player_frame + 1) % 2;
	}
	else if (keycode == 65363 || keycode == 100)
	{
		data->player_dir = 3;
		process_move(data, 0, 1);
		data->player_frame = (data->player_frame + 1) % 2;
	}
}

int	movement(int keycode, t_data *data)
{
	if (keycode == 65307)
		close_window(data);
	movement_handle(keycode, data);
	render_image(data);
	return (0);
}
