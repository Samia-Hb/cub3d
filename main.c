/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:49:36 by shebaz            #+#    #+#             */
/*   Updated: 2025/02/08 23:16:11 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_struct(t_data *data)
{
	int	i;

	i = 0;
	printf("east = '%s'\n", data->east_texture);
	printf("north = '%s'\n", data->north_texture);
	printf("west = '%s'\n", data->west_texture);
	printf("east = '%s'\n", data->south_texture);
	printf("--floor colores--\n");
	printf("colors = '%d'\n", data->floor_color->r);
	printf("       = '%d'\n", data->floor_color->g);
	printf("       = '%d'\n", data->floor_color->b);
	printf("--ceiling colores--\n");
	printf("colors = '%d'\n", data->ceiling_color->r);
	printf("       = '%d'\n", data->ceiling_color->g);
	printf("       = '%d'\n", data->ceiling_color->b);
	printf("--Maap height = %d\n", data->map_height);
	printf("--Maap--\n");
	while (data->map[i])
	{
		printf("%s\n", data->map[i]);
		i++;
	}
}

void	initiale_data(t_data *data)
{
	data->ceiling_color = NULL;
	data->floor_color = NULL;
	data->east_texture = NULL;
	data->west_texture = NULL;
	data->north_texture = NULL;
	data->south_texture = NULL;
	data->map_height = 0;
	data->map = NULL;
}

int	main(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	initiale_data(data);
	data = map_parsing(data);
	data_validation(data);
	map_updating(&data->map, data->map_height);
	// clean_data(data);
	return (1);
}
