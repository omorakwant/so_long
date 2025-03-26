/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odahriz <odahriz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:37:18 by odahriz           #+#    #+#             */
/*   Updated: 2025/03/26 17:38:18 by odahriz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

int	update_enemy_game(t_data *data)
{
	static int	counter = 0;

	put_moves(data);
	counter++;
	if (counter % 8000 == 0)
	{
		data->enemy_frame = (data->enemy_frame + 1) % 2;
		render_image(data);
	}
	return (0);
}

void	check_map(t_data *data)
{
	if (name_check(data->filename))
		exit_error("Error!\nPlease Enter a valid map with \".ber\"\n");
	data->map = read_map(data);
	if (!data->map)
		free_error(("Error\nMap could not be read\n"), data);
	if (data->rows > 31 || data->columns > 60)
		free_error("Error\nmap too long", data);
	if (is_rectangle(data))
		free_error(("Error\nMap is not a rectangle!\n"), data);
	if (surrounded_by_walls(data))
		free_error(("Error\nMap not surrounded by walls!\n"), data);
	if (has_required_element(data))
		free_error(("Error\nMap has invalid element count!\n"), data);
	if (has_valid_path(data))
		free_error(("Error\nNo valid path!\n"), data);
}

void	put_moves(t_data *data)
{
	char	*moves_str;

	moves_str = ft_itoa(data->moves_count);
	mlx_set_font(data->mlx, data->window, "rk24");
	mlx_do_sync(data->mlx);
	mlx_string_put(data->mlx, data->window, 10, (data->rows + 1) * 31.7,
		0x000000, "Moves: ");
	mlx_string_put(data->mlx, data->window, 100, (data->rows + 1) * 31.7,
		0x000000, moves_str);
	free(moves_str);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (1);
	data.filename = av[1];
	data.width = 0;
	data.height = 0;
	data.columns = 0;
	data.moves_count = 0;
	data.player_dir = 1;
	data.player_frame = 0;
	data.enemy_frame = 0;
	check_map(&data);
	data.mlx = mlx_init();
	data.window = mlx_new_window(data.mlx, data.columns * 32, (data.rows + 1)
			* 32, "so_long");
	load_image(&data);
	render_image(&data);
	mlx_hook(data.window, 2, 1, movement, &data);
	mlx_hook(data.window, 17, 0, close_x_window, &data);
	mlx_loop_hook(data.mlx, (int (*)(void *))update_enemy_game, &data);
	mlx_loop(data.mlx);
	return (0);
}
