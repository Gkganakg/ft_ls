/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 13:35:45 by gkganakg          #+#    #+#             */
/*   Updated: 2018/09/08 08:31:40 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_storage(char *str, char *tmp)
{
	struct s_info	*hlder;
	int				ret;

	hlder = (struct s_info *)malloc(sizeof(struct s_info));
	ret = 0;
	while (str[ret])
	{
		hlder->name[ret] = str[ret];
		ret++;
	}
	hlder->name[ret] = '\0';
	ret = 0;
	while (tmp[ret])
	{
		hlder->date[ret] = tmp[ret];
		ret++;
	}
	hlder->date[ret] = '\0';
	hlder->next = NULL;
	if (node)
		hlder->next = node;
	node = hlder;
}

void	sort_function(t_info *list)
{
	t_info	*i;
	t_info	*j;
	char	t[50];

	i = list;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if (time_cmp(i->name, j->name) < 0)
			{
				ft_strdupp(t, i->name);
				ft_strdupp(i->name, j->name);
				ft_strdupp(j->name, t);
			}
			j = j->next;
		}
		i = i->next;
	}
}
