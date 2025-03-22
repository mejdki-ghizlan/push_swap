/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gel-mejd <gel-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 20:39:41 by gel-mejd          #+#    #+#             */
/*   Updated: 2025/03/18 18:17:13 by gel-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all(t_node **stack_a, t_node **stack_b)
{
	int	lena;

	if (!stack_a || !*stack_a)
		return ;
	lena = list_size(*stack_a);
	while (lena > 3)
	{
		ft_pb(stack_a, stack_b);
		lena--;
	}
}

int	total_cost(t_node *node1)
{
	int	total;

	if (!node1 || !node1->target)
		return (0);
	total = node1->cost + node1->target->cost;
	return (total);
}

t_node	*get_min_tootal_cost(t_node *stack_b)
{
	t_node	*tmp;
	t_node	*small;

	if (!stack_b)
		return (NULL);
	small = stack_b;
	tmp = stack_b;
	while (tmp)
	{
		if (total_cost(tmp) < total_cost(small))
			small = tmp;
		tmp = tmp->next;
	}
	return (small);
}

void	last_move(t_node **stack_a)
{
	t_node	*tmp;
	t_node	*small;

	tmp = *stack_a;
	small = *stack_a;
	indexing(*stack_a);
	position(*stack_a);
	cost(*stack_a);
	while (tmp)
	{
		if (small->num > tmp->num)
			small = tmp;
		tmp = tmp->next;
	}
	if (small->position == 0)
	{
		while (small->cost--)
			ft_ra(stack_a);
	}
	else
	{
		while (small->cost--)
			ft_rra(stack_a);
	}
}

void	best_move(t_node **stack_a, t_node **stack_b)
{
	t_node	**tmp;
	int		len;
	int		i;

	i = 0;
	tmp = stack_b;
	if (!stack_a || !stack_b)
		return ;
	push_all(stack_a, stack_b);
	len = list_size(*stack_a);
	if (len <= 3)
		sort_if_three(stack_a, len);
	len = list_size(*stack_b);
	while (i++ < len && tmp)
	{
		indexing(*stack_a);
		indexing(*stack_b);
		position(*stack_a);
		position(*stack_b);
		cost(*stack_a);
		cost(*stack_b);
		target(*stack_a, *stack_b);
		moves(stack_a, stack_b);
	}
	last_move(stack_a);
}
