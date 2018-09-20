/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_permission.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 07:07:28 by gkganakg          #+#    #+#             */
/*   Updated: 2018/09/05 07:26:58 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/stat.h>

void	print_permission(mode_t file_mode)
{
	(file_mode & S_IRUSR) ? ft_putchar('r') : ft_putchar('-');
	(file_mode & S_IWUSR) ? ft_putchar('w') : ft_putchar('-');
	if (file_mode & S_ISUID)
		(file_mode & S_IXUSR) ? ft_putchar('s') : ft_putchar('S');
	else
		(file_mode & S_IXUSR) ? ft_putchar('x') : ft_putchar('-');
	(file_mode & S_IRGRP) ? ft_putchar('r') : ft_putchar('-');
	(file_mode & S_IWGRP) ? ft_putchar('w') : ft_putchar('-');
	if (file_mode & S_ISGID)
		(file_mode & S_IXGRP) ? ft_putchar('s') : ft_putchar('S');
	else
		(file_mode & S_IXGRP) ? ft_putchar('x') : ft_putchar('-');
	(file_mode & S_IROTH) ? ft_putchar('r') : ft_putchar('-');
	(file_mode & S_IWOTH) ? ft_putchar('w') : ft_putchar('-');
	if (file_mode & S_ISVTX)
		(file_mode & S_IXOTH) ? ft_putchar('t') : ft_putchar('T');
	else
		(file_mode & S_IXOTH) ? ft_putchar('x') : ft_putchar('-');
	ft_putstr("  ");
}
