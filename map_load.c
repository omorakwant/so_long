/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odahriz <odahriz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:45:05 by odahriz           #+#    #+#             */
/*   Updated: 2025/03/26 17:45:08 by odahriz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	rows_calc(char *map_file)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

char	**read_map_lines(int fd, t_data *data, int total_rows)
{
	char	**map;
	char	*line;
	int		i;

	map = malloc(sizeof(char *) * (total_rows + 1));
	if (!map)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	if (!line)
	{
		free(map);
		close(fd);
		exit_error("Error\nMap is Empty");
	}
	data->columns = ft_strlen(line);
	if (data->columns > 0 && line[data->columns - 1] == '\n')
		data->columns--;
	while (line)
	{
		map[i++] = line;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	return (map);
}

char	**read_map(t_data *data)
{
	int		fd;
	char	**map;

	fd = open(data->filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	data->rows = rows_calc(data->filename);
	map = read_map_lines(fd, data, data->rows);
	close(fd);
	return (map);
}
