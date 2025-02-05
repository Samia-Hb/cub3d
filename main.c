/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:49:36 by shebaz            #+#    #+#             */
/*   Updated: 2025/02/05 14:07:36 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void print_error()
{
	write(2, "Error : Invalid Map\n", 20);
	exit(1);
}
char *rm_nline(char *line)
{
	char *result;

	result = ft_strdup("");
	if (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			return (ft_strncpy(result, line, strlen(line) - 1));
	}
	return (line);
}
void set_texture(t_data *data, char *line)
{
	char	**splited;
	int		tmp;
	int		i;

	i = 0;
	tmp = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (!strncmp(line + i, "NO", 2))
		tmp = 1;
	else if (!strncmp(line + i, "SO", 2))
		tmp = 2;
	else if (!strncmp(line + i, "WE", 2))
		tmp = 3;
	else if (!strncmp(line + i, "EA", 2))
		tmp = 4;
	if (!tmp)
		print_error();
	splited = ft_split(line, ' ');
	if (tmp == 1)
		data->north_texture = rm_nline(splited[1]);
	else if (tmp == 2)
		data->south_texture = rm_nline(splited[1]);
	else if (tmp == 3)
		data->west_texture = rm_nline(splited[1]);
	else if (tmp == 4)
		data->east_texture = rm_nline(splited[1]);
}

t_rgb *apply_colors(char **arr)
{
	t_rgb *rgb;

	rgb = malloc(sizeof(t_rgb));
	if (!rgb)
		perror("Error :");
	rgb->r = atoi(arr[0]);
	rgb->g = atoi(arr[1]);
	rgb->b = atoi(arr[2]);
	if (rgb->r > 255 || rgb->r < 0 || rgb->g > 255 || rgb->g < 0 || rgb->b > 255 || rgb->b < 0)
		print_error();
	return (rgb);
}

void set_colors(t_data *data, char *line)
{
	int		tmp;
	char	**splited;
	int		i;

	i = 0;
	tmp = 0;
	if (!strncmp("F", line, 1))
		tmp = 1;
	else if (!strncmp("C", line, 1))
		tmp = 2;
	i++;
	while (line[i] && line[i] == ' ')
		i++;
	splited = ft_split(line + i, ',');
	if (tmp == 1)
		data->Floor_color = apply_colors(splited);
	else if (tmp == 2)
		data->ceiling_color = apply_colors(splited);
}

int is_empty_line(char *line)
{
	int i;

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
	if (!data->ceiling_color || !data->east_texture || !data->Floor_color
		|| !data->map_height || !data->map_weight || !data->north_texture
		|| !data->south_texture || !data->west_texture)
		return (0);
	return (1);
}

int	another_content(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' || str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}
void	print_struct(t_data *data)
{
	printf("east = '%s'\n",data->east_texture);
	printf("north = '%s'\n",data->north_texture);
	printf("west = '%s'\n",data->west_texture);
	printf("east = '%s'\n",data->south_texture);
	printf("--floor colores--\n");
	printf("colors = '%d'\n", data->Floor_color->r);
	printf("       = '%d'\n", data->Floor_color->g);
	printf("       = '%d'\n", data->Floor_color->b);
	printf("--ceiling colores--\n");
	printf("colors = '%d'\n", data->ceiling_color->r);
	printf("       = '%d'\n", data->ceiling_color->g);
	printf("       = '%d'\n", data->ceiling_color->b);
}

t_data *map_parsing(t_data *data)
{
	int		p_counter;
	int		counter;
	int		weight;
	int		height;
    char	*line;
	int		fd;
	int		i;
	int		tmp;

	tmp = 0;
	weight = 0;
	height = 0;
	counter = 0;
	p_counter = 0;
	fd = open("map.cub", O_RDONLY, 0777);
	if (fd == -1)
		print_error();
	int j = 0;
	while (1)
    {
		i = 0;
		j++;
		line = get_next_line(fd);
		if (!line)
			break ;
		while (line[i] && line[i] == ' ')
			i++;
		if (!strncmp(line + i, "NO", 2) || !strncmp(line + i, "WE", 2)
			|| !strncmp(line + i, "SO", 2) || !strncmp(line + i, "EA", 2))
			set_texture(data, line + i);
		else if (!strncmp("F", line + i, 1) || !strncmp("C", line + i, 1))
			set_colors(data, line + i);
		else if (is_empty_line(line) && !tmp)
			continue ;
		else if (is_empty_line(line) && tmp)
			print_error();
		else
		{
			tmp = 1;
			weight = strlen(line);
			while (line)
			{
				line = get_next_line(fd);
				if (ft_strlen(line) > weight)
					weight = strlen(line);
				printf("line = %s\n", line);	
			}
			// height++;
			// if (ft_strlen(line) > weight)
			// 	weight = strlen(line);
			// while (line[i])
			// {
			// 	if (line[i] == 32)
			// 		i++;
			// 	if (line[i] == 'N' || line[i] == 'S' ||line[i] == 'E' ||line[i] == 'W')
			// 		p_counter++;
			// 	i++;
			// }
		}
	}
	data->map_height = height;
	data->map_weight = weight;
	print_struct(data);
	if (!check_data(data) || p_counter > 1 || counter)
		print_error();
	return (data);
}

void initiale_data(t_data *data)
{
	data->ceiling_color = NULL;
	data->Floor_color = NULL;
	data->east_texture = NULL;
	data->west_texture = NULL;
	data->north_texture = NULL;
	data->south_texture = NULL;
	data->map_height = 0;
	data->map_weight = 0;
}

int	main()
{
	t_data *data;

	data = malloc(sizeof(t_data));
	initiale_data(data);
	data = map_parsing(data);
	return (1);
}