/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:57:38 by lyaiche           #+#    #+#             */
/*   Updated: 2022/03/19 18:11:42 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_tab(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->width)
		if (data->map[i])
			ft_free(&data->map[i]);
	free(data->map);
}
