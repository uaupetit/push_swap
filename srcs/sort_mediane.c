/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mediane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uaupetit <uaupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:08:08 by uaupetit          #+#    #+#             */
/*   Updated: 2024/02/19 16:22:41 by uaupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	under_mediane(t_stack **lst_a, t_stack **lst_b)
{
	int	i;
	int	size;
	int	mediane;

	i = 0;
	size = ft_lstsize(*lst_a);
	mediane = find_mediane(*lst_a);
	while (i < size)
	{
		if ((*lst_a)->content < mediane)
		{
			push_b(lst_a, lst_b);
		}
		else if ((*lst_a)->content >= mediane)
		{
			rotate_a(lst_a);
		}
		i++;
	}
}

void	upper_mediane(t_stack **lst_a, t_stack **lst_b)
{
	int	size;
	int	highest;

	highest = highest_value(*lst_a);
	size = ft_lstsize(*lst_a);
	while (size != 1)
	{
		if ((*lst_a)->content != highest)
		{
			push_b(lst_a, lst_b);
			size--;
		}
		else
			rotate_a(lst_a);
	}
}
