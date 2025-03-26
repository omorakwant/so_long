/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odahriz <odahriz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:46:27 by odahriz           #+#    #+#             */
/*   Updated: 2025/03/26 17:46:30 by odahriz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_read(char *buffer, int fd)
{
	char	*tmp;
	int		i;

	tmp = (char *)malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (free(buffer), NULL);
	i = 1;
	while (i && !ft_contain(buffer, '\n'))
	{
		i = read(fd, tmp, BUFFER_SIZE);
		if (i < 0)
			return (free(buffer), free(tmp), NULL);
		tmp[i] = '\0';
		buffer = ft_strjoin(buffer, tmp);
		if (!buffer)
			return (free(tmp), NULL);
	}
	free(tmp);
	return (buffer);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = buffer[j];
		j++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_rest_buff(char *buffer)
{
	char	*rest_buffer;
	int		i;
	int		j;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	rest_buffer = malloc(ft_strlen(buffer) - i + 1);
	if (!rest_buffer)
		return (free(buffer), NULL);
	j = 0;
	while (buffer[i])
		rest_buffer[j++] = buffer[i++];
	rest_buffer[j] = '\0';
	free(buffer);
	return (rest_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read(buffer, fd);
	if (!buffer)
		return (buffer);
	if (!buffer[0])
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = ft_line(buffer);
	buffer = ft_rest_buff(buffer);
	return (line);
}
