/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 22:13:04 by shebaz            #+#    #+#             */
/*   Updated: 2025/02/16 15:30:23 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void equilibre_line(char ***map, int length)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((*map)[i])
	{
		j = 0;
		if (ft_strlen((*map)[i]) < length)
		{
			line = malloc((length + 1) * sizeof(char));
			while ((*map)[i][j])
			{
				line[j] = (*map)[i][j];
				j++;
			}
			while (j < length)
			{
				line[j] = '1';
				j++;
			}
			line[j] = '\0';
			(*map)[i] = strdup(line);
			free(line);
		}
		i++;
	}
}

void	map_updating(char ***map, int height)
{
	int		max_length;
	int		i;
	int		j;
	char	c;

	i = 0;
	c = 0;
	max_length = 0;
	while ((*map)[i])
	{
		j = 0;
		if ((*map)[i] && ft_strlen((*map)[i]) > max_length)
			max_length = ft_strlen((*map)[i]);		
		if (i == 0 || i == height - 1)
			c = '1';
		else
			c = '0';
		while ((*map)[i][j])
		{
			if ((*map)[i][j] == ' ' || (*map)[i][j] == '\t')
				((*map)[i][j] = c);
			j++;
		}
		i++;
	}
	equilibre_line(map, max_length);
}
