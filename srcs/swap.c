/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uaupetit <uaupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:28:58 by uaupetit          #+#    #+#             */
/*   Updated: 2024/02/19 16:22:41 by uaupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(t_stack **lst_a)
{
	t_stack	*tmp;
	t_stack	*third;

	if (*lst_a && (*lst_a)->next)
	{
		tmp = *lst_a;
		third = (*lst_a)->next->next;
		*lst_a = (*lst_a)->next;
		(*lst_a)->next = tmp;
		(*lst_a)->next->next = third;
	}
	write(1, "sa\n", 3);
}

void	swap_b(t_stack **lst_b)
{
	t_stack	*tmp;
	t_stack	*third;

	if (*lst_b && (*lst_b)->next)
	{
		tmp = *lst_b;
		third = (*lst_b)->next->next;
		*lst_b = (*lst_b)->next;
		(*lst_b)->next = tmp;
		(*lst_b)->next->next = third;
	}
	write(1, "sb\n", 3);
}

void	swap_s(t_stack **lst_a, t_stack **lst_b)
{
	swap_a(lst_a);
	swap_b(lst_b);
	write(1, "ss\n", 3);
}
