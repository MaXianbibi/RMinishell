/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:21:41 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/02 14:40:23 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*addspace(char *str)
{
	char	*tmp;

	tmp = ft_strjoin(str, " ");
	free(str);
	return (tmp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen((char *)s1) + ft_strlen((char *)s2))
			+ 1);
	if (!str)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*multiple_join(char **split, int add_space)
{
	int		i;
	char	*tmp;
	char	*str;

	i = 0;
	tmp = NULL;
	str = NULL;
	while (split[i])
	{
		if (str)
			ft_free((void **)&str);
		str = ft_strjoin(tmp, split[i]);
		if (split[i + 1] && add_space)
			str = addspace(str);
		if (tmp)
			ft_free((void **)&tmp);
		tmp = ft_strdup(str);
		i++;
	}
	if (tmp)
		free(tmp);
	return (str);
}
