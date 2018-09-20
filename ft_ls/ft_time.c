/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 09:42:33 by gkganakg          #+#    #+#             */
/*   Updated: 2018/09/08 08:28:57 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		save_lines(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	return (i);
}

void	*print_time(char *timed)
{
	char	*tmp;
	int		ind;
	int		colon;
	int		ret;

	tmp = NULL;
	colon = 2;
	ret = 0;
	ind = save_lines(timed);
	ind++;
	tmp = &timed[ind];
	while (timed[ind++])
	{
		if (timed[ind] == ':')
			colon--;
		if (colon != 0)
			ret++;
	}
	timed[ind] = '\0';
	tmp[ret + 3] = '\0';
	return (tmp);
}

char	*trim_time(char *timed)
{
	char	*tmp;
	int		ind;
	int		colon;
	int		ret;

	tmp = NULL;
	ret = 0;
	colon = 2;
	ind = save_lines(timed);
	ind++;
	tmp = &timed[ind];
	while (timed[ind])
	{
		if (timed[ind] == ':')
			colon--;
		if (colon != 0)
		{
			ft_printf("%c", timed[ind]);
			ret++;
		}
		ind++;
	}
	timed[ind] = '\0';
	tmp[ret + 3] = '\0';
	return (tmp);
}
