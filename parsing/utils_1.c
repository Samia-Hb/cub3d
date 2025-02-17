/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 22:11:50 by shebaz            #+#    #+#             */
/*   Updated: 2025/02/16 14:20:58 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	add_back(t_helper **list, char *content)
{
	t_helper	*node;
	t_helper	*tmp;

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

void	fill_the_array(t_helper *lst, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->map = malloc((data->map_height + 1) * sizeof(char *));
	if (!data->map)
		perror("Allocation Failled");
	while (i < data->map_height && lst)
	{
		j = 0;
		data->map[i] = malloc((ft_strlen(lst->line) + 1) * sizeof(char));
		if (!data->map[i])
			perror("Allocation Failled");
		while (j < ft_strlen(lst->line) && lst->line[j] != '\n')
		{
			data->map[i][j] = lst->line[j];
			j++;
		}
		data->map[i][j] = '\0';
		lst = lst->next;
		i++;
	}
	data->map[data->map_height] = '\0';
}
