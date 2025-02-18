/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:24:06 by shebaz            #+#    #+#             */
/*   Updated: 2025/02/18 17:16:48 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define speed 5
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
int check_wall(int x, int y, t_data *data, int tmp)
{
    // tmp == 1 mean I trait( up and left)
    if (tmp == 1)
    {
        printf("x ==== %d\n", x);
        printf("compara === %d\n", data->p_pos_x * data->window->cell_height);
        printf("y ==== %d\n", y);
        printf("compara === %d\n", data->p_pos_y * data->window->cell_width);
        // printf("cell_width == %d\n", data->window->cell_width);
        // printf("cell_width_original == %d\n", Window_width / data->map_width);
        if (x <= (data->p_pos_x * data->window->cell_height))
        {
            // printf("check up hereeeeeeeeeeeeeeeeeeeee\n");
            if (data->map[data->p_pos_x - 1][data->p_pos_y] == '1' || data->map[data->p_pos_x - 1][data->p_pos_y - 1] == '1')
                return (0);
        }
    }
    // tmp == 1 mean I trait ( down and right)
    if (tmp == 0)
    {
        if (x > data->p_pos_x * data->window->cell_height  + data->window->cell_height|| y > data->p_pos_y * data->window->cell_width + data->window->cell_width)
        {
            if (data->map[data->p_pos_x + 1][data->p_pos_y] == '1' || data->map[data->p_pos_x + 1][data->p_pos_y - 1] == '1')
                return (0);
        }
    }
    return (1);
}

// void go_right(t_data *data)
// {
// 	printf("Player map position before move: p_pos_x = %d, p_pos_y = %d\n", data->p_pos_x, data->p_pos_y);
// 	printf("Player Pixel position before move: p_pos_x = %d, p_pos_y = %d\n", data->player.position_x, data->player.position_y);
//     if (data->player.position_y < Window_width && data->player.position_y >= ((data->p_pos_y * data->window->cell_width) + data->window->cell_width) && data->map[data->p_pos_x][data->p_pos_y + 1] != '1')
//     {
//         printf(">>>>>>>>>>>>>>>>>>>check up here<<<<<<<<<<<<<<<<<<<<\n");
//         data->map[data->p_pos_x][data->p_pos_y] = '0';
//         data->map[data->p_pos_x][data->p_pos_y + 1] = data->p_orientation;
//         data->p_pos_y += 1;
//     }
//     if (get_pixel_color(data, data->player.position_x, data->player.position_y + data->player.width) != 0x00008B)
//     {
//         printf(">>>>>>>>>>>>>>>>>>>check up here 2<<<<<<<<<<<<<<<<<<<<\n");
//         draw_grid('0', data->p_pos_x, data->p_pos_y, data);
//         data->player.position_y += 1;
//         data->player.position_x += 0;
//         // update_player_pos(data->player.position_x - 1, data->player.position_y, data);
//     }
//     printf("----------------------------------------------------\n");
//     printf("Player map position After move: p_pos_x = %d, p_pos_y = %d\n", data->p_pos_x, data->p_pos_y);
//     printf("Player Pixel position After move: p_pos_x = %d, p_pos_y = %d\n", data->player.position_x, data->player.position_y);
// }

// void go_down(t_data *data)
// {
// 	// printf("Player map position before move: p_pos_x = %d, p_pos_y = %d\n", data->p_pos_x, data->p_pos_y);
// 	// printf("Player Pixel position before move: p_pos_x = %d, p_pos_y = %d\n", data->player.position_x, data->player.position_y);
//     if (data->player.position_x < Window_height && data->player.position_x >= (data->p_pos_x * data->window->cell_height + data->window->cell_height) && data->map[data->p_pos_x + 1][data->p_pos_y] != '1')
//     {
//         printf(">>>>>>>>>>>>>>>>>>>check up here<<<<<<<<<<<<<<<<<<<<\n");
//         data->map[data->p_pos_x][data->p_pos_y] = '0';
//         data->map[data->p_pos_x + 1][data->p_pos_y] = data->p_orientation;
//         data->p_pos_x += 1;
//     }
//     if (get_pixel_color(data, data->player.position_x + data->player.height, data->player.position_y) != 0x00008B)
//     {
//         printf(">>>>>>>>>>>>>>>>>>>check up here 2<<<<<<<<<<<<<<<<<<<<\n");
//         draw_grid('0', data->p_pos_x, data->p_pos_y, data);
//         data->player.position_x += 1;
//         data->player.position_y += 0;
//         // update_player_pos(data->player.position_x - 1, data->player.position_y, data);
//     }
//     printf("----------------------------------------------------\n");
//     printf("Player map position After move: p_pos_x = %d, p_pos_y = %d\n", data->p_pos_x, data->p_pos_y);
//     printf("Player Pixel position After move: p_pos_x = %d, p_pos_y = %d\n", data->player.position_x, data->player.position_y);
// }

void go_up(t_data *data)
{
    if (data->player.position_x <= (data->p_pos_x * data->window->cell_height) && data->map[data->p_pos_x - 1][data->p_pos_y] != '1')
    {
        data->map[data->p_pos_x][data->p_pos_y] = '0';
        data->map[data->p_pos_x - 1][data->p_pos_y] = data->p_orientation;
        data->p_pos_x -= 1;
    }
    if ((data->player.position_x <= (data->p_pos_x * data->window->cell_height) && data->map[data->p_pos_x - 1][data->p_pos_y] != '1') || (data->player.position_x > (data->p_pos_x * data->window->cell_height)))
    {
        draw_grid('0', data->p_pos_x, data->p_pos_y, data);
        data->player.position_x -= speed;
        data->player.position_y += 0;
    }
}

void go_left(t_data *data)
{
    if (data->player.position_y <= (data->p_pos_y * data->window->cell_width) && data->map[data->p_pos_x][data->p_pos_y - 1] != '1')
    {
        data->map[data->p_pos_x][data->p_pos_y] = '0';
        data->map[data->p_pos_x][data->p_pos_y - 1] = data->p_orientation;
        data->p_pos_y -= 1;
    }
    if ((data->player.position_y <= (data->p_pos_y * data->window->cell_width) && data->map[data->p_pos_x][data->p_pos_y - 1] != '1') || (data->player.position_y > (data->p_pos_y * data->window->cell_width)))
    {
        draw_grid('0', data->p_pos_x, data->p_pos_y, data);
        data->player.position_y -= speed;
        data->player.position_x += 0;
    }
}

// void go_right(t_data *data)
// {
//     if (data->player.position_y >= (data->p_pos_y * data->window->cell_width) && data->map[data->p_pos_x][data->p_pos_y + 1] != '1')
//     {
//         data->map[data->p_pos_x][data->p_pos_y] = '0';
//         data->map[data->p_pos_x][data->p_pos_y + 1] = data->p_orientation;
//         data->p_pos_y += 1;
//     }
//     if ((data->player.position_y >= (data->p_pos_y * data->window->cell_width) && data->map[data->p_pos_x][data->p_pos_y + 1] != '1') || (data->player.position_y > (data->p_pos_y * data->window->cell_width)))
//     {
//         draw_grid('0', data->p_pos_x, data->p_pos_y, data);
//         data->player.position_y += speed;
//         data->player.position_x += 0;
//     }
// }
#define WHITE 0xFFFFFF  // Hexadecimal(R=255, G=255, B=255)

void go_down(t_data *data)
{    
    if (data->player.position_x < ((data->p_pos_x * data->window->cell_height) + data->window->cell_height))
    {
        if (get_pixel_color(data, data->player.position_x + (data->player.height), data->player.position_y) == WHITE)
        {            
            draw_grid('0', data->p_pos_x, data->p_pos_y, data);
            data->player.position_x += speed;
            data->player.position_y += 0;   
        }
    }
    else
    {
        
    }
}
void go_right(t_data *data)
{    
    printf("P_P_POS ==== %d\n", data->player.position_y);
    printf("compare ==== %d\n", (data->p_pos_y * data->window->cell_width) + (data->window->cell_width));
    // printf("c ===== %c\n", data->map[data->p_pos_x + 1][data->p_pos_y]);
    if (data->player.position_y < ((data->p_pos_y * data->window->cell_width) + data->window->cell_width))
    {
        // printf("color ==== %d\n", get_pixel_color(data, data->player.position_x + 1, data->player.position_y));
        if (get_pixel_color(data, data->player.position_x, data->player.position_y + (data->player.width)) == WHITE)
        {            
            draw_grid('0', data->p_pos_x, data->p_pos_y, data);
            data->player.position_y += speed;
            data->player.position_x += 0;   
        }
        // else
        // {
                
        // }
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

// check
	// printf("Player map position before move: M_pos_x = %d, M_pos_y = %d\n", data->p_pos_x, data->p_pos_y);
	// printf("Player Pixel position before move: p_pos_x = %d, p_pos_y = %d\n", data->player.position_x, data->player.position_y);
    // printf("result of counting ==== %d\n", (data->p_pos_x * data->window->cell_height));
    // printf("color ===== %d\n", get_pixel_color(data, data->player.position_x - data->player.width , data->player.position_y));
    // printf("player color ===== %d\n", get_pixel_color(data, data->player.position_x, data->player.position_y));
//check up 2
    // printf("value ===== %c\n ", data->map[data->p_pos_x + 1][data->p_pos_y]);
    // if (data->player.position_x >= (data->p_pos_x * data->window->cell_height))
    // {
    //     if (data->map[data->p_pos_x + 1][data->p_pos_y] !=)
    //     printf("check up here 2\n");
    //     draw_grid('0', data->p_pos_x, data->p_pos_y, data);
    //     data->player.position_x += 1;
    //     data->player.position_y += 0;
    // }
    // if (data->map[data->p_pos_x + 1][data->p_pos_y] != '1')
    // {
    //     printf("check up here 1\n");
    //     data->map[data->p_pos_x][data->p_pos_y] = '0';
    //     data->map[data->p_pos_x + 1][data->p_pos_y] = data->p_orientation;
    //     data->p_pos_x += 1;
    // }
