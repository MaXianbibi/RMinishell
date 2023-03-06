/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:53:32 by justinmorne       #+#    #+#             */
/*   Updated: 2023/03/06 17:54:53 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_find_index( const char * str, char c)
{
    int i;

    i = 0; 
    while (str[i])
    {
        if (str[i] == c)
            return (i);
        i++;
    }
    return (0);
}