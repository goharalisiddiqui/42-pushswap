/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkinput.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:44:13 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/08/12 16:20:51 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_seen(char **arr, int ind)
{
	int	i;

	i = 0;
	while (i < ind)
	{
		if (ft_atoi(arr[ind]) == ft_atoi(arr[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	ft_isinteger(char *str)
{
	long long	num;

	num = ft_atol(str);
	if (ft_strlen(str) > 11)
		return (0);
	if (*str == '-')
		str++;
	if (ft_strlen(str) > 11 || ft_strlen(str) < 1)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}

static int	ft_checkarg(char **argv)
{
	char	**arr;
	int		ind;

	ind = 0;
	arr = ft_multisplit(argv[1], " \t");
	while (arr[ind] != NULL)
	{
		if (!ft_isinteger(arr[ind]) || ft_seen(arr, ind))
		{
			ft_freesplit(arr);
			return (0);
		}
		ind++;
	}
	ft_freesplit(arr);
	return (ind);
}

int	ft_checkinput(int argc, char **argv)
{
	int		ind;

	if (argc == 2)
		return (ft_checkarg(argv));
	ind = 1;
	while (ind < argc)
	{
		if (!ft_isinteger(argv[ind]) || ft_seen(argv + 1, ind - 1))
			return (0);
		ind++;
	}
	return (argc - 1);
}
