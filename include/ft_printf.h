/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 20:01:34 by vscabell          #+#    #+#             */
/*   Updated: 2020/04/08 10:52:16 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define DECA "0123456789"
# define HEXA_LOWER "0123456789abcdef"
# define HEXA_UPPER "0123456789ABCDEF"

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

typedef struct	s_bag
{
	int			index;
	int			zero;
	int			minus;
	int			width_star;
	int			prec_star;
	int			width;
	int			prec;
	int			dot;
	int			ret;
}				t_bag;

int				ft_printf(const char *format, ...);
void			ft_reinit_var(t_bag *bag);
void			ft_convert_type(const char *format, va_list arg, t_bag *bag);
void			ft_convert_specif(const char *format, va_list arg, t_bag *bag);
void			ft_hold_flags(const char *format, t_bag *bag);
void			ft_hold_width(const char *format, va_list arg, t_bag *bag);
void			ft_hold_prec(const char *format, va_list arg, t_bag *bag);
void			ft_print_diux(va_list arg, t_bag *bag, char *base, char c);
void			ft_print_char(va_list arg, t_bag *bag);
void			ft_print_string(va_list arg, t_bag *bag);
void			ft_print_pointer(va_list arg, t_bag *bag);
void			ft_print_percent(va_list arg, t_bag *bag);
char			*ft_check_prec(char *str, t_bag *bag);
char			*ft_check_width(char *str, t_bag *bag);
char			*ft_check_prec_int_neg(char *str, t_bag *bag);
char			*ft_check_width_int_neg(char *str, t_bag *bag);
int				ft_isdigit(char c);
int				ft_isspecifier(char c);
void			ft_putchar(char c);
void			ft_putstr(char *str);
size_t			ft_strlen(const char *s);
void			*ft_memcpy(void *dst, const void *src, int n);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char *s1, char *s2);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_calloc_char(size_t count, char c);
char			*ft_itoa_base(long long n, char *base, int size_base);
char			*ft_itoa_ptr(long long int n, char *base, int size_base);

#endif
