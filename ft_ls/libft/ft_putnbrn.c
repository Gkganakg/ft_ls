/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 09:19:29 by gkganakg          #+#    #+#             */
/*   Updated: 2018/08/29 13:32:22 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_numlen(int num)
{
	int i;

	i = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		i++;
		num /= 10;
	}
	return (i);
}

void	ft_putnnbr(int num, int size)
{
	int i;

	i = size - ft_numlen(num);
	while (i > 0)
		ft_putchar(' ');
	ft_putnbr(num);
}
