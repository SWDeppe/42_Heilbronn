/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeppe <sdeppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 08:10:23 by sdeppe            #+#    #+#             */
/*   Updated: 2025/10/28 23:34:52 by sdeppe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*buf;
	t_list	*first;
	void	*new;

	if (!lst)
		return (NULL);
	first = NULL;
	while (lst)
	{
		new = f(lst->content);
		buf = ft_lstnew(new);
		if (buf == NULL)
		{
			(*del)((void *)new);
			ft_lstclear(&first, del);
			return (NULL);
		}
		ft_lstadd_back(&first, buf);
		lst = lst->next;
	}
	return (first);
}
