/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ms3ouda <ms3ouda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:14:44 by gel-mejd          #+#    #+#             */
/*   Updated: 2025/03/01 05:54:02 by ms3ouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    int i;
    int j;
    int k;
    int num;
    char **buff;
    t_node *stack = NULL;
    t_node *node;

    if (ac >= 2)
    {
        k = 1;
        while (av[k])
        {
            buff = ft_split(av[k]);
            if (!buff)
            {
                write(1, "ERROR\n", 6);
                exit(1);
            }
            i = 0;
            j = 0;
            while (buff[i][j])
            {
                if (!((buff[i][j] &&  buff[i][j] >= '0' && buff[i][j] <= '9') || buff[i][j] == '-' || buff[i][j] == '+' || buff[i][j] == ' '))
                {
                    write(1, "ERROR\n", 6);    
                    exit(1);
                }  
                while ((buff[i][j] &&  buff[i][j] >= '0' && buff[i][j] <= '9') || buff[i][j] == '-' || buff[i][j] == '+' || buff[i][j] == ' ')
                {
                    if (buff[i][j] == '-' || buff[i][j] == '+')
                    {
                        j++;
                        if (buff[i][j] == ' ' || buff[i][j] == '\0' || buff[i][j] == '-' || buff[i][j] == '+')  
                        {
                            write(1, "ERROR\n", 6);
                            exit(1);
                        }
                    }
                    j++;
                }
                num = ft_atoi(buff[i]);
                node = new_node(num);
                add_back(&stack, node);
                i++;
            }
            k++;
        }
    }
    return 0;
}
