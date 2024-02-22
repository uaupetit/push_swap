/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_final_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uaupetit <uaupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:05:59 by uaupetit          #+#    #+#             */
/*   Updated: 2024/02/19 16:22:41 by uaupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	strokes_to_the_top(t_stack *lst)
{
	t_stack	*temp;
	int		med;

	med = ((ft_lstsize(lst) / 2) + (ft_lstsize(lst) % 2));
	temp = lst;
	set_position(&lst);
	while (temp)
	{
		if (temp->position <= med)
			temp->strokes = temp->position - 1;
		else if (temp->position > med)
			temp->strokes = ft_lstsize(lst) - temp->position + 1;
		temp = temp->next;
	}
}

t_stack	*find_next_highest(int ref, t_stack *lst_a)
{
	t_stack	*current;
	int		next_highest;

	if (!lst_a)
		return (0);
	current = lst_a;
	next_highest = INT_MAX;
	while (lst_a)
	{
		if (lst_a->content > ref && lst_a->content < next_highest)
		{
			next_highest = lst_a->content;
			current = lst_a;
		}
		lst_a = lst_a->next;
	}
	return (current);
}

t_stack	*cheapest(t_stack *lst_a, t_stack *lst_b)
{
	t_stack	*next;
	int		min_stroke;
	t_stack	*temp;
	t_stack	*cheap;

	cheap = lst_b;
	strokes_to_the_top(lst_a);
	strokes_to_the_top(lst_b);
	next = find_next_highest(lst_b->content, lst_a);
	min_stroke = cheap->strokes + next->strokes;
	temp = lst_b;
	while (temp)
	{
		next = find_next_highest(temp->content, lst_a);
		if ((temp->strokes + next->strokes) < min_stroke)
		{
			min_stroke = temp->strokes + next->strokes;
			cheap = temp;
		}
		temp = temp->next;
	}
	return (cheap);
}

t_stack	*who_is_highest(t_stack *cheapest, t_stack *next)
{
	if (cheapest->strokes <= next->strokes)
		return (next);
	else
		return (cheapest);
}

void	setting(t_stack **l_a, t_stack **l_b, t_stack *cheap, t_stack *next)
{
	while (ft_lstsize(*l_b) != 0)
	{
		cheap = cheapest(*l_a, *l_b);
		next = find_next_highest(cheap->content, *l_a);
		set_position(l_a);
		set_position(l_b);
		if ((cheap->position <= ft_size(*l_b))
			&& (next->position <= ft_size(*l_a)))
			under(l_a, l_b, cheap, next);
		else if ((cheap->position > ft_size(*l_b))
			&& (next->position > ft_size(*l_a)))
			upper(l_a, l_b, cheap, next);
		else
			both(l_a, l_b, cheap, next);
		push_a(l_a, l_b);
	}
}
