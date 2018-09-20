/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algn_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 11:08:34 by gkganakg          #+#    #+#             */
/*   Updated: 2018/08/27 11:45:48 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_align_str(char *str, int num)
{
	int i;
	int j;

	i = ft_strlen(str);
	j = num - i;
	ft_putstr(str);
	while (i-- > 0)
		ft_putchar(' ');
}
