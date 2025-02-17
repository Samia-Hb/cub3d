// void draw_large_pixel(int x, int y, int width, int height, int color, void *mlx_ptr, void *win_ptr)
// {
//     int	i;
// 	int	j;

//     i = 0;
//     while (i < height)
//     {
//         j = 0;
// 		while (j < width)
// 		{
// 			my_mlx_pixel_put(mlx_ptr, win_ptr, x + i , y + j, color);
// 			j++;
// 		}
//         i++;
//     }
// }

// void my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
//     char *dst;

//     // Make sure the pixel is inside the window
//     if (x >= 0 && x < Window_width && y >= 0 && y < Window_height)
//     {
//         // Calculate the memory address of the pixel
//         dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));

//         // Write the color value to the address
//         *(unsigned int *)dst = color;
//     }
// }

// int find_max_row_length(t_data *data)
// {
// 	int max_length = 0;
// 	int i = 0;

// 	while (data->map[i])
// 	{
// 		int row_length = 0;
// 		while (data->map[i][row_length])
// 			row_length++;
// 		if (row_length > max_length)
// 			max_length = row_length;
// 		i++;
// 	}
// 	return (max_length);
// }

// void	*check_image(char c, void *mlx_ptr)
// {
// 	void		*image;
// 	int			img_width;
// 	int			img_height;

// 	img_width = 64;
// 	img_height = 64;
// 	if (c == '1')
// 		image = mlx_xpm_file_to_image(mlx_ptr,"assests/wall.xpm", &img_width, &img_height);
// 	else if (c == '0')
// 		image = mlx_xpm_file_to_image(mlx_ptr,"assests/road.xpm", &img_width, &img_height);
// 	else	
// 		image = mlx_xpm_file_to_image(mlx_ptr,"assests/player.xpm", &img_width, &img_height);
// 	if (!image)
// 	{
// 		perror("Failed to load one or more textures");
// 		return NULL;
// 	}
// 	return (image);
// }

// void draw_grid(char c, int i, int j, void *mlx_ptr, void *win_ptr)
// {
// 	size_t	color;
// 	int		k;
// 	int		l;

// 	k = 0;
// 	if (c == '0')
// 		color = 0xFFFFFF;
// 	else if (c ==  '1')
// 		color = 0x00008B;
// 	else
// 		color = 0x000000;
// 	while (k < grid_height)
// 	{
// 		l = 0;
// 		while (l < grid_width)
// 		{
// 			mlx_pixel_put(mlx_ptr,win_ptr,l * i, k * j, color);
// 			l++;
// 		}
// 		k++;
// 	}
// }
