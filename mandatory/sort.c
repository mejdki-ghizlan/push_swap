/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gel-mejd <gel-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 22:41:11 by gel-mejd          #+#    #+#             */
/*   Updated: 2025/03/21 09:54:31 by gel-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	moves(t_node **stack_a, t_node **stack_b)
{
	t_node	*small;

	small = get_min_tootal_cost(*stack_b);
	if ((small->position == 0) && (small->target->position == 0))
		check_0_0(stack_a, stack_b, small);
	else if ((small->position == 1) && (small->target->position == 0))
		check_1_0(stack_a, stack_b, small);
	else if ((small->position == 1) && (small->target->position == 1))
		check_1_1(stack_a, stack_b, small);
	else if ((small->position == 0) && (small->target->position == 1))
		check_0_1(stack_a, stack_b, small);
	ft_pa(stack_a, stack_b);
}

void	check_0_0(t_node **stack_a, t_node **stack_b, t_node *small)
{
	if (!*stack_b || !(*stack_b)->target)
		return ;
	if (small->cost < small->target->cost)
	{
		while (small->cost--)
		{
			ft_rr(stack_a, stack_b);
			small->target->cost--;
		}
		while (small->target->cost--)
			ft_ra(stack_a);
	}
	else
	{
		while (small->target->cost--)
		{
			ft_rr(stack_a, stack_b);
			small->cost--;
		}
		while (small->cost--)
			ft_rb(stack_b);
	}
}

void	check_1_0(t_node **stack_a, t_node **stack_b, t_node *small)
{
	if (!(*stack_b) || !(*stack_b)->target)
		return ;
	while (small->cost--)
		ft_rrb(stack_b);
	while (small->target->cost--)
		ft_ra(stack_a);
}

void	check_1_1(t_node **stack_a, t_node **stack_b, t_node *small)
{
	if (!(*stack_b) || !(*stack_b)->target)
		return ;
	if (small->cost < small->target->cost)
	{
		while (small->cost--)
		{
			ft_rrr(stack_a, stack_b);
			small->target->cost--;
		}
		while (small->target->cost--)
			ft_rra(stack_a);
	}
	else
	{
		while (small->target->cost--)
		{
			ft_rrr(stack_a, stack_b);
			small->cost--;
		}
		while (small->cost--)
			ft_rrb(stack_b);
	}
}

void	check_0_1(t_node **stack_a, t_node **stack_b, t_node *small)
{
	if (!(*stack_b) || !(*stack_b)->target)
		return ;
	while (small->cost--)
		ft_rb(stack_b);
	while (small->target->cost--)
		ft_rra(stack_a);
}
