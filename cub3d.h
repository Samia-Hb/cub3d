/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:12:50 by shebaz            #+#    #+#             */
/*   Updated: 2025/02/18 21:29:45 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "Libft/libft.h"
# include "Minilibx-linux/mlx.h"
# include "get_next_line/get_next_line.h"
# include <dirent.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define W 87
# define A 65
# define S 83
# define D 68

# define Window_width 1920
# define Window_height 1080

# define cell_width 64
# define cell_height 64
# define speed 5

typedef struct rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct player
{
	int position_x;
	int position_y;
	int width;
	int height;
}t_player;

typedef struct window
{
	char			*addr;
    int				bpp;
    int     		line_len;
    int     		endian;
	void    		*img_ptr;
	void			*mlx_ptr;
	void 			*mlx_window;
	// int				cell_width;
	// int				cell_height;
}t_window;

typedef struct data
{
	char			*north_texture;
	char			*south_texture;
	char			*west_texture;
	char			*east_texture;
	t_rgb			*ceiling_color;
	t_rgb			*floor_color;
	int				map_height;
	int				map_width;
	char			**map;
	int				p_pos_x;
	int				p_pos_y;
	char			p_orientation;
	t_player		player;
	t_window 		*window;
}					t_data;

typedef struct helper
{
	char			*line;
	struct helper	*next;

}					t_helper;

t_data				*map_parsing(t_data *data, int fd);
int					another_content(char *str);
void				initiale_data(t_data *data);
int					handle_key(int keycode, t_data *data);
int					check_data(t_data *data);
int					is_empty_line(char *line);
void				set_colors(t_data *data, char *line);
t_rgb				*apply_colors(t_data *data, char **arr);
void				set_texture(t_data *data, char *line);
void				map_updating(char ***map, int height);
void				data_validation(t_data *data);
void				add_back(t_helper **list, char *content);
void				fill_the_array(t_helper *lst, t_data *data);
void				print_error(void);
void				clean_data(t_data *data);
void				ft_free(char **str);
void				clean_list(t_helper *envp);
void				draw_grid(char c, int i, int j, t_data *data);
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
// void				draw_player(int i, int j, t_data *data);
void				draw_map(t_data *data);
void				print_struct(t_data *data);
int					get_pixel_color(t_data *data, int x, int y);
#endif