/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beat_normm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 09:04:16 by gkganakg          #+#    #+#             */
/*   Updated: 2018/09/08 09:05:29 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		check_path(int n, char **s)
{
	int i;
	int k;

	i = 1;
	while (i < n)
	{
		if (s[i][0] == '.' || s[i][0] == '/' || s[i][0] == '~')
			return (1);
		i++;
	}
	return (0);
}

void	beat_norm(char *av, t_fla *fla)
{
	int i;
	int j;

	j = 1;
	while (av[j] != '\0')
	{
		if (is_valid(av[j] == 0))
			print_error(av[j]);
		else
			set_flags(av[j], fla);
		j++;
	}
}
