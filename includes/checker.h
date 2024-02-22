/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uaupetit <uaupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:49:34 by uaupetit          #+#    #+#             */
/*   Updated: 2023/03/09 11:12:34 by uaupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "push_swap.h"
# include "../get_next_line/includes/get_next_line.h"

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;
int					ft_strncmp(char *s1, char *s2, size_t n);
int					main(int ac, char **av);
void				exec_move(t_stack **lst_a, t_stack **lst_b, char *str);
void				push_a_bis(t_stack **lst_a, t_stack **lst_b);
void				push_b_bis(t_stack **lst_a, t_stack **lst_b);
void				reverse_rotate_a_bis(t_stack **lst_a);
void				reverse_rotate_b_bis(t_stack **lst_b);
void				reverse_rotate_r_bis(t_stack **lst_a, t_stack **lst_b);
void				rotate_a_bis(t_stack **lst_a);
void				rotate_b_bis(t_stack **lst_b);
void				rotate_r_bis(t_stack **lst_a, t_stack **lst_b);
void				swap_a_bis(t_stack **lst_a);
void				swap_b_bis(t_stack **lst_b);
void				swap_s_bis(t_stack **lst_a, t_stack **lst_b);
int					checker(t_stack **lst_a, t_stack **lst_b, char *line);
void				write_check(t_stack **lst_a, t_stack **lst_b);
int					main(int ac, char **av);
int					check_move(char *str);
void				free_stack_bis(t_stack **stack);
void				free_memory_bis(int *tab, t_stack **lst_a, t_stack **lst_b);
#endif
