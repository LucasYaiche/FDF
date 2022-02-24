/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:36:00 by lyaiche           #+#    #+#             */
/*   Updated: 2022/02/24 12:59:54 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	row_len(char *row, t_data *data)
{
	size_t	i;
	int		j;
	char	**result;

	i = 0;
	result = ft_split(row, ' ');
	if (!row)
		panic_button(3, -1, data);
	while (result[i])
		i++;
	j = i;
	while (result[j])
		free(result[--j]);
	return (i);
}
