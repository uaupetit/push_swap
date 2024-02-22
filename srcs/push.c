/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uaupetit <uaupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:32:59 by uaupetit          #+#    #+#             */
/*   Updated: 2024/02/19 16:22:41 by uaupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a(t_stack **lst_a, t_stack **lst_b)
{
	t_stack	*temp;

	if (*lst_b != NULL)
	{
		temp = *lst_b;
		*lst_b = (*lst_b)->next;
		temp->next = *lst_a;
		*lst_a = temp;
	}
	write(1, "pa\n", 3);
}

void	push_b(t_stack **lst_a, t_stack **lst_b)
{
	t_stack	*temp;

	if (*lst_a != NULL)
	{
		temp = *lst_a;
		*lst_a = (*lst_a)->next;
		temp->next = *lst_b;
		*lst_b = temp;
	}
	write(1, "pb\n", 3);
}
