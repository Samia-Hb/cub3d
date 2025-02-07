/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:49:36 by shebaz            #+#    #+#             */
/*   Updated: 2025/02/06 15:34:02 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

typedef struct helper
{
	char *line;
	struct helper *next;

}t_helper;

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
		|| !data->map_height || !data->north_texture
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
	int i;

	i = 0;
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
	printf("--Maap height = %d\n", data->map_height);
	printf("--Maap--\n");
	while (data->map[i])
	{
		printf("%s\n", data->map[i]);
		i++;
	}
}

void add_back(t_helper **list, char *content)
{
	t_helper *node;
	t_helper *tmp;

	node = malloc(sizeof(t_helper));
	if (!node)
		perror("Allocation Failed:");
	node->line = ft_strdup(content);
	node->next = NULL;
	if (!*list)
		*list = node;
	else
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
}

t_data *map_parsing(t_data *data)
{
	t_helper	*list;
	char		**map;
    char		*line;
	int			fd;
	int			tmp;
	int			i;
	int			k ;

	tmp = 0;
	k = 0;
	list = NULL;
	fd = open("map.cub", O_RDONLY, 0777);
	if (fd == -1)
		print_error();
	while (1)
    {
		i = 0;
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
			add_back(&list , line);
			free(line);
			k++;
		}
	}
	data->map_height = k;
	map = malloc((k + 1) * sizeof(char *));
	i = 0;
	while (i < k)
	{
		map[i] = ft_strdup(list->line);
		list = list->next;
		i++;
	}
	map[i] = NULL;
	data->map = map;
	print_struct(data);
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
	data->map = NULL;
}

void validate_colors (t_data *data)
{
	if (!data->ceiling_color || !data->Floor_color)
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
	if (data->Floor_color->b > 255 || data->Floor_color->b < 0
	|| data->Floor_color->r > 255 || data->Floor_color->r < 0
	|| data->Floor_color->g > 255 || data->Floor_color->g < 0)
	{
		clean_data(data);
		print_error();
	}
}
void validate_paths(t_data *data)
{
	if (!data->north_texture || !data->south_texture
		|| !data->west_texture || !data->east_texture)
	{
		clean_data(data);
		print_error();
	}
}

void validate_map()
{

}

void data_validating(t_data *data)
{
	validate_colors(data);
	validate_paths(data);
	validate_map();
}

int	main()
{
	t_data *data;

	data = malloc(sizeof(t_data));
	initiale_data(data);
	data = map_parsing(data);
	data_validating(data);
	return (1);
}