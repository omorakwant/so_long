/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odahriz <odahriz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:46:54 by odahriz           #+#    #+#             */
/*   Updated: 2025/03/26 17:48:22 by odahriz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_victory(t_data *data)
{
	char	*moves_str;

	moves_str = ft_itoa(data->moves_count);
	ft_putstr("Moves: ");
	ft_putstr(moves_str);
	ft_putstr("\nYOU WIN");
	free(moves_str);
	close_window(data);
}

void	ft_lose(t_data *data)
{
	char	*moves_str;

	moves_str = ft_itoa(data->moves_count);
	ft_putstr("Moves: ");
	ft_putstr(moves_str);
	ft_putstr("\nYOU LOSE");
	free(moves_str);
	close_window(data);
}
