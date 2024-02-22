/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_to_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uaupetit <uaupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:01:24 by uaupetit          #+#    #+#             */
/*   Updated: 2024/02/19 16:22:41 by uaupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*tab_to_lst(int *tab, int ac, t_stack *lst_a)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < ac - 1)
	{
		ft_lstadd_back(&lst_a, ft_lstnew(tab[i]));
		i++;
		j++;
	}
	return (lst_a);
}

t_stack	*ft_lstnew(int i)
{
	t_stack	*lst_a;

	lst_a = malloc(sizeof(t_stack));
	if (!lst_a)
		return (NULL);
	lst_a->content = i;
	lst_a->position = 0;
	lst_a->next = NULL;
	return (lst_a);
}

t_stack	*ft_lstlast(t_stack *lst_a)
{
	if (!lst_a)
		return (NULL);
	while (lst_a->next)
		lst_a = lst_a->next;
	return (lst_a);
}

void	ft_lstadd_back(t_stack **lst_a, t_stack *new)
{
	if (*lst_a)
		ft_lstlast(*lst_a)->next = new;
	else
		*lst_a = new;
}

t_stack	*ft_previouslast(t_stack *lst_a)
{
	if (!lst_a)
		return (NULL);
	while (lst_a->next->next)
		lst_a = lst_a->next;
	return (lst_a);
}
