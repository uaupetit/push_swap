/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uaupetit <uaupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:38:49 by uaupetit          #+#    #+#             */
/*   Updated: 2024/02/19 16:22:41 by uaupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate_a(t_stack **lst_a)
{
	t_stack	*previouslast;
	t_stack	*last;

	if (ft_lstsize(*lst_a) > 1)
	{
		previouslast = ft_previouslast(*lst_a);
		last = ft_lstlast(*lst_a);
		last->next = *lst_a;
		*lst_a = last;
		previouslast->next = NULL;
		write(1, "rra\n", 4);
	}
}

void	reverse_rotate_b(t_stack **lst_b)
{
	t_stack	*previouslast;
	t_stack	*last;

	if (ft_lstsize(*lst_b) > 1)
	{
		previouslast = ft_previouslast(*lst_b);
		last = ft_lstlast(*lst_b);
		last->next = *lst_b;
		*lst_b = last;
		previouslast->next = NULL;
		write(1, "rrb\n", 4);
	}
}

void	reverse_rotate_r(t_stack **lst_a, t_stack **lst_b)
{
	if (ft_lstsize(*lst_a) > 1 && ft_lstsize(*lst_b) > 1)
	{
		reverse_rotate_aa(lst_a);
		reverse_rotate_bb(lst_b);
		write(1, "rrr\n", 4);
	}
}

void	reverse_rotate_aa(t_stack **lst_a)
{
	t_stack	*previouslast;
	t_stack	*last;

	if (ft_lstsize(*lst_a) > 1)
	{
		previouslast = ft_previouslast(*lst_a);
		last = ft_lstlast(*lst_a);
		last->next = *lst_a;
		*lst_a = last;
		previouslast->next = NULL;
	}
}

void	reverse_rotate_bb(t_stack **lst_b)
{
	t_stack	*previouslast;
	t_stack	*last;

	if (ft_lstsize(*lst_b) > 1)
	{
		previouslast = ft_previouslast(*lst_b);
		last = ft_lstlast(*lst_b);
		last->next = *lst_b;
		*lst_b = last;
		previouslast->next = NULL;
	}
}
