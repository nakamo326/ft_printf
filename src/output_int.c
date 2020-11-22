/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot <ynakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 10:57:36 by ynakamot          #+#    #+#             */
/*   Updated: 2020/11/17 11:12:06 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		output_integer(t_flags s, va_list ap)
{
	char	*str;
	long	n;
	int		len;

	n = (long)va_arg(ap, int);
	str = ft_ltoa(ft_abs(n));
	str = treat_prec(s, str, n);
	len = ft_strlen(str);
	if (n < 0 && s.dot == false && s.minus == false && s.zero == true)
		len += ft_putstr_re("-");
	if (n < 0 && (s.dot == true || s.minus == true || s.zero == false))
	{
		len += treat_width(s, len + 1);
		len += ft_putstr_re("-");
	}
	else
		len += treat_width(s, len);
	ft_putstr_fd(str, 1);
	len += treat_leftjustify(s, len);
	free(str);
	return (len);
}
