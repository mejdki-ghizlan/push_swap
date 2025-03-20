/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_2_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gel-mejd <gel-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 00:48:07 by gel-mejd          #+#    #+#             */
/*   Updated: 2025/03/15 23:13:03 by gel-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_node **stack)
{
	t_node	*tmp;

	if (!stack || !*stack)
		return ;
	tmp = (*stack);
	if (tmp->num > tmp->next->num)
		ft_swap(stack);
}

void	sort_3(t_node **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->num;
	b = (*stack)->next->num;
	c = (*stack)->next->next->num;
	if (a > b && a > c && b > c)
	{
		ft_ra(stack);
		ft_sa(stack);
	}
	else if (a > b && a > c && c > b)
		ft_ra(stack);
	else if (a > b && a < c)
		ft_sa(stack);
	else if (c < b && c < a && b > a)
		ft_rra(stack);
	else if (a < b && a < c && b > c)
	{
		ft_rra(stack);
		ft_sa(stack);
	}
	else
		return ;
}

void	sort_if_three(t_node **stack, int len)
{
	if (len == 2)
		sort_2(stack);
	else
		sort_3(stack);
}
