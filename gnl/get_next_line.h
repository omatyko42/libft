/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatyko <omatyko@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 01:14:04 by omatyko           #+#    #+#             */
/*   Updated: 2025/03/11 13:48:17 by omatyko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# else
#  if BUFFER_SIZE > 8000000
#   undef BUFFER_SIZE
#   define BUFFER_SIZE 8000000
#  endif
# endif

char	*get_next_line(int fd);
size_t	ft_strlen_gnl(const char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strichr_gnl(const char *s, int c);
char	*cut_line(char **storage, int newline_index);
void	free_get_next_line(int fd);
void	free_line_close_fd(int fd, char *str);
int		free_get_next_line_on_error(int fd, char *line);
#endif
