/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uaupetit <uaupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:10:57 by uaupetit          #+#    #+#             */
/*   Updated: 2024/02/19 16:22:41 by uaupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../get_next_line/includes/get_next_line.h"
#include "../includes/push_swap.h"
#include "../includes/checker.h"

void	exec_move(t_stack **lst_a, t_stack **lst_b, char *str)
{
	if (ft_strncmp(str, "pa\n", 3) == 0)
		push_a_bis(lst_a, lst_b);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		push_b_bis(lst_a, lst_b);
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		rotate_a_bis(lst_a);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		rotate_b_bis(lst_b);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		rotate_r_bis(lst_a, lst_b);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		reverse_rotate_a_bis(lst_a);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		reverse_rotate_b_bis(lst_b);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		reverse_rotate_r_bis(lst_a, lst_b);
	else if (ft_strncmp(str, "sa\n", 3) == 0)
		swap_a_bis(lst_a);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		swap_b_bis(lst_b);
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		swap_s_bis(lst_a, lst_b);
}

int	check_move(char *str)
{
	if (ft_strncmp(str, "pa\n", 3) == 0)
		return (0);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		return (0);
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		return (0);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		return (0);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		return (0);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		return (0);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		return (0);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		return (0);
	else if (ft_strncmp(str, "sa\n", 3) == 0)
		return (0);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		return (0);
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		return (0);
	else
		return (1);
}

int	checker(t_stack **lst_a, t_stack **lst_b, char *line)
{
	while (line != NULL)
	{
		if (check_move(line) == 1)
		{
			write(2, "error\n", 6);
			free (line);
			get_next_line(0, 1);
			return (1);
		}
		exec_move(lst_a, lst_b, line);
		free(line);
		line = get_next_line(0, 0);
	}
	return (0);
}

void	write_check(t_stack **lst_a, t_stack **lst_b)
{
	char	*line;

	line = get_next_line(0, 0);
	if (checker(lst_a, lst_b, line) == 1)
		return ;
	if (*lst_a == NULL)
		write (1, "KO\n", 3);
	else if ((order_or_not(*lst_a) == 1) && ft_lstsize(*lst_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	free_memory_bis(int *tab, t_stack **lst_a, t_stack **lst_b)
{
	free(tab);
	free_stack_bis(lst_a);
	free_stack_bis(lst_b);
}
