/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:29:07 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/02 14:41:24 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_free_chartable(char **table)
{
	int	i;

	i = 0;
	while (table && table[i])
	{
		free(table[i]);
		table[i] = NULL;
		i++;
	}
	if (table)
	{
		free(table);
		table = NULL;
	}
}
