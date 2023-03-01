/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:35:07 by jmorneau          #+#    #+#             */
/*   Updated: 2022/11/05 18:30:11 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*extra_buffer(char *str)
// {
// 	int		i;
// 	char	*new_str;

// 	i = 0;
// 	new_str = ft_calloc(ft_strlen(str) + 1000, 1);
// 	while (str[i])
// 	{
// 		new_str[i] = str[i];
// 		i++;
// 	}
// 	free (str);
// 	return (new_str);
// }

// char	*get_next_line(int fd)
// {
// 	t_u			u;
// 	char		character;
// 	char		*buffer;

// 	u.i = 0;
// 	u.j = 1;
// 	buffer = ft_calloc(1002, sizeof(char));
// 	while (1)
// 	{
// 		u.j = read(fd, &character, 1);
// 		if (!u.j)
// 			break ;
// 		buffer[u.i++] = character;
// 		if (character == '\n')
// 			break ;
// 		if (u.i > (u.i / 1000) * 1000)
// 			buffer = extra_buffer(buffer);
// 	}
// 	if ((!buffer[u.i - 1] && !u.j) || u.j == -1)
// 	{
// 		free (buffer);
// 		return (NULL);
// 	}
// 	buffer[u.i] = '\0';
// 	return (buffer);
// }


char *get_next_line(int fd)
{
    int 	i = 0;
    int 	rd = 0;
    char	character;
    char 	*buffer = malloc(10000);

    while ((rd = read(fd, &character, 1)) > 0)
    {
        buffer[i++] = character;
        if (character == '\n')
            break;
    }
    if ((!buffer[i - 1] && !rd) || rd == -1)
    {
        free(buffer);
        return (NULL);
    }
    buffer[i] =  '\0';
    return(buffer);
}

