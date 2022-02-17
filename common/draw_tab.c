/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:51:32 by lyaiche           #+#    #+#             */
/*   Updated: 2022/02/17 19:32:45 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_tab(t_data *data)
{
	int	current_x;
	int	current_y;
	int	next_x;
	int	next_y;

	current_x = data->init_x;
	current_y = data->init_y;
	next_x = data->init_x + data->lenght / 2 * 16;
	next_y = data->init_y + data->width / 2 * 9;
	data->addr[next_y * data->line_bytes + next_x] = 0xff0000;
}
