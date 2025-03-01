/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ms3ouda <ms3ouda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 07:08:13 by ms3ouda           #+#    #+#             */
/*   Updated: 2025/03/01 07:08:32 by ms3ouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap(t_node *stack_a, t_node *stack_b)
{
    t_node *head_a;
    t_node *head_b;

    head_a = stack_a;
    head_b = stack_b;
    stack_a->next = stack_b;
    head_a->next = stack_a->next;
    head_b->next = stack_a;
}