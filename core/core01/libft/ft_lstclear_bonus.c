/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeppe <sdeppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 06:09:40 by sdeppe            #+#    #+#             */
/*   Updated: 2025/10/28 23:31:11 by sdeppe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*before;

	if (!*lst)
		return ;
	current = *lst;
	while (current)
	{
		(*del)((void *)current->content);
		before = current;
		current = current->next;
		free(before);
	}
	*lst = NULL;
}
