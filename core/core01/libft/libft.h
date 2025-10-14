/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeppe <sdeppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 13:50:06 by sdeppe            #+#    #+#             */
/*   Updated: 2025/10/12 13:50:12 by sdeppe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
#include <stddef.h>
#include <stdlib.h>

int 	ft_isalpha(int c);
void 	ft_bzero(void *s, size_t n);
int 	ft_isalnum(int c);
int 	ft_isascii(int c);
int 	ft_isdigit(int c);
int 	ft_isprint(int c);
void *	ft_memcpy(void *dest, const void *src, size_t n);
void *	ft_memmove(void *dest, const void *src, size_t n);
void *	ft_memset(void *s, int c, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t 	ft_strlen(const char *s);
int 	ft_toupper(int c);
int 	ft_tolower(int c);

#endif
