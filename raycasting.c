/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:00:23 by shebaz            #+#    #+#             */
/*   Updated: 2025/02/22 21:06:26 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"


double get_player_direction(t_data *data)
{
    double	dir;

    dir = 0;
    if (data->p_orientation == 'N') // up
        dir = 3 *  M_PI / 2;     
    else if (data->p_orientation == 'S') // down
        dir = 2 *  M_PI; 
    else if (data->p_orientation == 'E') // right
        dir = 0; 
    else if (data->p_orientation == 'W') // left
        dir = 3 *  M_PI; 
    return (dir);
}


int cast_ray(t_casting *data, int ray_angle)
{
	int		i = 0;
	double	dx;
	double	dy;
	double	step;
	dx = cos(ray_angle);
	dy = sin(ray_angle);
	step = dx > dy ? dx : dy ;

	double in_x = dx / step;
	double in_y = dy / step; 
	while (i < Window_width)
	{
		double tmp = data->start_angle + (i * ray_angle);
		my_mlx_pixel_put(data->data, dx , dy, 0);
		dx += in_x;
		dy += in_y;
		i++;
	}
	return (step);
}
void raycasting(t_data *data)
{    
	t_casting		*cast_data;
	// int			step;
	
	double ray_angle = (60 / (double)data->map_width);
	cast_data = malloc(sizeof(t_casting));
	if (!cast_data)
		perror("Error\n");
	cast_data->data = data;
	cast_data->fov = 60;
	cast_data->dir = get_player_direction(data);
	cast_data->start_angle = cast_data->dir - (cast_data->fov / 2);
	cast_data->end_angle = cast_data->dir + (cast_data->fov / 2);
	while (cast_data->start_angle <= cast_data->end_angle)
    {		
		cast_ray(cast_data, ray_angle);
		cast_data->start_angle += ray_angle;        
	}
}