/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 09:31:38 by gkganakg          #+#    #+#             */
/*   Updated: 2018/09/07 15:16:16 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_all(char *dpath)
{
	DIR				*dirp;
	struct dirent	*read;
	t_stat			buf;

	dirp = opendir(dpath);
	if (dirp == NULL)
		return ;
	read = readdir(dirp);
	ft_names(read->d_name);
	read = readdir(dirp);
	while (read != NULL)
	{
		ft_names(read->d_name);
		read = readdir(dirp);
		stat(read->d_name, &buf);
	}
	sort_function(node);
	node = reverse(node);
	display_list(node);
}

void	print_rev(char *dpath)
{
	DIR				*dirp;
	struct dirent	*read;
	t_stat			buf;
	char			*str;
	char			*tmp;

	str = NULL;
	dirp = opendir(dpath);
	read = readdir(dirp);
	stat(read->d_name, &buf);
	tmp = ctime(&buf.st_ctime);
	str = print_time(tmp);
	if (read->d_name[0] != '.')
		ft_storage(read->d_name, str);
	while (read != NULL)
	{
		read = readdir(dirp);
		stat(read->d_name, &buf);
		tmp = ctime(&buf.st_ctime);
		str = print_time(tmp);
		if (read != NULL && read->d_name[0] != '.')
			ft_storage(read->d_name, str);
	}
	sort_function(node);
	display_list(node);
}

void	time_sort(char *dpath)
{
	DIR				*dirp;
	struct dirent	*read;
	t_stat			buf;
	char			*str;
	char			*tmp;

	str = NULL;
	dirp = opendir(dpath);
	read = readdir(dirp);
	stat(read->d_name, &buf);
	tmp = ctime(&buf.st_ctime);
	str = print_time(tmp);
	if (read->d_name[0] != '.')
		ft_storage(read->d_name, str);
	while (read != NULL)
	{
		read = readdir(dirp);
		stat(read->d_name, &buf);
		tmp = ctime(&buf.st_ctime);
		str = print_time(tmp);
		if (read != NULL && read->d_name[0] != '.')
			ft_storage(read->d_name, str);
	}
	sort_function(node);
	display_list(node);
}
