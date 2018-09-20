/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 14:27:57 by gkganakg          #+#    #+#             */
/*   Updated: 2018/09/08 10:17:04 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_valid(char c)
{
	if (c != 'r' && c != 'R' && c != 't' && c != 'l' && c != 'a' && c != '-')
		return (0);
	return (1);
}

void	set_flags(char c, t_fla *fla)
{
	fla->r = (c == 'r' ? 1 : fla->r);
	fla->rr = (c == 'R' ? 1 : fla->rr);
	fla->t = (c == 't' ? 1 : fla->t);
	fla->l = (c == 'l' ? 1 : fla->l);
	fla->a = (c == 'a' ? 1 : fla->a);
	fla->d = (c == '-' ? 1 : fla->d);
}

void	print_error(char c)
{
	ft_printf("ft_ls: illegal option -- %c\n", c);
	ft_printf("usage: ./ft_ls [-Ralrt] [file ...]\n");
	exit(1);
}

void	save(char *av, t_fla fla)
{
	t_stat	buf;

	if (lstat(av, &buf) == 0)
	{
		if (fla.a == 1)
			print_all(av);
		else if (fla.l == 1)
			print_long(av);
		else if (fla.r == 1)
			print_rev(av);
		else if (fla.t == 1)
			time_sort(av);
		else if (fla.rr == 1)
		{
			ft_printf("WARNING !!!! Didint cater for it\n");
			return ;
		}
		else
			print_cdir(av);
	}
	else
		ft_printf("ft_ls: %s: Not such file or  directory\n", av);
}

void	check_args(int ac, char **av, t_fla *fla)
{
	int i;
	int j;
	int k;

	k = check_path(ac, av);
	i = 0;
	while (++i < ac)
	{
		if (av[i][0] == '-' && av[i][1] != '\0')
		{
			if (!is_valid(av[i][1]) && av[i][2] == '\0')
				print_error(av[i][1]);
			else if (av[i][1] == '-' && av[i][2] != '\0')
				print_error(av[i][2]);
			else if (av[i][1] != '\0')
				beat_norm(av[i], fla);
		}
		else if (av[i][0] != '-' && k == 0)
		{
			ft_printf("ft_ls: %s: Not such file or  directory\n", av[i]);
			return ;
		}
		if (k == 0)
			av[i] = ".";
		if ((av[i][0] == '.' || av[i][0] == '~' || av[i][0] == '/') \
				&& av[i])
			save(av[i], *fla);
	}
}
