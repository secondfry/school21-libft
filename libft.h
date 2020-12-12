/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:21:31 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/03/08 02:06:09 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
** It could be that sizeof(char) is not 1 somewhere...
*/
# define DATA_MODEL_LONG_WIDTH sizeof(long) / sizeof(char)

/*
** Decimal representation of `2 ^ pow` number is at max `pow / log2 10` long
** `3 < log2 10 < 4` so we take 3 as desired delimeter
*/
# define DATA_MODEL_LONG_DECIMAL_WIDTH (sizeof(long) / sizeof(char)) * 8 / 3

/*
** Hex representation of `2 ^ pow` number is at max `pow / log2 16` long
*/
# define DATA_MODEL_LONG_HEX_WIDTH (sizeof(long) / sizeof(char)) * 2

/*
** `limits.h` are off limits, so we use our own
*/
# ifndef LONG_MIN
#  ifdef _LP64
#   define LONG_MIN 9223372036854775808U
#  else
#   define LONG_MIN 2147483648U
#  endif
# endif
# ifndef LONG_MAX
#  ifdef _LP64
#   define LONG_MAX 9223372036854775807U
#  else
#   define LONG_MAX 2147483647U
#  endif
# endif

/*
** Color defines
*/
# define COLOR_BLACK	30
# define COLOR_000		30
# define COLOR_RED		31
# define COLOR_F00		31
# define COLOR_GREEN	32
# define COLOR_0F0		32
# define COLOR_ORANGE	33
# define COLOR_FA0		33
# define COLOR_BLUE		34
# define COLOR_00F		34
# define COLOR_PURPLE	35
# define COLOR_A0A		35
# define COLOR_CYAN		36
# define COLOR_0FF		36
# define COLOR_LGRAY	37
# define COLOR_AAA		37

/*
** Including `string.h` as norminette doesn't like size_t typedef
*/
# include <string.h>

/*
** Seems like the only reasonable thing to do
*/
# define ENOMEM		12

/*
** Wonderful typedefs
*/
typedef unsigned char	t_byte;
typedef unsigned short	t_ushort;
typedef unsigned long	t_ulong;
typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

/*
** Part 1
** libc functions
*/
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(
	const char *haystack,
	const char *needle,
	size_t len
);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

/*
** Part 2
** libft functions
*/
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/*
** Bonus
** t_list functions
*/
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *elem);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** void ft_print_ptr(void *data);
** Prints `data` pointer address
*/
void			ft_print_ptr(void *data);

/*
** void ft_print_memory(const void *addr, size_t size);
** Prints `size` bytes starting from `addr` like hexdump
*/
void			ft_print_memory(const void *addr, size_t size);

/*
** void ft_print_list(t_list *root);
** Prints all the links in `root` list chain
**
** Following data is printed:
** 1. Link pointer address
** 2. Link content memory region
*/
void			ft_print_list(t_list *root);

/*
** void ft_putlong_fd(long n, int fd);
** Prints `n` as long to `fd`
*/
void			ft_putlong_fd(long n, int fd);
void			ft_putlong(long n);

/*
** void ft_putstr_color(char *str, t_byte color);
** Prints `str` as string to stdout in specified color and then clears the color
*/
void			ft_putstr_color(char *str, t_byte color);
void			ft_putchar_color(char c, t_byte color);

/*
** Other personal functions
*/
char			*ft_strrev(char *str);
char			*ft_ltoa_hex_static(long n);
char			*ft_ltoa_static(long n);
char			*ft_ltoa(long n);
int				ft_isspace(int c);
long			ft_atol(const char *str);
long			ft_strtol(const char *str, char **endptr, int base);
void			ft_ptr_check(void *ptr, char *msg, size_t args, ...);

#endif
