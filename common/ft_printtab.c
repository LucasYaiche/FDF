/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:45:05 by lyaiche           #+#    #+#             */
/*   Updated: 2022/02/18 11:48:44 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_printtab(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->width)
	{
		j = -1;
		while (++j < data->length)
			printf("%i ", data->map[i][j]);
		printf("\n");
	}
	printf("length = %i\n", data->length);
	printf("width = %i\n", data->width);
}
