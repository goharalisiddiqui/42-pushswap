/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hfuncs2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gohar <gohar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:27:03 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/07/31 18:24:36 by gohar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf_mfwcalc_qm(char *flags, int *laf, int *zpf)
{
	*laf = 0;
	*zpf = 0;
	while (*flags && (*flags != '.'))
	{
		if (*flags == '-')
			*laf = 1;
		else if (*flags == '0')
			*zpf = 1;
		else if (ft_isdigit(*flags))
			return (ft_atoi(flags));
		flags++;
	}
	return (0);
}

int	ft_chrlen(char *str)
{
	int	count;

	count = 1;
	while (*str)
	{
		if (*str == ' ')
			count++;
		str++;
	}
	return (count);
}
