/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uaupetit <uaupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:06:54 by uaupetit          #+#    #+#             */
/*   Updated: 2024/02/19 16:22:41 by uaupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*parsing(int *tab, int ac, char **av)
{
	int	j;
	int	i;

	j = 0;
	i = 1;
	if (ft_check_args(ac, av) == 0 && ft_len_check(ac, av) == 0)
	{
		while (i < ac)
		{
			if (ft_atol(av[i]) <= INT_MAX && ft_atol(av[i]) >= INT_MIN)
			{
				tab[j] = (int)ft_atol(av[i]);
				j++;
				i++;
			}
			else
				return (0);
		}
	}
	else
		return (0);
	if (ft_check_doublons(tab, ac) == 0)
		return (tab);
	else
		return (0);
}
