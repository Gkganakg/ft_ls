/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 11:46:25 by gkganakg          #+#    #+#             */
/*   Updated: 2018/09/08 08:31:47 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			print_cdir(char *path)
{
	DIR				*dirp;
	struct dirent	*read;
	t_stat			buf;

	dirp = opendir(path);
	if (dirp == NULL)
		ft_printf("Not a valid file or directory\n");
	read = readdir(dirp);
	if (read->d_name[0] != '.')
		ft_names(read->d_name);
	while (read != NULL)
	{
		if (read->d_name[0] != '.')
			ft_names(read->d_name);
		read = readdir(dirp);
		stat(read->d_name, &buf);
	}
	closedir(dirp);
	sort_function(node);
	node = reverse(node);
	display_list(node);
}

static void		initialize_flags(t_fla *fla)
{
	fla->r = 0;
	fla->rr = 0;
	fla->t = 0;
	fla->a = 0;
	fla->l = 0;
	fla->d = 0;
}

void			total(char *dpath)
{
	int				total;
	DIR				*dirp;
	struct dirent	*read;
	t_stat			buf;

	total = 0;
	dirp = opendir(dpath);
	while (((read = readdir(dirp)) != NULL))
	{
		stat(read->d_name, &buf);
		if (read->d_name[0] != '.')
			total += buf.st_blocks;
	}
	ft_printf("total %d\n ", total);
}

void			print_long(char *dpath)
{
	DIR				*dirp;
	struct dirent	*read;
	t_stat			buf;
	char			*ptr;

	dirp = opendir(dpath);
	total(dpath);
	while (((read = readdir(dirp)) != NULL))
	{
		if (read->d_name[0] != '.')
		{
			stat(read->d_name, &buf);
			print_mode(buf.st_mode);
			print_permission(buf.st_mode);
			ft_printf("	%i", buf.st_nlink);
			if ((pwd = getpwuid(buf.st_uid)) != NULL)
				ft_printf("	%s", pwd->pw_name);
			if ((grp = getgrgid(buf.st_gid)) != NULL)
				ft_printf("	%s", grp->gr_name);
			ft_printf("	%lld	", (long long)buf.st_size);
			ptr = ctime(&buf.st_mtime);
			trim_time(ptr);
			ft_printf("	%s\n", read->d_name);
		}
	}
}

int				main(int ac, char **av)
{
	int		ret;
	t_fla	fla;
	char	*path;
	int		i;

	i = 0;
	initialize_flags(&fla);
	if (ac == 1)
		print_cdir(".");
	else
		check_args(ac, av, &fla);
	return (0);
}
