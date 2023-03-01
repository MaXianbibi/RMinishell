/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwawzyni <dwawzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:08:17 by jmorneau          #+#    #+#             */
/*   Updated: 2022/11/09 03:00:26 by dwawzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	while (*str1 != '\0' && *str1 == *str2 && n-- > 0)
	{
		str1++;
		str2++;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)*str1 - (unsigned char)*str2);
}
