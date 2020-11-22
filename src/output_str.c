/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot <ynakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:18:31 by ynakamot          #+#    #+#             */
/*   Updated: 2020/11/16 01:52:35 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		output_pct(t_flags s)
{
	int	len;

	len = 1;
	len += treat_width(s, len);
	ft_putchar_fd('%', 1);
	len += treat_leftjustify(s, len);
	return (len);
}

int		output_char(t_flags s, va_list ap)
{
	char	c;
	int		len;

	len = 1;
	c = (char)va_arg(ap, int);
	len += treat_width(s, len);
	ft_putchar_fd(c, 1);
	len += treat_leftjustify(s, len);
	return (len);
}

int		output_string(t_flags s, va_list ap)
{
	char	*str;
	int		len;

	if (!(str = va_arg(ap, char *)))
		str = ft_strdup("(null)");
	else
		str = ft_strdup(str);
	if (!str)
		return (ERROR);
	if (s.dot == true && s.prec < (int)ft_strlen(str))
		str[s.prec] = '\0';
	len = (int)ft_strlen(str);
	len += treat_width(s, len);
	ft_putstr_fd(str, 1);
	len += treat_leftjustify(s, len);
	free(str);
	return (len);
}
