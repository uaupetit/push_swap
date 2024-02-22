/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mediane_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uaupetit <uaupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:12:21 by uaupetit          #+#    #+#             */
/*   Updated: 2024/02/19 16:22:41 by uaupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	highest_value(t_stack *lst)
{
	t_stack	*temp;
	int		max;

	temp = lst;
	max = temp->content;
	while (temp)
	{
		if (temp->next && temp->next->content > max)
			max = temp->next->content;
		temp = temp->next;
	}
	return (max);
}

void	tab_sort(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < (size - 1))
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
				swap_values(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
}

void	swap_values(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	*create_tab_from_lst(t_stack *lst)
{
	int		*tab;
	int		i;
	t_stack	*temp;

	temp = lst;
	i = 0;
	tab = malloc(sizeof(int) * (ft_lstsize(lst) + 1));
	if (!tab)
		return (0);
	while (temp)
	{
		tab[i] = temp->content;
		temp = temp->next;
		i++;
	}
	return (tab);
}

int	find_mediane(t_stack *lst)
{
	int	*tab;
	int	median;

	tab = create_tab_from_lst(lst);
	if (!tab)
		return (0);
	tab_sort(tab, ft_lstsize(lst));
	if (ft_lstsize(lst) % 2 == 0)
		median = tab[(ft_lstsize(lst) + 1) / 2];
	else
		median = tab[ft_lstsize(lst) / 2];
	free(tab);
	return (median);
}
