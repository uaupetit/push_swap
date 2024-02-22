/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uaupetit <uaupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:57:14 by uaupetit          #+#    #+#             */
/*   Updated: 2024/02/19 16:22:41 by uaupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		(*stack)->content = 0;
		(*stack)->position = 0;
		(*stack)->strokes = 0;
		tmp = *stack;
		*stack = tmp->next;
		free(tmp);
	}
	*stack = (NULL);
}

void	free_memory(int *tab, t_stack **lst_a, t_stack **lst_b)
{
	free(tab);
	free_stack(lst_a);
	free_stack(lst_b);
}

void	algorithm(int ac, t_stack **lst_a, t_stack **lst_b)
{
	if (ac == 3)
		algo_two(lst_a);
	else if (ac == 4)
		algo_three(lst_a);
	else if (ac == 5 || ac == 6)
		algo_five(lst_a, lst_b);
	else
		algo_final(lst_a, lst_b);
}

int	main(int ac, char **av)
{
	int		*tab;
	t_stack	*lst_a;
	t_stack	*lst_b;

	lst_a = NULL;
	lst_b = NULL;
	if (ac <= 1)
		return (0);
	tab = malloc(sizeof(int) * (ac - 1));
	if (!tab)
		return (0);
	if (!(parsing(tab, ac, av)))
		write(2, "Error\n", 6);
	else
	{
		lst_a = tab_to_lst(tab, ac, lst_a);
		if (!lst_a)
			return (free_memory(tab, &lst_a, &lst_b), 0);
		if (order_or_not(lst_a) != 1)
			algorithm(ac, &lst_a, &lst_b);
	}
	free_memory(tab, &lst_a, &lst_b);
	return (0);
}
