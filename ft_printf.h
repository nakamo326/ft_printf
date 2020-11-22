/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot <ynakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 09:25:35 by ynakamot          #+#    #+#             */
/*   Updated: 2020/11/17 11:14:37 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# define ERROR -1
# define EOS -3

typedef struct	s_flags
{
	bool	zero;
	bool	minus;
	int		width;
	bool	dot;
	int		prec;

}				t_flags;

int				ft_printf(const char *format, ...);
int				ft_vprintf(char *fmt, va_list ap);
int				parse_format(t_flags *s, char **ptr, va_list ap);
void			init_tflags(t_flags *s);
char			*check_flags(t_flags *s, char *ptr);
char			*check_width(t_flags *s, char *ptr, va_list ap);
char			*check_precision(t_flags *s, char *ptr, va_list ap);
int				switch_output(t_flags *s, char *ptr, va_list ap);
int				output_pct(t_flags s);
int				output_char(t_flags s, va_list ap);
int				output_string(t_flags s, va_list ap);
int				output_integer(t_flags s, va_list ap);
int				switch_unsigned(t_flags s, va_list ap, char c);
int				output_uint_base(t_flags s, va_list ap, const char *base);
int				output_pointer(t_flags s, va_list ap, const char *base);
int				ft_putchar_re(char c);
int				ft_putstr_re(char *str);
char			*treat_prec(t_flags s, char *str, int n);
int				treat_width(t_flags s, int len);
int				treat_leftjustify(t_flags s, int len);

#endif
