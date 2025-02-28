/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gel-mejd <gel-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:14:44 by gel-mejd          #+#    #+#             */
/*   Updated: 2025/02/27 18:51:24 by gel-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    int i;
    int j;
    char **buff;
    // s_node stack_a;
    // s_node stack_b;

    if (ac >= 2)
    {
        i = 1;
        while (av[i])
        {
            buff = ft_split(av[i]);
            if (!buff)
            {
                write(1, "ERROR\n", 6);
                exit(1);
            }
            if (!((buff[i][j] &&  buff[i][j] >= '0' && buff[i][j] <= '9') || buff[i][j] == '-' || buff[i][j] == '+' || buff[i][j] == ' '))
            {
                write(1, "ERROR\n", 6);    
                exit(1);
            }  
            j = 0;
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
            i++;
        }
    }
    return 0;
}
