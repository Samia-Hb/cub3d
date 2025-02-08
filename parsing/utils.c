/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 22:10:15 by shebaz            #+#    #+#             */
/*   Updated: 2025/02/08 23:14:41 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_error(void)
{
	write(2, "Error : Invalid Map\n", 20);
	exit(1);
}

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] && line[i] == '\n')
		return (1);
	return (0);
}
int	check_data(t_data *data)
{
	if (!data)
		return (0);
	if (!data->ceiling_color || !data->east_texture || !data->floor_color
		|| !data->map_height || !data->north_texture || !data->south_texture
		|| !data->west_texture)
		return (0);
	return (1);
}

int	another_content(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' || str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}
