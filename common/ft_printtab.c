/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:45:05 by lyaiche           #+#    #+#             */
/*   Updated: 2022/02/10 15:27:29 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_printtab(t_tab *tab)
{
	int	i;
	int	j;

	i = -1;
	while (++i < tab->lenght)
	{
		j = -1;
		while (++j < tab->width)
			printf("%i ", tab->map[i][j]);
		printf("\n");
	}
	printf("lenght = %i\n", tab->lenght);
	printf("width = %i\n", tab->width);
}
