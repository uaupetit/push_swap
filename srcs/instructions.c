/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uaupetit <uaupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:31:35 by uaupetit          #+#    #+#             */
/*   Updated: 2024/02/19 16:43:25 by uaupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/checker.h"

void	push_a_bis(t_stack **lst_a, t_stack **lst_b)
{
	t_stack	*temp;

	if (*lst_b != NULL)
	{
		temp = *lst_b;
		*lst_b = (*lst_b)->next;
		temp->next = *lst_a;
		*lst_a = temp;
	}
}

void	push_b_bis(t_stack **lst_a, t_stack **lst_b)
{
	t_stack	*temp;

	if (*lst_a != NULL)
	{
		temp = *lst_a;
		*lst_a = (*lst_a)->next;
		temp->next = *lst_b;
		*lst_b = temp;
	}
}

void	reverse_rotate_a_bis(t_stack **lst_a)
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

void	reverse_rotate_b_bis(t_stack **lst_b)
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

void	reverse_rotate_r_bis(t_stack **lst_a, t_stack **lst_b)
{
	reverse_rotate_aa(lst_a);
	reverse_rotate_bb(lst_b);
}
