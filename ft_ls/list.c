/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 13:24:36 by gkganakg          #+#    #+#             */
/*   Updated: 2018/09/08 08:27:27 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		time_cmp(const char *time1, const char *time2)
{
	unsigned char	*s1;
	unsigned char	*s2;
	int				i;

	i = 0;
	s1 = (unsigned char*)time1;
	s2 = (unsigned char *)time2;
	while (s1 || s2)
	{
		if (s1[i] - s2[i] > 0)
			return (s1[i] - s2[i]);
		if (s1[i] - s2[i] < 0)
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_strdupp(char *str, char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
}

void	display_list(t_info *list)
{
	t_info *info;

	info = list;
	while (info)
	{
		ft_printf("%s\n", info->name);
		info = info->next;
	}
	ft_putchar('\n');
}

t_info	*reverse(t_info *head)
{
	t_info	*p;
	t_info	*q;
	t_info	*r;

	q = head;
	r = q->next;
	while (q != NULL)
	{
		q->next = p;
		p = q;
		q = r;
		if (r != NULL)
			r = r->next;
	}
	return (p);
}

void	ft_names(char *str)
{
	struct s_info	*tmp;
	int				ret;

	tmp = (struct s_info *)malloc(sizeof(struct s_info));
	ret = 0;
	while (str[ret])
	{
		tmp->name[ret] = str[ret];
		ret++;
	}
	tmp->name[ret] = '\0';
	tmp->next = NULL;
	if (node)
		tmp->next = node;
	node = tmp;
}
