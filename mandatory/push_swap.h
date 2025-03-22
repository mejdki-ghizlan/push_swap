/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gel-mejd <gel-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:34:34 by gel-mejd          #+#    #+#             */
/*   Updated: 2025/03/21 10:31:35 by gel-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				num;
	int				cost;
	int				position;
	int				index;
	struct s_node	*target;
	struct s_node	*next;
}					t_node;

// algo
void				push_all(t_node **stack_a, t_node **stack_b);
int					total_cost(t_node *node1);
t_node				*get_min_tootal_cost(t_node *stack_b);
void				last_move(t_node **stack_a);
void				best_move(t_node **stack_a, t_node **stack_b);

// ft_push
void				ft_push(t_node **stack_a, t_node **stack_b);
void				ft_pa(t_node **stack_a, t_node **stack_b);
void				ft_pb(t_node **stack_a, t_node **stack_b);

// ft_revrse_rotate
void				ft_reverse_rotate(t_node **stack);
void				ft_rrr(t_node **stack_a, t_node **stack_b);
void				ft_rra(t_node **stack_a);
void				ft_rrb(t_node **stack_b);

// ft_rotate
void				ft_rotate(t_node **stack);
void				ft_rr(t_node **stack_a, t_node **stack_b);
void				ft_ra(t_node **stack_a);
void				ft_rb(t_node **stack_a);

// ft_swap
void				ft_swap(t_node **stack);
void				ft_sa(t_node **stack_a);
void				ft_sb(t_node **stack_b);
void				ft_ss(t_node **stack_a, t_node **stack_b);

// is_valid
t_node				*new_node(int num);
void				add_back(t_node **lst, t_node *new);
int					is_duplicate(t_node *node, t_node **stack);
int					check_numbers(char **buff);
int					is_valid(char **str, t_node **stack);

// main_push_swap
char				**ft_split(char *str);
int					count_word(char *str);
void 				helper_split(char **dst, char *str, int i, int *k);

// free_functions
void				ft_free_stack(t_node **stack);
void          		free_exit(char ***av);
void				ft_free(char **str);

// set_stack
void				indexing(t_node *stack);
void				min_target(t_node *stack_a, t_node *node);
void				target(t_node *stack_a, t_node *stack_b);
void				position(t_node *stack);
void				cost(t_node *stack);

// sort
void				moves(t_node **stack_a, t_node **stack_b);
void				check_0_0(t_node **stack_a, t_node **stack_b,
						t_node *small);
void				check_1_0(t_node **stack_a, t_node **stack_b,
						t_node *small);
void				check_1_1(t_node **stack_a, t_node **stack_b,
						t_node *small);
void				check_0_1(t_node **stack_a, t_node **stack_b,
						t_node *small);

// sorting_2_5
void				sort_if_three(t_node **stack, int len);
void				sort_3(t_node **stack);
void				sort_2(t_node **stack);

// utils
int					ft_atoi(char *str, int *check);
void				error(void);
int					list_size(t_node *list);
void				is_sorted(t_node **stack);


#endif
