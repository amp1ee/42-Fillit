/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 13:49:09 by vbrazhni          #+#    #+#             */
/*   Updated: 2017/11/09 01:57:54 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);

void				ft_bzero(void *s, size_t n);

int					ft_isalnum(int c);

int					ft_isalpha(int c);

int					ft_isascii(int c);

int					ft_isblank(int c);

int					ft_isdigit(int c);

int					ft_islower(int c);

int					ft_isprint(int c);

int					ft_isspace(int c);

int					ft_isupper(int c);

char				*ft_itoa(int n);

void				ft_lstadd(t_list **alst, t_list *new);

void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));

void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

t_list				*ft_lstnew(void const *content, size_t content_size);

void				*ft_memalloc(size_t size);

void				*ft_memccpy(void *dest, const void *src, int c, size_t n);

void				*ft_memchr(const void *arr, int c, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

void				*ft_memcpy(void *dest, const void *src, size_t n);

void				ft_memdel(void **ap);

void				*ft_memmove(void *dest, const void *src, size_t n);

void				*ft_memset(void *destination, int c, size_t n);

void				ft_putchar_fd(int c, int fd);

void				ft_putchar(int c);

void				ft_putendl_fd(char const *s, int fd);

void				ft_putendl(char const *s);

void				ft_putnbr_fd(int n, int fd);

void				ft_putnbr(int n);

void				ft_putstr_fd(char const *s, int fd);

void				ft_putstr(char const *s);

char				*ft_strcat(char *dest, const char *src);

char				*ft_strchr(const char *str, int ch);

void				ft_strclr(char *s);

int					ft_strcmp(const char *str1, const char *str2);

char				*ft_strcpy(char *dest, const char *src);

void				ft_strdel(char **as);

char				*ft_strdup(char *src);

int					ft_strequ(char const *str1, char const *str2);

void				ft_striter(char *s, void (*f)(char *));

void				ft_striteri(char *s, void (*f)(unsigned int, char *));

char				*ft_strjoin(char const *s1, char const *s2);

size_t				ft_strlcat(char *dest, const char *src, size_t size);

size_t				ft_strlen(const char *str);

char				*ft_strmap(char const *s, char (*f)(char));

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char				*ft_strncat(char *dest, const char *src, size_t n);

int					ft_strncmp(const char *str1, const char *str2, size_t n);

char				*ft_strncpy(char *dest, const char *src, size_t n);

int					ft_strnequ(char const *str1, char const *str2, size_t n);

char				*ft_strnew(size_t size);

char				*ft_strnstr(const char *big,
											const char *little, size_t len);

char				*ft_strrchr(const char *str, int ch);

char				**ft_strsplit(char const *str, char c);

char				*ft_strstr(const char *big, const char *little);

char				*ft_strsub(char const *s, unsigned int start, size_t len);

char				*ft_strtrim(char const *s);

int					ft_tolower(int c);

int					ft_toupper(int c);

int					ft_abs(int number);

char				*ft_strrev(char *s);

#endif
