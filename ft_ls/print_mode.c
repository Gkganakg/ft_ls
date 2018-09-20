/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 07:08:43 by gkganakg          #+#    #+#             */
/*   Updated: 2018/09/07 08:53:14 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/types.h>
#include <sys/stat.h>

void	print_mode(mode_t mode)
{
	if (S_ISBLK(mode))
		ft_putchar('b');
	if (S_ISCHR(mode))
		ft_putchar('c');
	if (S_ISDIR(mode))
		ft_putchar('d');
	if (S_ISLNK(mode))
		ft_putchar('l');
	if (S_ISSOCK(mode))
		ft_putchar('s');
	if (S_ISFIFO(mode))
		ft_putchar('p');
	if (S_ISREG(mode))
		ft_putchar('-');
}
