/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ms3ouda <ms3ouda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 20:20:14 by gel-mejd          #+#    #+#             */
/*   Updated: 2025/03/01 00:09:26 by ms3ouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node  *new_node(int num)
{
    t_node *node;

    node = malloc(sizeof(t_node));
    if (!node)
        return (NULL);
    node->num = num;
    node->next = NULL;
    return (node);
}

// int main()
// {
//     int a = 42;
//     t_node *node1 = new_node(a);
//     printf("%d\n", node1->num);
//     printf("%s\n", node1->next);
// }