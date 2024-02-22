/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uaupetit <uaupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:20:17 by uaupetit          #+#    #+#             */
/*   Updated: 2024/02/19 16:43:25 by uaupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/checker.h"

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
			return (free_memory_bis(tab, &lst_a, &lst_b), 0);
		write_check(&lst_a, &lst_b);
	}
	free_memory_bis(tab, &lst_a, &lst_b);
	return (0);
}
