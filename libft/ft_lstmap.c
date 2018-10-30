/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:34:22 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/30 18:38:42 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rm_rf(void *str, size_t amount)
{
	ft_bzero(str, amount);
	free(str);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *start;
	t_list *curr;

	if (!lst || !f || (start = (*f)(lst)) == NULL)
		return (NULL);
	lst = lst->next;
	curr = start;
	while (lst)
	{
		if (!(curr->next = (*f)(lst)))
		{
			ft_lstdel(&start, rm_rf);
		}
		curr = curr->next;
		lst = lst->next;
	}
	return (start);
}
