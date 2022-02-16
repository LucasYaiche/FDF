/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:45:05 by lyaiche           #+#    #+#             */
/*   Updated: 2022/02/14 17:35:16 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_printtab(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->lenght)
	{
		j = -1;
		while (++j < data->width)
			printf("%i ", data->map[i][j]);
		printf("\n");
	}
	printf("lenght = %i\n", data->lenght);
	printf("width = %i\n", data->width);
}
