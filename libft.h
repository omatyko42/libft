/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatyko <omatyko@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:24:45 by omatyko           #+#    #+#             */
/*   Updated: 2025/03/10 12:19:14 by omatyko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef unsigned char	t_uchar;

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}						t_list;

void					*ft_calloc(size_t count, size_t size);
void					ft_bzero(void *s, size_t n);
void					*ft_memset(void *s, int c, size_t n);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					*ft_memmove(void *dest, const void *src, size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
char					*ft_strdup(const char *s1);
size_t					ft_strlen(const char *s);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_substr(char const *s, unsigned int start,
							size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s1, char const *set);
char					**ft_split(char const *s, char c);
char					*ft_strmapi(char const *s, char (*f)(unsigned int,
								char));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t					ft_strlcpy(char *dest, const char *src, size_t size);
size_t					ft_strlcat(char *dest, const char *src, size_t size);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					*ft_itoa(int n);
char					*ft_strnstr(const char *haystack, const char *needle,
							size_t len);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_tolower(int c);
int						ft_toupper(int c);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char *s, int fd);
void					ft_putendl_fd(char *s, int fd);
void					ft_putnbr_fd(int n, int fd);
int						ft_atoi(const char *str);
t_list					*ft_lstnew(void *content);
void					ft_lstadd_front(t_list **lst, t_list *new);
int						ft_lstsize(t_list *lst);
t_list					*ft_lstlast(t_list *lst);
void					ft_lstadd_back(t_list **lst, t_list *new);
void					ft_lstdelone(t_list *lst, void (*del)(void *));
void					ft_lstclear(t_list **lst, void (*del)(void *));
t_list					*ft_lstmap(t_list *lst, void *(*f)(void *),
							void (*del)(void *));
void					ft_lstiter(t_list *lst, void (*f)(void *));

// long				ft_strtol(const char *nptr, char **endptr, int base);

/*Printf block*/
int						print_non_def_prefix(const char *str);
int						is_alpha(const char *str);
int						is_prefix(const char *str);
int						prn_ptr(uintptr_t num, char *prefix);
int						prn_char(char c);
int						prn_str(const char *str);
int						prn_u_hex(unsigned int num, unsigned int base,
							char upper);
int						prn_nbr(int num);
int						ft_printf(const char *str, ...);

void					*ft_free(void **ptr);
int						ft_is_spaces(const char *arg);

char					*get_next_line(int fd);
void					free_get_next_line(int fd);
void					free_line_close_fd(int fd, char *str);

int						ft_atoi_base(const char *str, const char *base);
int						ft_min(int a, int b);
int						ft_max(int a, int b);
int						ft_abs(int a);

#endif
