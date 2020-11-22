/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot <ynakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:26:23 by ynakamot          #+#    #+#             */
/*   Updated: 2020/11/21 15:52:24 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_format(t_flags *s, char **ptr, va_list ap)
{
	int ret;

	(*ptr)++;
	init_tflags(s);
	*ptr = check_flags(s, *ptr);
	*ptr = check_width(s, *ptr, ap);
	*ptr = check_precision(s, *ptr, ap);
	if (**ptr == '\0')
		return (EOS);
	if ((ret = switch_output(s, *ptr, ap)) == ERROR)
		return (ERROR);
	return (ret);
}

void	init_tflags(t_flags *s)
{
	s->zero = false;
	s->minus = false;
	s->width = 0;
	s->prec = 0;
	s->dot = false;
}

char	*check_flags(t_flags *s, char *ptr)
{
	if (!ptr)
		return (NULL);
	while (*ptr == '0' || *ptr == '-')
	{
		if (*ptr == '0')
			s->zero = true;
		if (*ptr == '-')
			s->minus = true;
		ptr++;
	}
	return (ptr);
}

char	*check_width(t_flags *s, char *ptr, va_list ap)
{
	int	n;

	if (!ptr)
		return (NULL);
	while (*ptr >= '0' && *ptr <= '9')
		s->width = s->width * 10 + (*ptr++ - '0');
	if (*ptr == '*')
	{
		n = va_arg(ap, int);
		s->width = ft_abs(n);
		if (n < 0)
			s->minus = true;
		ptr++;
	}
	return (ptr);
}

char	*check_precision(t_flags *s, char *ptr, va_list ap)
{
	if (!ptr)
		return (NULL);
	if (*ptr != '.')
		return (ptr);
	s->dot = true;
	ptr++;
	while (*ptr >= '0' && *ptr <= '9')
		s->prec = s->prec * 10 + (*ptr++ - '0');
	if (*ptr == '*')
	{
		s->prec = va_arg(ap, int);
		if (s->prec < 0)
		{
			s->dot = false;
			s->prec = 0;
		}
		ptr++;
	}
	return (ptr);
}
