/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeppe <sdeppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 12:30:45 by sdeppe            #+#    #+#             */
/*   Updated: 2025/11/16 00:19:50 by sdeppe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "ft_bool.h"
# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

# define TYPES char

// types for the struct define some number that represente all different types
// TODO use enums
# define _PERCENT_ '%'
# define _CHARACTER_ 'c'
# define _STRING_ 's'
# define _POINTER_ 'p'
# define _DECIMAL_ 'd'
# define _INTEGER_ 'i'
# define _UINTEGER_ 'u'
# define _HEXA_ 'x'
# define _HEXA_MAJ_ 'X'

/******************************    structs     ********************************/

typedef struct s_pars {
	int		with;
	_BOOL_	is_prec;
	int		precision;

	_BOOL_	zero;
	_BOOL_	invert;
	_BOOL_	space;
	_BOOL_	plus;
	_BOOL_	see_hex;

	TYPES	type;
}			t_pars;

/******************************   prototypes   ********************************/

int		ft_printf( const char *format, ...);
t_pars	pars(const char *format, int *i);
int		render_integer(t_pars *p, int nbr);
int		render_uinteger(t_pars *parser, unsigned int nbr);
int		render_hexa(t_pars *parser, int nbr);
int		render_hexa_maj(t_pars *parser, int nbr);
int		render_character(t_pars *parser, int c);
int		render_string(t_pars *parser, char *str);
int		ft_renderer(t_pars parser, va_list ap);
int		print_wis_with(t_pars *parser, char *str);

#endif