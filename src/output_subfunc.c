/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_subfunc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot <ynakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 22:01:28 by ynakamot          #+#    #+#             */
/*   Updated: 2020/11/17 11:13:50 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar_re(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int		ft_putstr_re(char *str)
{
	if (str)
	{
		ft_putstr_fd(str, 1);
		return (ft_strlen(str));
	}
	return (0);
}

char	*treat_prec(t_flags s, char *str, int n)
{
	int		i;
	char	*tmp;

	i = 0;
	if (s.dot == true && s.prec > (int)ft_strlen(str))
	{
		while (i < (int)(s.prec - ft_strlen(str)))
		{
			tmp = str;
			if (!(str = ft_strjoin("0", str)))
				return (NULL);
			free(tmp);
		}
	}
	if (s.dot == true && s.prec == 0 && n == 0)
		str[0] = '\0';
	return (str);
}

int		treat_width(t_flags s, int len)
{
	int i;

	i = 0;
	while (s.minus == false && len < s.width)
	{
		if (s.dot == true || s.zero == false)
			len += ft_putstr_re(" ");
		else
			len += ft_putstr_re("0");
		i++;
	}
	return (i);
}

int		treat_leftjustify(t_flags s, int len)
{
	int i;

	i = 0;
	if (s.minus == true)
	{
		while (len < s.width)
		{
			len += ft_putstr_re(" ");
			i++;
		}
	}
	return (i);
}
