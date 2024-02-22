/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uaupetit <uaupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:56:33 by uaupetit          #+#    #+#             */
/*   Updated: 2024/02/22 10:27:46 by uaupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct lst_a
{
	int				content;
	int				position;
	int				strokes;
	struct lst_a	*next;
}					t_stack;
int					find_mediane(t_stack *lst);
int					highest_value(t_stack *lst);
int					count_digits(char *str);
int					ft_size(t_stack *lst);
int					*create_tab_from_lst(t_stack *lst);
int					ft_len_check(int ac, char **av);
int					ft_check_doublons(int *tab, int ac);
int					ft_check_args(int ac, char **av);
int					*parsing(int *tab, int ac, char **av);
int					main(int ac, char **av);
int					order_or_not(t_stack *lst);
int					croissant_order(t_stack *lst);
int					decroissant_order(t_stack *lst);
int					findlowest(t_stack *lst);
int					ft_lstsize(t_stack *lst);
t_stack				*who_is_highest(t_stack *cheapest, t_stack *next);
t_stack				*cheapest(t_stack *lst_a, t_stack *lst_b);
t_stack				*ft_lstnew(int i);
t_stack				*ft_lstlast(t_stack *lst_a);
t_stack				*tab_to_lst(int *tab, int ac, t_stack *lst_a);
t_stack				*ft_previouslast(t_stack *lst_a);
t_stack				*next_lowest(t_stack *a, t_stack *b, t_stack *lowest);
t_stack				*first_lowest(t_stack *lst_a, t_stack *lst_b);
t_stack				*find_next_highest(int ref, t_stack *lst_a);
long				ft_atol(char *nptr);
void				strokes_to_the_top(t_stack *lst);
void				algo_three(t_stack **lst_a);
void				ft_lstadd_back(t_stack **lst_a, t_stack *new);
void				set_position(t_stack **lst);
void				swap_a(t_stack **lst_a);
void				swap_b(t_stack **lst_b);
void				swap_s(t_stack **lst_a, t_stack **lst_b);
void				push_a(t_stack **lst_a, t_stack **lst_b);
void				push_b(t_stack **lst_a, t_stack **lst_b);
void				rotate_a(t_stack **lst_a);
void				rotate_b(t_stack **lst_b);
void				rotate_aa(t_stack **lst_a);
void				rotate_bb(t_stack **lst_b);
void				rotate_r(t_stack **lst_a, t_stack **lst_b);
void				reverse_rotate_a(t_stack **lst_a);
void				reverse_rotate_aa(t_stack **lst_a);
void				reverse_rotate_b(t_stack **lst_b);
void				reverse_rotate_bb(t_stack **lst_b);
void				reverse_rotate_r(t_stack **lst_a, t_stack **lst_b);
void				algo_five(t_stack **lst_a, t_stack **lst_b);
void				strokes_to_push(t_stack *lst_a, t_stack *lst_b);
void				under_mediane(t_stack **lst_a, t_stack **lst_b);
void				swap_values(int *a, int *b);
void				tab_sort(int *tab, int size);
void				upper_mediane(t_stack **lst_a, t_stack **lst_b);
void				algo_final(t_stack **lst_a, t_stack **lst_b);
void				algo_two(t_stack **lst_a);
void				under(t_stack **lst_a, t_stack **lst_b, t_stack *cheap,
						t_stack *next);
void				upper(t_stack **lst_a, t_stack **lst_b, t_stack *cheap,
						t_stack *next);
void				both(t_stack **lst_a, t_stack **lst_b, t_stack *cheap,
						t_stack *next);
void				setting(t_stack **l_a, t_stack **l_b, t_stack *cheap,
						t_stack *next);
void				next_in_first(t_stack *next, t_stack **lst_a);
void				free_stack(t_stack **stack);
void				free_memory(int *tab, t_stack **lst_a, t_stack **lst_b);
#endif