/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odahriz <odahriz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:45:41 by odahriz           #+#    #+#             */
/*   Updated: 2025/03/26 17:45:43 by odahriz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	name_check(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (ft_strcmp(filename + len - 4, ".ber") != 0)
		return (1);
	if (len < 5 || filename[len - 5] == '/')
		exit_error("Error!\nPlease Enter at least 1 character with \".ber\"");
	return (0);
}

int	is_rectangle(t_data *data)
{
	int	i;
	int	line_len;

	i = 0;
	while (i < data->rows)
	{
		line_len = ft_strlen(data->map[i]);
		if (line_len > 0 && data->map[i][line_len - 1] == '\n')
			line_len--;
		if (line_len != data->columns)
			return (1);
		i++;
	}
	return (0);
}

int	surrounded_by_walls(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->columns)
	{
		if (data->map[0][i] != '1' || data->map[data->rows - 1][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < data->rows)
	{
		if (data->map[i][0] != '1' || data->map[i][data->columns - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	count_elements(t_data *data)
{
	int		i;
	int		j;
	char	cell;

	data->collectible = 0;
	data->player = 0;
	data->exit = 0;
	i = -1;
	while (++i < data->rows)
	{
		j = -1;
		while (++j < data->columns)
		{
			cell = data->map[i][j];
			if (cell == 'C')
				data->collectible++;
			else if (cell == 'P')
				data->player++;
			else if (cell == 'E')
				data->exit++;
			else if (cell != '0' && cell != '1' && cell != 'X')
				free_error("Error\nMap contains invalid characters!", data);
		}
	}
	return (0);
}

int	has_required_element(t_data *data)
{
	if (count_elements(data))
		return (1);
	if (data->exit != 1 || data->player != 1 || data->collectible < 1)
	{
		free_map(data->map, data->rows);
		exit_error("Error\nInvalid element count");
	}
	return (0);
}
