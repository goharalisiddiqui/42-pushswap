/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 19:23:29 by gohar             #+#    #+#             */
/*   Updated: 2021/08/12 16:34:26 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_mod(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

void	ft_err(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	phfree(void *c)
{
	if (c != NULL)
		c = NULL;
}

void	ft_freesplit(char **arr)
{
	int	ind;

	ind = 0;
	while (arr[ind])
	{
		free(arr[ind]);
		ind++;
	}
	free(arr);
}
