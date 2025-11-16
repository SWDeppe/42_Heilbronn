/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeppe <sdeppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:32:19 by sdeppe            #+#    #+#             */
/*   Updated: 2025/11/15 23:23:47 by sdeppe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf( const char *format, ...)
{
	int		ret;
	int		i;
	va_list	args_p;
	t_pars	parser;

	ret = 0;
	i = 0;
	va_start(args_p, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			parser = pars(format, &i);
			ret += ft_renderer(parser, args_p);
		}
		else
			ret += write(1, &format[i], 1);
		i++;
	}	
	va_end(args_p);
	return (ret);
}
