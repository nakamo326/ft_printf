/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot <ynakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 13:41:38 by ynakamot          #+#    #+#             */
/*   Updated: 2020/11/22 10:00:00 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		switch_unsigned(t_flags s, va_list ap, char c)
{
	const char decimal[11] = "0123456789";
	const char hexlower[17] = "0123456789abcdef";
	const char hexupper[17] = "0123456789ABCDEF";

	if (c == 'u')
		return (output_uint_base(s, ap, decimal));
	if (c == 'x')
		return (output_uint_base(s, ap, hexlower));
	if (c == 'X')
		return (output_uint_base(s, ap, hexupper));
	if (c == 'p')
		return (output_pointer(s, ap, hexlower));
	return (ERROR);
}

int		output_uint_base(t_flags s, va_list ap, const char *base)
{
	char			*str;
	int				len;
	unsigned int	n;

	n = va_arg(ap, unsigned int);
	if (!(str = ft_lltoa_base(n, (char *)base)))
		return (ERROR);
	str = treat_prec(s, str, n);
	len = ft_strlen(str);
	len += treat_width(s, len);
	ft_putstr_fd(str, 1);
	len += treat_leftjustify(s, len);
	free(str);
	return (len);
}

int		output_pointer(t_flags s, va_list ap, const char *base)
{
	unsigned long long	n;
	char				*str;
	int					len;

	n = (unsigned long long)va_arg(ap, void *);
	if (!(str = ft_lltoa_base(n, (char *)base)))
		return (ERROR);
	str = treat_prec(s, str, n);
	len = ft_strlen(str);
	if (s.dot == false && s.minus == false && s.zero == true)
		len += ft_putstr_re("0x");
	if (s.dot == true || s.minus == true || s.zero == false)
	{
		len += treat_width(s, len + 2);
		len += ft_putstr_re("0x");
	}
	else
		len += treat_width(s, len);
	ft_putstr_fd(str, 1);
	len += treat_leftjustify(s, len);
	free(str);
	return (len);
}
