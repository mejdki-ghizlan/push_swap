/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ms3ouda <ms3ouda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 22:02:40 by gel-mejd          #+#    #+#             */
/*   Updated: 2025/03/01 05:58:13 by ms3ouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int count_word(char *str)
{
    int counter;

    counter = 0;
    while (*str != '\0')
    {
        while (*str == ' ')
            str++;
        if (*str == '\0')
            break ;
        while (*str != ' ')
            str++;
        counter++;
    }
    return (counter);
}

char **ft_split(char *str)
{
    char **dst;
    int len;
    int cw;
    int i;
    int j;

    if (*str == '\0')
        return NULL;
    cw = count_word(str);
    dst = malloc((cw + 1) * sizeof(char *));
    if (!dst) 
        return NULL;
    i = 0;
    j = 0;
    while (i < cw) {
        while (str[j] == ' ')
            j++;
        len = 0;
        while (str[j + len] && str[j + len] != ' ')
            len++;
        dst[i] = malloc(len + 1);
        int c = 0;
        while (c < len) {
            dst[i][c] = str[j + c];
            c++;
        }
        dst[i][c] = '\0';  
        j += len;  
        i++;
    }
    dst[i] = NULL; 
    return dst;
}

// int main()
// {
//     char *str = "ab  cd cv dgdf dfgdf ";
//     char **res;
//     res = ft_split(str);
//     while(*res)
//         printf("%s-----> \n", *res++);
//     return (0);
// }