/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gel-mejd <gel-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 07:08:13 by ms3ouda           #+#    #+#             */
/*   Updated: 2025/03/16 23:58:01 by gel-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_pa(t_node **stack_a, t_node **stack_b)
{
	ft_push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	ft_pb(t_node **stack_a, t_node **stack_b)
{
	ft_push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
