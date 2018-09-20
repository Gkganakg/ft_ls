/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 16:12:50 by gkganakg          #+#    #+#             */
/*   Updated: 2018/09/08 10:19:30 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_by(t_list **lst, t_list *new, int (*order)(t_list *, \
			t_list *), int ret)
{
	t_list *cur;

	if (*order == NULL || ret == 0)
		ft_ladd_bak(lst, new);
	else if (*lst == NULL || (*order)(new, *lst) == ret)
	{
		new->next = *lst;
		*lst = new;
	}
	else
	{
		cur = *lst;
		while (cur->next != NULL && (*order)(cur->next, new) == ret)
			cur = cur->next;
		new->next = cur->next;
		cur->next = new;
	}
}

/*
**  ft_lstaddback adds a t_list* node 'new' to a t_list** list 'lst'
**  If lst is NULL ft_ladd_back does nothin
*/

void	ft_ladd_bak(t_list **lst, t_list *new)
{
	if (lst != NULL)
	{
		if (*lst == NULL)
			*lst = new;
		else if ((*lst)->next == NULL)
			(*lst)->next = new;
		else
			return (ft_ladd_bak(&(*lst)->next, new));
	}
}
