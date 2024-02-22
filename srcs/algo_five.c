/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uaupetit <uaupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:03:19 by uaupetit          #+#    #+#             */
/*   Updated: 2024/02/19 16:22:41 by uaupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 1;
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	set_position(t_stack **lst)
{
	int		i;
	t_stack	*cur;

	i = 1;
	cur = *lst;
	while (cur)
	{
		cur->position = i;
		cur = cur->next;
		i++;
	}
}

int	findlowest(t_stack *lst)
{
	int	lowest;

	lowest = lst->content;
	while (lst)
	{
		if (lst->content < lowest)
			lowest = lst->content;
		lst = lst->next;
	}
	return (lowest);
}

void	move_lowest_to_top(t_stack **stack, int lowest)
{
	t_stack	*temp;

	temp = *stack;
	set_position(stack);
	while (temp->content != lowest)
		temp = temp->next;
	if ((temp->position > ft_lstsize(*stack) / 2) + (ft_lstsize(*stack) % 2))
	{
		while (temp->position != 1)
		{
			reverse_rotate_a(stack);
			set_position(stack);
		}
	}
	else if (temp->position <= ft_size(*stack))
	{
		while (temp->position != 1)
		{
			rotate_a(stack);
			set_position(stack);
		}
	}
}

void	algo_five(t_stack **lst_a, t_stack **lst_b)
{
	int		lowest;
	int		size;

	size = ft_lstsize(*lst_a);
	while (ft_lstsize(*lst_a) != 3)
	{
		lowest = findlowest(*lst_a);
		move_lowest_to_top(lst_a, lowest);
		push_b(lst_a, lst_b);
	}
	algo_three(lst_a);
	while (ft_lstsize(*lst_a) != size)
		push_a(lst_a, lst_b);
}
