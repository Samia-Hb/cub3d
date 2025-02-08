/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 22:07:20 by shebaz            #+#    #+#             */
/*   Updated: 2025/02/08 23:14:23 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	validate_colors(t_data *data)
{
	if (!data->ceiling_color || !data->floor_color)
	{
		clean_data(data);
		print_error();
	}
	if (data->ceiling_color->b > 255 || data->ceiling_color->b < 0
		|| data->ceiling_color->r > 255 || data->ceiling_color->r < 0
		|| data->ceiling_color->g > 255 || data->ceiling_color->g < 0)
	{
		clean_data(data);
		print_error();
	}
	if (data->floor_color->b > 255 || data->floor_color->b < 0
		|| data->floor_color->r > 255 || data->floor_color->r < 0
		|| data->floor_color->g > 255 || data->floor_color->g < 0)
	{
		clean_data(data);
		print_error();
	}
}

void	validate_paths(t_data *data)
{
	if (!data->north_texture || !data->south_texture || !data->west_texture
		|| !data->east_texture)
	{
		clean_data(data);
		print_error();
	}
}

void	validate_player(t_data *data)
{
	int	p_counter;
	int	i;
	int	j;

	i = 0;
	p_counter = 0;
	;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'W' || data->map[i][j] == 'E')
			{
				p_counter++;
				j++;
			}
			else if (data->map[i][j] == 32 || data->map[i][j] == '\t')
				j++;
			else if (data->map[i][j] != '0' && data->map[i][j] != '1')
			{
				p_counter++;
				j++;
			}
			else
				j++;
		}
		i++;
	}
	if (p_counter != 1)
	{
		clean_data(data);
		print_error();
	}
}

void	validate_walls(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[0][j])
	{
		if ((data->map[0][j] != '1' && data->map[0][j] != ' ')
			|| (data->map[data->map_height - 1][j] != '1'
				&& data->map[data->map_height - 1][j] != ' '))
		{
			printf("up here\n");
			clean_data(data);
			print_error();
			return ;
		}
		j++;
	}
	while (i < data->map_height)
	{
		if (data->map[i][0] != '1' || data->map[i][ft_strlen(data->map[i])
			- 1] != '1')
		{
			clean_data(data);
			print_error();
			return ;
		}
		i++;
	}
}

void	validate_map(t_data *data)
{
	if (!data->map)
	{
		clean_data(data);
		print_error();
	}
	validate_player(data);
	validate_walls(data);
}

void	data_validation(t_data *data)
{
	validate_colors(data);
	validate_paths(data);
	validate_map(data);
}
