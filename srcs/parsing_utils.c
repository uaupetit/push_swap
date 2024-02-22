/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uaupetit <uaupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:14:39 by uaupetit          #+#    #+#             */
/*   Updated: 2024/02/19 16:22:41 by uaupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	count_digits(char *str)
{
	int	count;
	int	sign_flag;

	count = 0;
	sign_flag = 0;
	if (str[0] == '+' || str[0] == '-')
		sign_flag = 1;
	while (str[sign_flag] == '0')
		sign_flag++;
	while (str[sign_flag] != '\0')
	{
		count++;
		sign_flag++;
	}
	return (count);
}

int	ft_len_check(int ac, char **av)
{
	int	e;
	int	k;
	int	i;

	e = 0;
	k = 1;
	while (k < ac)
	{
		i = count_digits(av[k]);
		if (i > 10)
		{
			e++;
		}
		k++;
	}
	if (e != 0)
		return (1);
	return (0);
}
/*
int	ft_len_check(int ac, char **av)
{
	int	i;
	int	j;
	int	k;
	int	e;
	int	k;
	int	lenght;

	e = 0;
	k = 1;
	while (k < ac)
	{
		i = 0;
		j = 0;
		if (av[k][j] == '+' || av[k][j] == '-')
			j++;
		while (av[k][j] == '0' && av[k][j])
			j++;
		while (av[k][j])
		{
			j++;
			i++;
		}
		if (i > 10)
			e++;
		k++;
	}
	if (e != 0)
		return (1);
	return (0);
}*/
/*int	ft_len_check(int ac, char **av)
{
	k = 1;
	length = 0;
	while (k < ac)
	{
		length = get_number_length(av[k]);
		if (length > 10)
			return (1);
		k++;
	}
	return (0);
}

int	get_number_length(char *str)
{
	int	length;
	int	i;

	length = 0;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] == '0')
		i++;
	while (str[i] != '\0')
	{
		length++;
		i++;
	}
	return (length);
}
*/

int	ft_check_doublons(int *tab, int ac)
{
	int	i;
	int	j;
	int	*tab1;

	tab1 = tab;
	i = 0;
	while (i < ac - 2)
	{
		j = i + 1;
		while (j < ac - 1)
		{
			if (tab1[j] == tab[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

long	ft_atol(char *nptr)
{
	int		i;
	int		signe;
	long	nb;

	i = 0;
	signe = 1;
	nb = 0;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			signe *= -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		nb = nb * 10 + (nptr[i] - 48);
		i++;
	}
	nb = nb * signe;
	return (nb);
}

int	ft_check_args(int ac, char **av)
{
	int	j;
	int	i;

	j = 1;
	while (j < ac)
	{
		i = 0;
		if (av[j][i] >= 48 && av[j][i] <= 57)
			i++;
		else if ((av[j][i] == '+' || av[j][i] == '-') &&
					(av[j][i + 1] >= 48 && av[j][i + 1] <= 57))
			i++;
		else
			return (1);
		while (av[j][i])
		{
			if (av[j][i] >= 48 && av[j][i] <= 57)
				i++;
			else
				return (1);
		}
		j++;
	}
	return (0);
}
