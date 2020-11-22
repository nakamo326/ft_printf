/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot <ynakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:49:34 by ynakamot          #+#    #+#             */
/*   Updated: 2020/11/17 11:13:53 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	if (!format)
		return (ERROR);
	va_start(ap, format);
	ret = ft_vprintf((char *)format, ap);
	va_end(ap);
	return (ret);
}

int		ft_vprintf(char *fmt, va_list ap)
{
	t_flags	s;
	char	*tmp;
	int		len;
	int		ret;

	len = 0;
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			tmp = fmt;
			if ((ret = parse_format(&s, &fmt, ap)) == ERROR)
				return (ERROR);
			if (ret == EOS)
			{
				ret = ft_putstr_re(tmp);
				return (len + ret);
			}
			len += ret;
			fmt++;
			continue;
		}
		len += ft_putchar_re(*fmt++);
	}
	return (len);
}

int		switch_output(t_flags *s, char *ptr, va_list ap)
{
	if (*ptr == '%')
		return (output_pct(*s));
	if (*ptr == 'c')
		return (output_char(*s, ap));
	if (*ptr == 's')
		return (output_string(*s, ap));
	if (*ptr == 'd' || *ptr == 'i')
		return (output_integer(*s, ap));
	if (*ptr == 'u' || *ptr == 'x' || *ptr == 'X' || *ptr == 'p')
		return (switch_unsigned(*s, ap, *ptr));
	return (ERROR);
}
