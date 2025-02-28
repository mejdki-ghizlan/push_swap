/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gel-mejd <gel-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 21:49:30 by gel-mejd          #+#    #+#             */
/*   Updated: 2025/02/27 22:21:15 by gel-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_atoi(char *str)
{
    int i;
    int s;
    int r;

    r = 0;
    s = 1;
    i = 0;
    while (str[i])
    {
        while (str[i] == ' ')
            i++;
        if (str[i] == '+' || str[i] == '-')
        {
            if (str[i] == '-')
                s = s * (-1);
            i++;
        }
        while (str[i] >= 0 && str[i] <= 9)
            r = r * 10 + (str[i] - 48);
        i++;
    }
    return (r * s);
}
int main()
{
    char *str = "    -123";
    printf("%d\n", ft_atoi(str));
}