/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gel-mejd <gel-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 05:35:07 by gel-mejd          #+#    #+#             */
/*   Updated: 2025/03/16 23:55:50 by gel-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_rr(t_node **stack_a, t_node **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	write(1, "rr\n", 3);
}

void	ft_ra(t_node **stack_a)
{
	ft_rotate(stack_a);
	write(1, "ra\n", 3);
}

void	ft_rb(t_node **stack_a)
{
	ft_rotate(stack_a);
	write(1, "rb\n", 3);
}
