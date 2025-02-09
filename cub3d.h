/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:12:50 by shebaz            #+#    #+#             */
/*   Updated: 2025/02/09 12:01:52 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line/get_next_line.h"
# include "Libft/libft.h"
# include "Minilibx-linux/mlx.h"
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
// # define ESC 27
// # define whitespace 32

typedef struct rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct data
{
	char			*north_texture;
	char			*south_texture;
	char			*west_texture;
	char			*east_texture;
	t_rgb			*ceiling_color;
	t_rgb			*floor_color;
	int				map_height;
	char			**map;
}					t_data;

typedef struct helper
{
	char			*line;
	struct helper	*next;

}					t_helper;

t_data				*map_parsing(t_data *data);
int					another_content(char *str);
void				initiale_data(t_data *data);
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
#endif