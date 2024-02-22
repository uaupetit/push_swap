/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_final.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uaupetit <uaupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:26:29 by uaupetit          #+#    #+#             */
/*   Updated: 2024/02/19 16:22:41 by uaupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algo_final(t_stack **lst_a, t_stack **lst_b)
{
	t_stack	*cheap;
	t_stack	*next_highest;

	cheap = *lst_b;
	next_highest = *lst_a;
	under_mediane(lst_a, lst_b);
	upper_mediane(lst_a, lst_b);
	push_a(lst_a, lst_b);
	setting(lst_a, lst_b, cheap, next_highest);
	while (order_or_not(*lst_a) != 1)
		reverse_rotate_a(lst_a);
}

void	under(t_stack **lst_a, t_stack **lst_b, t_stack *cheap, t_stack *next)
{
	while (cheap->position != 1 && next->position != 1)
	{
		rotate_r(lst_a, lst_b);
		set_position(lst_a);
		set_position(lst_b);
	}
	if (cheap->position != 1)
	{
		while (cheap->position != 1)
		{
			rotate_b(lst_b);
			set_position(lst_b);
		}
	}
	else if (next->position != 1)
	{
		while (next->position != 1)
		{
			rotate_a(lst_a);
			set_position(lst_a);
		}
	}
}

void	upper(t_stack **lst_a, t_stack **lst_b, t_stack *cheap, t_stack *next)
{
	while (cheap->position != 1 && next->position != 1)
	{
		reverse_rotate_r(lst_a, lst_b);
		set_position(lst_a);
		set_position(lst_b);
	}
	if (cheap->position != 1)
	{
		while (cheap->position != 1)
		{
			reverse_rotate_b(lst_b);
			set_position(lst_b);
		}
	}
	else if (next->position != 1)
	{
		while (next->position != 1)
		{
			reverse_rotate_a(lst_a);
			set_position(lst_a);
		}
	}
}

void	both(t_stack **lst_a, t_stack **lst_b, t_stack *cheap, t_stack *next)
{
	while (cheap->position != 1)
	{
		if (cheap->position <= ft_size(*lst_b))
		{
			rotate_b(lst_b);
			set_position(lst_b);
		}
		else if (cheap->position > ft_size(*lst_b))
		{
			reverse_rotate_b(lst_b);
			set_position(lst_b);
		}
	}
	while (next->position != 1)
		next_in_first(next, lst_a);
}

void	next_in_first(t_stack *next, t_stack **lst_a)
{
	if (next->position <= (ft_size(*lst_a)))
	{
		rotate_a(lst_a);
		set_position(lst_a);
	}
	else if (next->position > (ft_size(*lst_a)))
	{
		reverse_rotate_a(lst_a);
		set_position(lst_a);
	}
}
