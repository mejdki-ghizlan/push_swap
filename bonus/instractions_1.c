/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instractions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gel-mejd <gel-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 03:08:10 by gel-mejd          #+#    #+#             */
/*   Updated: 2025/03/21 12:03:46 by gel-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_push(t_node **src, t_node **target)
{
	t_node	*new_head;
	t_node	*tmp;

	if (!*src)
		return ;
	tmp = (*src);
	new_head = (*src)->next;
	*src = new_head;
	tmp->next = *target;
	(*target) = tmp;
}

void	pa_bonus(t_node **stack_a, t_node **stack_b)
{
	ft_push(stack_b, stack_a);
}

void	pb_bonus(t_node **stack_a, t_node **stack_b)
{
	ft_push(stack_a, stack_b);
}

void	ft_reverse_rotate(t_node **stack)
{
	t_node	*tmp;
	t_node	*last;
	t_node	*second_last;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next)
	{
		second_last = tmp;
		tmp = tmp->next;
	}
	last = tmp;
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rrr_bonus(t_node **stack_a, t_node **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
}
