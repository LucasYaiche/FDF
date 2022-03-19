/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:36:00 by lyaiche           #+#    #+#             */
/*   Updated: 2022/03/19 17:56:49 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	row_len(char *row, t_data *data)
{
	size_t	i;
	int		j;
	char	**result;

	if (!row)
		panic_button(3, -1, data);
	result = ft_split(row, ' ');
	if (!result)
		panic_button(2, -1, data);
	i = 0;
	while (result[i])
		i++;
	j = i;
	free_row(result, i);
	return (i);
}
