/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_extraction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 22:08:51 by shebaz            #+#    #+#             */
/*   Updated: 2025/02/11 19:11:31 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*rm_nline(char *line)
{
	char	*result;

	result = NULL;
	if (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			return (ft_strncpy(result, line, strlen(line) - 1));
	}
	return (line);
}

void	set_texture(t_data *data, char *line)
{
	char	**splited;
	int		tmp;
	int		i;

	i = 0;
	tmp = 00;
	while (line[i] && line[i] == ' ')
		i++;
	if (!ft_strncmp(line + i, "NO", 2))
		tmp = 1;
	else if (!ft_strncmp(line + i, "SO", 2))
		tmp = 2;
	else if (!ft_strncmp(line + i, "WE", 2))
		tmp = 3;
	else if (!ft_strncmp(line + i, "EA", 2))
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
	ft_free(splited);
}

t_rgb	*apply_colors(t_data *data, char **arr)
{
	t_rgb	*rgb;

	if (!arr[0] || !arr[1] || !arr[2])
	{
		clean_data(data);
		print_error();
	}
	rgb = malloc(sizeof(t_rgb));
	if (!rgb)
		perror("Error :");
	rgb->r = atoi(arr[0]);
	rgb->g = atoi(arr[1]);
	rgb->b = atoi(arr[2]);
	return (rgb);
}

void	set_colors(t_data *data, char *line)
{
	int		tmp;
	char	**splited;
	int		i;

	i = 0;
	tmp = 0;
	if (!ft_strncmp("F", line, 1))
		tmp = 1;
	else if (!ft_strncmp("C", line, 1))
		tmp = 2;
	i++;
	while (line[i] && line[i] == ' ')
		i++;
	splited = ft_split(line + i, ',');
	if (!splited)
		perror("Allocation Failled");
	if (tmp == 1)
		data->floor_color = apply_colors(data, splited);
	else if (tmp == 2)
		data->ceiling_color = apply_colors(data, splited);
	ft_free(splited);
}

t_data	*map_parsing(t_data *data, int fd)
{
	t_helper	*list;
	char		*line;
	int			tmp;
	int			i;
	int			k;

	tmp = 0;
	k = 0;
	list = NULL;
	while (1)
	{
		i = 0;
		line = get_next_line(fd);
		if (!line)
			break ;
		while (line[i] && line[i] == ' ')
			i++;
		if (!ft_strncmp(line + i, "NO", 2) || !ft_strncmp(line + i, "WE", 2)
			|| !ft_strncmp(line + i, "SO", 2) || !ft_strncmp(line + i, "EA", 2))
			set_texture(data, line + i);
		else if (!ft_strncmp("F", line + i, 1) || !ft_strncmp("C", line + i, 1))
			set_colors(data, line + i);
		else if (is_empty_line(line) && !tmp)
		{
			free(line);
			continue ;
		}
		else if (is_empty_line(line) && tmp)
			print_error();
		else
		{
			tmp = 1;
			add_back(&list, line + i);
			k++;
		}
		free(line);
	}
	data->map_height = k;
	fill_the_array(list, data);
	clean_list(list);
	return (data);
}
