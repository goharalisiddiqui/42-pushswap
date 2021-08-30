/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 18:39:54 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/08/12 16:21:37 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	ft_readorder(t_stack *ha)
{
	int		flag;
	t_stack	*elem;
	t_stack	*elem2;
	int		ord;

	flag = ha->prev->val;
	elem = ha;
	while (1)
	{
		elem2 = ha;
		ord = 1;
		while (1)
		{
			if (elem2->val < elem->val)
				ord++;
			if (elem2->val == flag)
				break ;
			elem2 = elem2->next;
		}
		elem->order = ord;
		if (elem->val == flag)
			break ;
		elem = elem->next;
	}
}

void	ft_initialize(t_stack **ha, int n, char **argv, int argc)
{
	int	i;

	if (argc == 2)
		argv = ft_multisplit(argv[1], " \t");
	else
		argv++;
	i = 0;
	while (i < n)
	{
		ft_addtostack(ha, ft_stacknew(ft_atoi(argv[i]), 0));
		i++;
	}
	ft_readorder(*ha);
	if (argc == 2)
	{
		i = 0;
		while (argv[i])
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
}
