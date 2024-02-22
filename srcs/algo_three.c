/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uaupetit <uaupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:57:17 by uaupetit          #+#    #+#             */
/*   Updated: 2024/02/19 16:22:41 by uaupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algo_three(t_stack **lst_a)
{
	while (order_or_not(*lst_a) != 1)
	{
		if ((*lst_a)->content == highest_value(*lst_a))
			rotate_a(lst_a);
		else if (ft_lstlast(*lst_a)->content == highest_value(*lst_a))
			swap_a(lst_a);
		else if ((*lst_a)->next->content == highest_value(*lst_a))
			reverse_rotate_a(lst_a);
	}
}
