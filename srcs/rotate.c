/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uaupetit <uaupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:36:02 by uaupetit          #+#    #+#             */
/*   Updated: 2024/02/19 16:22:41 by uaupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(t_stack **lst_a)
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
		write(1, "ra\n", 3);
	}
}

void	rotate_b(t_stack **lst_b)
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
		write(1, "rb\n", 3);
	}
}

void	rotate_r(t_stack **lst_a, t_stack **lst_b)
{
	if (ft_lstsize(*lst_a) > 1 && ft_lstsize(*lst_b) > 1)
	{
		rotate_aa(lst_a);
		rotate_bb(lst_b);
		write(1, "rr\n", 3);
	}
}

void	rotate_aa(t_stack **lst_a)
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

void	rotate_bb(t_stack **lst_b)
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
