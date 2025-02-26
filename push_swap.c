/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gel-mejd <gel-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:14:44 by gel-mejd          #+#    #+#             */
/*   Updated: 2025/02/24 22:12:07 by gel-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"


// int main(int ac, char **av)
// {
//     int i;
//     int j;
//     // s_node stack_a;
//     // s_node stack_b;

//     if (ac >= 2)
//     {
//         i = 1;
//         while (av[i])
//         {
//             if (!((av[i][j] &&  av[i][j] >= '0' && av[i][j] <= '9') || av[i][j] == '-' || av[i][j] == '+' || av[i][j] == ' '))
//             {
//                 write(1, "ERROR\n", 6);    
//                 exit(1);
//             }  
//             j = 0;
//             while ((av[i][j] &&  av[i][j] >= '0' && av[i][j] <= '9') || av[i][j] == '-' || av[i][j] == '+' || av[i][j] == ' ')
//             {
//                 if (av[i][j] == '-' || av[i][j] == '+')
//                 {
//                     j++;
//                     if (av[i][j] == ' ' || av[i][j] == '\0' || av[i][j] == '-' || av[i][j] == '+')  
//                     {
//                         write(1, "ERROR\n", 6);
//                         exit(1);
//                     }
//                 }
//                 j++;
//             }
//             i++;
//         }
//     }
//     return 0;
// }
