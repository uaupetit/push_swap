/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uaupetit <uaupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:20:17 by uaupetit          #+#    #+#             */
/*   Updated: 2024/02/19 16:43:25 by uaupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/checker.h"

void	rotate_a_bis(t_stack **lst_a)
{
	t_stack	*temp;
	t_stack	*last;

	if (ft_lstsize(*lst_a) > 1)
	{
		temp = *lst_a;
		last = ft_lstlast(*lst_a);
		last->next = temp;
		*lst_a = (*lst_a)->next;
		temp->next = NULL;
	}
}

void	rotate_b_bis(t_stack **lst_b)
{
	t_stack	*temp;
	t_stack	*last;

	if (ft_lstsize(*lst_b) > 1)
	{
		temp = *lst_b;
		last = ft_lstlast(*lst_b);
		last->next = temp;
		*lst_b = (*lst_b)->next;
		temp->next = NULL;
	}
}

void	rotate_r_bis(t_stack **lst_a, t_stack **lst_b)
{
	rotate_aa(lst_a);
	rotate_bb(lst_b);
}

void	swap_a_bis(t_stack **lst_a)
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
}

void	swap_b_bis(t_stack **lst_b)
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
}
