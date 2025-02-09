/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:50:25 by shebaz            #+#    #+#             */
/*   Updated: 2024/04/21 16:12:26 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	additional_case(const char *str, int tmp)
{
	int	i;

	i = 0;
	if (str[i] != '\0' || tmp > 1)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}

long	ft_atoi(const char *str)
{
	int		i;
	int		tmp;
	int		signe;
	long	result;

	i = 0;
	tmp = 0;
	signe = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
		tmp++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	additional_case(str, tmp);
	return (signe * result);
}
