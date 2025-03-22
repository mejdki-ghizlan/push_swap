/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instractions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gel-mejd <gel-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 03:11:35 by gel-mejd          #+#    #+#             */
/*   Updated: 2025/03/18 03:14:47 by gel-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rrb_bonus(t_node **stack_b)
{
	ft_reverse_rotate(stack_b);
}

void	ft_rotate(t_node **stack)
{
	t_node	*head;
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	head = *stack;
	*stack = (*stack)->next;
	head->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = head;
}

void	rr_bonus(t_node **stack_a, t_node **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}

void	ra_bonus(t_node **stack_a)
{
	ft_rotate(stack_a);
}

void	rb_bonus(t_node **stack_a)
{
	ft_rotate(stack_a);
}
