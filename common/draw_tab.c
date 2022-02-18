/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:51:32 by lyaiche           #+#    #+#             */
/*   Updated: 2022/02/18 12:39:22 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_tab(t_data *data)
{
	int	current_x;
	int	current_y;
	int	next_x;
	int	next_y;
	int	i;
	int	j;
	int	dx;
	int	dy;

	current_x = data->init_x;
	current_y = data->init_y;
	i = -1;
	while (++i < data->width)
	{
		j = -1;
		while (++j < data->length)
		{
			next_y = data->init_y + (data->width / 2) * 9;
			next_x = data->init_x + (data->length / 2) * 16;
			
		}
	}
}
