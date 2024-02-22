/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_or_not.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uaupetit <uaupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:05:07 by uaupetit          #+#    #+#             */
/*   Updated: 2024/02/19 16:22:41 by uaupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	order_or_not(t_stack *lst)
{
	if (croissant_order(lst) == 0)
		return (1);
	else if (decroissant_order(lst) == 0)
		return (2);
	else
		return (0);
}

int	croissant_order(t_stack *lst)
{
	while (lst->next)
	{
		if ((lst->content) < (lst->next->content))
			lst = lst->next;
		else
			return (1);
	}
	return (0);
}

int	decroissant_order(t_stack *lst)
{
	while (lst->next)
	{
		if ((lst->content) > (lst->next->content))
			lst = lst->next;
		else
			return (1);
	}
	return (0);
}
