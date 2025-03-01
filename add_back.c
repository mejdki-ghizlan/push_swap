/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ms3ouda <ms3ouda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 23:59:19 by ms3ouda           #+#    #+#             */
/*   Updated: 2025/03/01 05:53:01 by ms3ouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void add_back(t_node **lst, t_node *new)
{
    t_node *tmp;

    if (*lst == NULL)
        *lst = new;
    else
    {
        tmp = *lst;
        while (tmp->next != NULL)
           tmp = tmp->next;
        tmp->next = new;
    }
}

// int main()
// {
//     t_node  *lst = NULL;
//     t_node  *node1 = new_node(42);
//     t_node *node2 = new_node(1337);
//     add_back(&lst, node1);
//     add_back(&lst, node2);
//     printf("fvw");
//     while (lst)
//     {
//         printf("%d", lst->num);
//         lst = lst->next;
//     }
// }