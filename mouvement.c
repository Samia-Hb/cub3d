/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:24:06 by shebaz            #+#    #+#             */
/*   Updated: 2025/02/18 21:31:28 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void update_player_pos(int x, int y, t_data *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->player.height)
	{
		j = 0;
		while (j < data->player.width)
		{
			my_mlx_pixel_put(data, y + j, x + i, 0);
			j++;
		}
		i++;
	}
	data->player.position_x = x;
	data->player.position_y = y;
}

void go_up(t_data *data)
{
    if (data->player.position_x <= (data->p_pos_x * cell_height) && data->map[data->p_pos_x - 1][data->p_pos_y] != '1')
    {
        data->map[data->p_pos_x][data->p_pos_y] = '0';
        data->map[data->p_pos_x - 1][data->p_pos_y] = data->p_orientation;
        data->p_pos_x -= 1;
    }
    if ((data->player.position_x <= (data->p_pos_x * cell_height) && data->map[data->p_pos_x - 1][data->p_pos_y] != '1') || (data->player.position_x > (data->p_pos_x * cell_height)))
    {
        draw_grid('0', data->p_pos_x, data->p_pos_y, data);
        data->player.position_x -= speed;
        data->player.position_y += 0;
    }
}

void go_left(t_data *data)
{
    if (data->player.position_y <= (data->p_pos_y * cell_width) && data->map[data->p_pos_x][data->p_pos_y - 1] != '1')
    {
        data->map[data->p_pos_x][data->p_pos_y] = '0';
        data->map[data->p_pos_x][data->p_pos_y - 1] = data->p_orientation;
        data->p_pos_y -= 1;
    }
    if ((data->player.position_y <= (data->p_pos_y * cell_width) && data->map[data->p_pos_x][data->p_pos_y - 1] != '1') || (data->player.position_y > (data->p_pos_y * cell_width)))
    {
        draw_grid('0', data->p_pos_x, data->p_pos_y, data);
		data->player.position_y -= speed;
		data->player.position_x += 0;
    }
}
void go_down(t_data *data)
{
    int next_x = data->player.position_x;
    if ((next_x + data->player.height) < ((data->p_pos_x + 1) * cell_height) || data->map[data->p_pos_x + 1][data->p_pos_y] != '1')
    {
        draw_grid('0', data->p_pos_x, data->p_pos_y, data);
        data->player.position_x += speed;
    }
    if (data->player.position_x >= (data->p_pos_x + 1) * cell_height)
    {
        data->map[data->p_pos_x][data->p_pos_y] = '0';
        data->map[data->p_pos_x + 1][data->p_pos_y] = data->p_orientation;
        data->p_pos_x += 1;
    }
}

void go_right(t_data *data)
{
    int next_y = data->player.position_y;

    if ((next_y + data->player.width) < ((data->p_pos_y + 1) * cell_width) || data->map[data->p_pos_x][data->p_pos_y + 1] != '1')
    {
        draw_grid('0', data->p_pos_x, data->p_pos_y, data);
        data->player.position_y += speed;
    }
    if (data->player.position_y >= (data->p_pos_y + 1) * cell_width)
    {
        data->map[data->p_pos_x][data->p_pos_y] = '0';
        data->map[data->p_pos_x][data->p_pos_y + 1] = data->p_orientation;
        data->p_pos_y += 1;
    }
}

int handle_key(int keycode, t_data *data)
{
    int		i;
    int		j;
    char	c;

    printf("Keycode: %d\n", keycode);
    if (keycode == 65307)
        exit(0);
    if (keycode == 119 || keycode == 65362)
        go_up(data);
    else if (keycode == 115 || keycode == 65364)
        go_down(data);
    else if (keycode == 97 || keycode == 65361)
        go_left(data);
    else if (keycode == 100 || keycode == 65363)
	{
        go_right(data);
	}
	mlx_clear_window(data->window->mlx_ptr, data->window->mlx_window);
    i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
            c = data->map[i][j];
            if (c == data->p_orientation)
                c = '0';
			draw_grid(c, i , j , data);
			j++;
		}
		i++;
	}
    update_player_pos(data->player.position_x, data->player.position_y, data);
	mlx_put_image_to_window(data->window->mlx_ptr, data->window->mlx_window, data->window->img_ptr, 0, 0);
    return (0);
}