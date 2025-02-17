/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:49:36 by shebaz            #+#    #+#             */
/*   Updated: 2025/02/17 15:56:16 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int find_max_row_length(t_data *data)
{
	int max_length;
	int row_length;
	int i;

	i = 0;
	max_length = 0;
	while (data->map[i])
	{
		row_length = 0;
		while (data->map[i][row_length])
			row_length++;
		if (row_length > max_length)
			max_length = row_length;
		i++;
	}
	return (max_length);
}


void	print_struct(t_data *data)
{
	int	i;

	i = 0;
	// printf("east = '%s'\n", data->east_texture);
	// printf("north = '%s'\n", data->north_texture);
	// printf("west = '%s'\n", data->west_texture);
	// printf("east = '%s'\n", data->south_texture);
	// printf("--floor colores--\n");
	// printf("colors = '%d'\n", data->floor_color->r);
	// printf("       = '%d'\n", data->floor_color->g);
	// printf("       = '%d'\n", data->floor_color->b);
	// printf("--ceiling colores--\n");
	// printf("colors = '%d'\n", data->ceiling_color->r);
	// printf("       = '%d'\n", data->ceiling_color->g);
	// printf("       = '%d'\n", data->ceiling_color->b);
	// printf("--Maap height = %d\n", data->map_height);
	printf("--Maap--\n");
	while (data->map[i])
	{
		printf("%s\n", data->map[i]);
		i++;
	}
	// printf("Player's position = (%d , %d)\n", data->p_pos_x, data->p_pos_y);
	// printf("Player's Orientation = %c\n", data->p_orientation);
}

void	initiale_data(t_data *data)
{
	data->window = malloc(sizeof(t_window));
	data->ceiling_color = NULL;
	data->floor_color = NULL;
	data->east_texture = NULL;
	data->west_texture = NULL;
	data->north_texture = NULL;
	data->south_texture = NULL;
	data->window->mlx_ptr = NULL;
	data->window->mlx_window = NULL;
	data->map_height = 0;
	data->map = NULL;
	data->p_pos_x = 0;
	data->p_pos_y = 0;
	data->player.position_x = -1;
	data->player.position_y = -1;
	data->p_orientation = 0;
}


int get_pixel_color(t_data *data, int x, int y)
{
    char	*pixel;
    int		color;

    if (x < 0 || y < 0 || x >= Window_width || y >= Window_height)
        return (0);
    pixel = data->window->addr + (y * data->window->line_len + x * (data->window->bpp / 8));
    color = *(unsigned int *)pixel;
    return (color);
}

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    if (x < 0 || y < 0 || x >= Window_width || y >= Window_height)
        return;
    dst = data->window->addr + (y * data->window->line_len + x * (data->window->bpp / 8));
    *(unsigned int*)dst = color;
}

void draw_player(int i, int j, t_data *data)
{
    int cell_width;
    int cell_height;

    cell_width = Window_width / data->map_width;
    cell_height = Window_height / data->map_height;
	if (data->player.position_x == -1  && data->player.position_y == -1)
    {
        data->player.position_x = i * cell_height + cell_height / 2;
        data->player.position_y = j * cell_width + cell_width / 2;
    }
    data->player.height = cell_height / 4;
    data->player.width = cell_width / 4;
    draw_grid('0', i, j, data);
	i = 0;
	j  = 0;
	while (i < (cell_height / 4))
	{
		j = 0;
		while (j < (cell_width / 4))
		{
			my_mlx_pixel_put(data, data->player.position_y + j ,data->player.position_x + i, 0);
			j++;
		}
		i++;
	}
}

void draw_grid(char c, int i, int j, t_data *data)
{
    size_t	color;
    int		x;
	int 	y;
	
    if (c == '0')
		color = 0xFFFFFF;
    else if (c == '1')
		color = 0x00008B;
    else
	{
		color = 0x000000;
	}
	if (c != '1' && c!= '0')
		draw_player(i, j, data);
	else
	{
		y = i * data->window->cell_height;
		while (y < (i + 1) * data->window->cell_height && y < Window_height)
		{
			x = j * data->window->cell_width;
			while (x < (j + 1) * data->window->cell_width && x < Window_width)
			{
				my_mlx_pixel_put(data, x, y, color);
				x++;
			}
			y++;
		}
	}
}


void draw_map(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	data->map_width = find_max_row_length(data);
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			draw_grid(data->map[i][j], i , j , data);
			j++;
		}
		i++;
	}
}

// void update_player_pos(int x, int y, t_data *data)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (i < data->player.height)
// 	{
// 		j = 0;
// 		while (j < data->player.width)
// 		{
// 			my_mlx_pixel_put(data, x + i, y + j, 0);
// 			j++;
// 		}
// 		i++;
// 	}
// 	data->player.position_x = x;
// 	data->player.position_y = y;
// }

// void go_up(t_data *data)
// {
// 	// if (data->player.position_x < 0)
// 	// {
// 	// 	data->map[data->p_pos_x][data->p_pos_y] = '0';
// 	// 	data->map[data->p_pos_x - 1][data->p_pos_y] = data->p_orientation;
// 	// 	data->p_pos_x -= 1;
// 	// }
// 	if (data->map[data->p_pos_x][data->p_pos_y] == data->p_orientation && get_pixel_color(data, data->player.position_x - 1, data->player.position_y) != 0x00008B)
// 	{
// 		draw_grid('0', data->p_pos_x, data->p_pos_y, data);
// 		update_player_pos(data->player.position_x - 1,data->player.position_y, data);
// 	}
// }

// void go_right(t_data *data)
// {
// 	// if (data->player.position_y >= data->window->cell_width)
// 	// {
// 	// 	data->map[data->p_pos_x][data->p_pos_y] = '0';
// 	// 	data->map[data->p_pos_x - 1][data->p_pos_y] = data->p_orientation;
// 	// 	data->p_pos_x -= 1;
// 	// }
// 	if (data->map[data->p_pos_x][data->p_pos_y] == data->p_orientation && get_pixel_color(data, data->player.position_x, data->player.position_y + 1) != 0x00008B)
// 	{
// 		draw_grid('0', data->p_pos_x, data->p_pos_y, data);
// 		update_player_pos(data->player.position_x, data->player.position_y + 1, data);
// 	}
// }


// void go_left(t_data *data)
// {
// 	// if (data->player.position_y < 0)
// 	// {
// 	// 	data->map[data->p_pos_x][data->p_pos_y] = '0';
// 	// 	data->map[data->p_pos_x][data->p_pos_y - 1] = data->p_orientation;
// 	// 	data->p_pos_y -= 1;
// 	// }
// 	if (data->map[data->p_pos_x][data->p_pos_y] == data->p_orientation && get_pixel_color(data, data->player.position_x, data->player.position_y - 1) != 0x00008B)
// 	{
// 		draw_grid('0', data->p_pos_x, data->p_pos_y, data);
// 		update_player_pos(data->player.position_x ,data->player.position_y - 1, data);
// 	}
// }

// void go_down(t_data *data)
// {
// 	printf("Player map position before move: p_pos_x = %d, p_pos_y = %d\n", data->p_pos_x, data->p_pos_y);
// 	printf("Player Pixel position before move: p_pos_x = %d, p_pos_y = %d\n", data->player.position_x, data->player.position_y);
// 	if (data->player.position_y >= (data->p_pos_x * data->window->cell_height + data->window->cell_height))
// 	{
// 		data->map[data->p_pos_x][data->p_pos_y] = '0';
// 		data->map[data->p_pos_x + 1][data->p_pos_y] = data->p_orientation;
// 		data->p_pos_x += 1;
// 	}
// 	if (data->map[data->p_pos_x][data->p_pos_y] == data->p_orientation && get_pixel_color(data, data->player.position_x, data->player.position_y + 1) != 0x00008B)
// 	{
// 		draw_grid('0', data->p_pos_x, data->p_pos_y, data);
// 		update_player_pos(data->player.position_x , data->player.position_y + 1, data);
// 	}
// 	// printf("Player map position After move: p_pos_x = %d, p_pos_y = %d\n", data->p_pos_x, data->p_pos_y);
// 	// printf("Player Pixel position After move: p_pos_x = %d, p_pos_y = %d\n", data->player.position_x, data->player.position_y);
// }

void execution(t_data *data)
{
	data->map_width = find_max_row_length(data);
	data->window->cell_height = Window_height / data->map_height;
	data->window->cell_width = Window_width / data->map_width;
    data->window->mlx_ptr = mlx_init();
    data->window->mlx_window = mlx_new_window(data->window->mlx_ptr, Window_width, Window_height, "Cub3d");
	data->window->img_ptr = mlx_new_image(data->window->mlx_ptr, Window_width, Window_height);
	data->window->addr = mlx_get_data_addr(data->window->img_ptr, &data->window->bpp, &data->window->line_len, &data->window->endian);
	draw_map(data);
	mlx_put_image_to_window(data->window->mlx_ptr, data->window->mlx_window, data->window->img_ptr, 0, 0);
    mlx_hook(data->window->mlx_window, 2, 1L << 0, handle_key, data);
    mlx_loop(data->window->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		fd;

	if(argc != 2)
	{
		ft_putstr_fd("Invalid Number Of Argument\n", 2);
		return (1);
	}
	fd = open(argv[1], O_CREAT | O_RDWR, 0777);
	if (fd == -1)
		print_error();
	data = malloc(sizeof(t_data));
	initiale_data(data);
	data = map_parsing(data, fd);
	data_validation(data);
	map_updating(&data->map, data->map_height);
	execution(data);
	// clean_data(data);
	return (1);
}
