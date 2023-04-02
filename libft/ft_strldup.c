/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strldup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:19:29 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/02 14:38:55 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strldup(const char *str, int n)
{
	char	*tmp;
	int		size;

	size = ft_strlen(str);
	if (size < n)
		tmp = ft_calloc(size + 1, sizeof(char));
	else
		tmp = ft_calloc(n + 1, sizeof(char));
	ft_strlcpy(tmp, str, n);
	return (tmp);
}
