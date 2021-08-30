/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crunchsol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 14:40:03 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/08/12 16:30:04 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_crunch(t_list **sol)
{
	t_list	*elem;
	t_list	*nsol;

	nsol = NULL;
	elem = *sol;
	while (elem != NULL)
	{
		if (!(elem->next) || (!(!ft_strncmp((char *)elem->content, "pa", 3)
					&& !ft_strncmp((char *)elem->next->content, "pb", 3))
				 && !(!ft_strncmp((char *)elem->content, "pb", 3)
					 && !ft_strncmp((char *)elem->next->content, "pa", 3))))
		{
			ft_lstadd_back(&nsol, ft_lstnew(elem->content));
		}
		else
			elem = elem->next;
		elem = elem->next;
	}
	ft_lstclear(sol, phfree);
	*sol = nsol;
}
