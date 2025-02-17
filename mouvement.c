/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:24:06 by shebaz            #+#    #+#             */
/*   Updated: 2025/02/17 17:54:01 by shebaz           ###   ########.fr       */
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
	printf("Player map position before move: p_pos_x = %d, p_pos_y = %d\n", data->p_pos_x, data->p_pos_y);
	printf("Player Pixel position before move: p_pos_x = %d, p_pos_y = %d\n", data->player.position_x, data->player.position_y);
    if (data->player.position_x > 0 && data->player.position_x <= (data->p_pos_x * data->window->cell_height) && data->map[data->p_pos_x - 1][data->p_pos_y] != '1')
    {
        printf(">>>>>>>>>>>>>>>>>>>check up here<<<<<<<<<<<<<<<<<<<<\n");
        data->map[data->p_pos_x][data->p_pos_y] = '0';
        data->map[data->p_pos_x - 1][data->p_pos_y] = data->p_orientation;
        data->p_pos_x -= 1;
    }
    if (get_pixel_color(data, data->player.position_x - 1, data->player.position_y) != 0x00008B)
    {
        printf(">>>>>>>>>>>>>>>>>>>check up here 2<<<<<<<<<<<<<<<<<<<<\n");
        draw_grid('0', data->p_pos_x, data->p_pos_y, data);
        data->player.position_x -= 1;
        data->player.position_y += 0;
        // update_player_pos(data->player.position_x - 1, data->player.position_y, data);
    }
    printf("----------------------------------------------------\n");
    printf("Player map position After move: p_pos_x = %d, p_pos_y = %d\n", data->p_pos_x, data->p_pos_y);
    printf("Player Pixel position After move: p_pos_x = %d, p_pos_y = %d\n", data->player.position_x, data->player.position_y);
}

void go_left(t_data *data)
{
	// printf("Player map position before move: p_pos_x = %d, p_pos_y = %d\n", data->p_pos_x, data->p_pos_y);
	// printf("Player Pixel position before move: p_pos_x = %d, p_pos_y = %d\n", data->player.position_x, data->player.position_y);
    if (data->player.position_y > 0 && data->player.position_y <= (data->p_pos_y* data->window->cell_width) && data->map[data->p_pos_x][data->p_pos_y - 1] != '1')
    {
        // printf(">>>>>>>>>>>>>>>>>>>check up here<<<<<<<<<<<<<<<<<<<<\n");
        data->map[data->p_pos_x][data->p_pos_y] = '0';
        data->map[data->p_pos_x][data->p_pos_y - 1] = data->p_orientation;
        data->p_pos_y -= 1;
    }
    if (get_pixel_color(data, data->player.position_x, data->player.position_y - 1) != 0x00008B)
    {
        // printf(">>>>>>>>>>>>>>>>>>>check up here 2<<<<<<<<<<<<<<<<<<<<\n");
        draw_grid('0', data->p_pos_x, data->p_pos_y, data);
        data->player.position_y -= 1;
        data->player.position_x += 0;
        // update_player_pos(data->player.position_x - 1, data->player.position_y, data);
    }
    // printf("----------------------------------------------------\n");
    // printf("Player map position After move: p_pos_x = %d, p_pos_y = %d\n", data->p_pos_x, data->p_pos_y);
    // printf("Player Pixel position After move: p_pos_x = %d, p_pos_y = %d\n", data->player.position_x, data->player.position_y);
}

void go_right(t_data *data)
{
	printf("Player map position before move: p_pos_x = %d, p_pos_y = %d\n", data->p_pos_x, data->p_pos_y);
	printf("Player Pixel position before move: p_pos_x = %d, p_pos_y = %d\n", data->player.position_x, data->player.position_y);
    if (data->player.position_y < Window_width && data->player.position_y >= ((data->p_pos_y * data->window->cell_width) + data->window->cell_width) && data->map[data->p_pos_x][data->p_pos_y + 1] != '1')
    {
        printf(">>>>>>>>>>>>>>>>>>>check up here<<<<<<<<<<<<<<<<<<<<\n");
        data->map[data->p_pos_x][data->p_pos_y] = '0';
        data->map[data->p_pos_x][data->p_pos_y + 1] = data->p_orientation;
        data->p_pos_y += 1;
    }
    if (get_pixel_color(data, data->player.position_x, data->player.position_y + data->player.width) != 0x00008B)
    {
        printf(">>>>>>>>>>>>>>>>>>>check up here 2<<<<<<<<<<<<<<<<<<<<\n");
        draw_grid('0', data->p_pos_x, data->p_pos_y, data);
        data->player.position_y += 1;
        data->player.position_x += 0;
        // update_player_pos(data->player.position_x - 1, data->player.position_y, data);
    }
    printf("----------------------------------------------------\n");
    printf("Player map position After move: p_pos_x = %d, p_pos_y = %d\n", data->p_pos_x, data->p_pos_y);
    printf("Player Pixel position After move: p_pos_x = %d, p_pos_y = %d\n", data->player.position_x, data->player.position_y);
}

void go_down(t_data *data)
{
	// printf("Player map position before move: p_pos_x = %d, p_pos_y = %d\n", data->p_pos_x, data->p_pos_y);
	// printf("Player Pixel position before move: p_pos_x = %d, p_pos_y = %d\n", data->player.position_x, data->player.position_y);
    if (data->player.position_x < Window_height && data->player.position_x >= (data->p_pos_x * data->window->cell_height + data->window->cell_height) && data->map[data->p_pos_x + 1][data->p_pos_y] != '1')
    {
        printf(">>>>>>>>>>>>>>>>>>>check up here<<<<<<<<<<<<<<<<<<<<\n");
        data->map[data->p_pos_x][data->p_pos_y] = '0';
        data->map[data->p_pos_x + 1][data->p_pos_y] = data->p_orientation;
        data->p_pos_x += 1;
    }
    if (get_pixel_color(data, data->player.position_x + data->player.height, data->player.position_y) != 0x00008B)
    {
        printf(">>>>>>>>>>>>>>>>>>>check up here 2<<<<<<<<<<<<<<<<<<<<\n");
        draw_grid('0', data->p_pos_x, data->p_pos_y, data);
        data->player.position_x += 1;
        data->player.position_y += 0;
        // update_player_pos(data->player.position_x - 1, data->player.position_y, data);
    }
    printf("----------------------------------------------------\n");
    printf("Player map position After move: p_pos_x = %d, p_pos_y = %d\n", data->p_pos_x, data->p_pos_y);
    printf("Player Pixel position After move: p_pos_x = %d, p_pos_y = %d\n", data->player.position_x, data->player.position_y);
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
    // print_struct(data);
	// draw_map(data);

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


/////////////////////////////////////////////////////////////////////////////////////////////////

// void draw_grid(char c, int i, int j, t_data *data)
// {
//     size_t	color;
//     int		x;
// 	int 	y;
	
//     if (c == '0')
// 		color = 0xFFFFFF;
//     else if (c == '1')
// 		color = 0x00008B;
//     else
// 	{
// 		color = 0x000000;
// 	}
// 	if (c != '1' && c!= '0')
// 		draw_player(i, j, data);
// 	else
// 	{
// 		y = i * data->window->cell_height;
// 		while (y < (i + 1) * data->window->cell_height && y < Window_height)
// 		{
// 			x = j * data->window->cell_width;
// 			while (x < (j + 1) * data->window->cell_width && x < Window_width)
// 			{
// 				my_mlx_pixel_put(data, x, y, color);
// 				x++;
// 			}
// 			y++;
// 		}
// 	}
// }


// void draw_map(t_data *data)
// {
// 	int		i;
// 	int		j;

// 	i = 0;
// 	data->map_width = find_max_row_length(data);
// 	while (data->map[i])
// 	{
// 		j = 0;
// 		while (data->map[i][j])
// 		{
// 			draw_grid(data->map[i][j], i , j , data);
// 			j++;
// 		}
// 		i++;
// 	}
// }