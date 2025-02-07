#ifndef CUB3D_H
#define CUB3D_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <math.h>
# include <unistd.h>
# include <dirent.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stddef.h>

# define W 87
# define A 65
# define S 83
# define D 68
// # define ESC 27
// # define whitespace 32 

typedef struct rgb
{
	int r;
	int g;
	int b;
}t_rgb;

typedef struct data
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	t_rgb	*ceiling_color;
	t_rgb	*Floor_color;	
	int		map_height;
	char	**map;
} t_data;


t_data  *map_parsing(t_data *data);
int     another_content(char *str);
void    initiale_data(t_data *data);
int     check_data(t_data *data);
int     is_empty_line(char *line);
void    set_colors(t_data *data, char *line);
t_rgb   *apply_colors(char **arr);
void    set_texture(t_data *data, char *line);
int		ft_counter(char *line);
#endif