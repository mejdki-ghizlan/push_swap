/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instractions_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gel-mejd <gel-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 03:18:26 by gel-mejd          #+#    #+#             */
/*   Updated: 2025/03/21 12:03:54 by gel-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa_bonus(t_node **stack_a)
{
	ft_swap(stack_a);
}

void	sb_bonus(t_node **stack_b)
{
	ft_swap(stack_b);
}

void	ss_bonus(t_node **stack_a, t_node **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
}

void	rra_bonus(t_node **stack_a)
{
	ft_reverse_rotate(stack_a);
}