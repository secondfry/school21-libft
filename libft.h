/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:21:31 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/04/25 16:26:07 by oadhesiv         ###   ########.fr       */
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
** Including `string.h` as norminette doesn't like size_t typedef
*/
# include <string.h>

/*
** Wonderful typedefs
*/
typedef unsigned char	t_byte;
typedef unsigned long	t_ulong;

/*
** Part 1
*/
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strncat(char *s1, const char *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *haystack, const char *needle);

int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

/*
** Part 2
*/
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);
char	*ft_itoa(int n);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putendl(char const *s);
void	ft_putnbr(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/*
** Bonus
*/

/*
** Personal functions
*/
void	ft_print_memory(const void *addr, size_t size);
char	*ft_strrev(char *str);
char	*ft_ltoa_hex_static(long n);
char	*ft_ltoa_static(long n);
char	*ft_ltoa(long n);
void	ft_putlong_fd(long n, int fd);
void	ft_putlong(long n);
int		ft_isspace(int c);
long	ft_atol(const char *str);
long	ft_strtol(const char *str, char **endptr, int base);

#endif
