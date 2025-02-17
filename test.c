# include "Minilibx-linux/mlx.h"
# include <stdio.h>
# define Window_width 1000
# define Window_height 800

typedef struct s_data {
    void    *mlx_ptr;
    void    *win_ptr;
    void    *img_ptr;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;
} t_data;

int get_pixel_color(t_data *data, int x, int y)
{
    char    *pixel;
    int     color;

    if (x < 0 || y < 0 || x >= Window_width || y >= Window_height)
        return (0);
    pixel = data->addr + (y * data->line_len + x * (data->bpp / 8));
    color = *(unsigned int *)pixel;
    return (color);
}

int main()
{
    t_data data;

    data.mlx_ptr = mlx_init();
    data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 600, "MLX Get Pixel");
    data.img_ptr = mlx_new_image(data.mlx_ptr, 800, 600);
    data.addr = mlx_get_data_addr(data.img_ptr, &data.bpp, &data.line_len, &data.endian);

    // Example: Get pixel color at (100, 100)
    int color = get_pixel_color(&data, 100, 100);
    printf("Pixel Color: %X\n", color);

    mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0);
    mlx_loop(data.mlx_ptr);

    return 0;
}
