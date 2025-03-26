/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odahriz <odahriz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:42:17 by odahriz           #+#    #+#             */
/*   Updated: 2025/03/26 17:43:20 by odahriz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->columns)
		{
			if (data->map[i][j] == 'P')
			{
				data->player_x = i;
				data->player_y = j;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	reachable(char **map, int rows, int columns)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < columns)
		{
			if (map[i][j] == 'E' || map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	flood_fill(char **map, int x, int y)
{
	if (x < 0 || y < 0 || !map[x] || map[x][y] == '1' || map[x][y] == 'V'
		|| map[x][y] == 'X')
		return ;
	map[x][y] = 'V';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

char	**map_copy(char **map, int rows)
{
	char	**new_map;
	int		i;

	new_map = (char **)malloc(sizeof(char *) * (rows + 1));
	if (!new_map)
		exit_error("Error\nMemory allocation failed for map copy!");
	i = 0;
	while (i < rows)
	{
		new_map[i] = ft_strdup(map[i]);
		if (!new_map[i])
		{
			while (i-- > 0)
				free(new_map[i]);
			free(new_map);
			exit_error("Error\nMemory allocation failed for map copy!");
		}
		i++;
	}
	new_map[rows] = NULL;
	return (new_map);
}

int	has_valid_path(t_data *data)
{
	char	**copy;

	find_player(data);
	copy = map_copy(data->map, data->rows);
	if (!copy)
		return (1);
	flood_fill(copy, data->player_x, data->player_y);
	if (reachable(copy, data->rows, data->columns))
	{
		free_map(copy, data->rows);
		free_error("Error\nNo valid path!\n", data);
	}
	free_map(copy, data->rows);
	return (0);
}
