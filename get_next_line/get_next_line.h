/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:39:10 by shebaz            #+#    #+#             */
/*   Updated: 2025/02/04 10:14:13 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

char	*ft_strjoin(char *dest, char *src);
int		ft_lenght(const char *str);
int		check_new_line(char *ptr);
char	*ft_update(char *next_line);
char	*ft_read(char *next_line, int fd);
char	*extract_line(char *next_line);
char	*get_next_line(int fd);
int		until_newline(const char *str);
#endif
