/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:03:18 by mgayduk           #+#    #+#             */
/*   Updated: 2019/08/16 17:35:17 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <inttypes.h>

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# include "get_next_line.h"
# include "ft_printf.h"
# include "ft_btree.h"
# include "ft_getopt.h"

# define FT_DUMP_SIZE 32
# define FT_DUMP_CHUNK 8

# define FT_ABS(x) x < 0 ? -x : x
# define FT_BOOL(x) x ? 1 : 0
# define FT_TO_BYTES(x) (x >> 3)
# define FT_TO_BITS(x) (x << 3)

/*
** bit shift
*/
# define SHR(x, n) ((x) >> (n))
# define SHL(x, n) ((x) << (n))

/*
** x - value to rotate
** n - number of bit rotate to
** s - size of the value in bits
*/
# define FT_ROTL(x, n, s) (((x) << (n)) | ((x) >> ((s) - (n))))
# define FT_ROTR(x, n, s) (((x) >> (n)) | ((x) << ((s) - (n))))

# define FT_FREE_FIRST	0
# define FT_FREE_SECOND	1
# define FT_FREE_BOTH	2

# define FT_TRUE	1
# define FT_FALSE	0

typedef	char	t_bool;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_word
{
	char const		*start;
	char const		*end;
	size_t			len;
}					t_word;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstadd_back(t_list *alst, t_list *new);
void				ft_lstdel_back(t_list **alst);
void				ft_lstdel_front(t_list **alst);
size_t				ft_lstlen(t_list *alst);
t_list				*ft_lst_erase(t_list *head);

void				*ft_memset(void *destination, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, void const *src, int c, size_t n);
void				*ft_memmove(void *dst, void const *src, size_t len);
void				*ft_memchr(void const *s, int c, size_t n);
int					ft_memcmp(void const *s1, void const *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_memdump(void *ptr, size_t mem_size);
void				*ft_memcpy_rev(void *dst, const void *src, size_t n);

size_t				ft_strlen(char const *str);
char				*ft_strdup(char const *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, char const *s2);
char				*ft_strncat(char *s1, char const *s2, size_t n);
size_t				ft_strlcat(char *dst, char const *src, size_t dstsize);
char				*ft_strchr(char const *s, int c);
char				*ft_strrchr(char const *s, int c);
char				*ft_strstr(char const *haystack, char const *needle);
char				*ft_strnstr(char const *haystack,
								char const *needle, size_t len);
int					ft_strcmp(char const *s1, char const *s2);
int					ft_strncmp(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s1, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_m(char *s1, char *s2, int mode);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char	const *s, char c);
size_t				ft_word_count(char const *s, char c);
void				ft_strrev(char *str);

void				ft_clear_strarr(char ***str_arr);
size_t				ft_len_strarr(char **arr);
void				ft_put_strarr(char *const *const arr);

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_iswhite(char c);
int					ft_toupper(int c);
int					ft_tolower(int c);

intmax_t			ft_atoi(char const *str);
long long int		ft_atoi16(char const *str);
char				*ft_itoa(long long n);
char				*ft_itoa_base(intmax_t n, char base, int char_case);
char				*ft_itoa_base_unsigned(uintmax_t n, char base,
											int char_case);
char				*ft_itoa_sign(long long n);
char				*ft_itoa_abs(long long n);
char				*ft_ftoa(long double n, int precision);
char				*ft_ftoa_abs(long double n, int precision);
size_t				ft_numlen(intmax_t n);
int					ft_is_number(char *str);

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int i, int fd);

#endif
