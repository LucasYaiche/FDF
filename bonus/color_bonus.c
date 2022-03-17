/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:51:36 by lyaiche           #+#    #+#             */
/*   Updated: 2022/03/17 16:57:26 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	color(t_data *data)
{
	if (data->color == 0)
		return (0xFFFFFF);
	else if (data->color == 1)
		return (0xF8FF00);
	else if (data->color == 2)
		return (0x4BFF00);
	else if (data->color == 3)
		return (0x00FFAC);
	else if (data->color == 4)
		return (0x00E6FF);
	else if (data->color == 5)
		return (0x0044FF);
	else if (data->color == 6)
		return (0x8C00FF);
	else if (data->color == 7)
		return (0xF000FF);
	else if (data->color == 8)
		return (0xFF0000);
	else if (data->color == 9)
	{
		data->color = 0;
		return (0xFF8700);
	}
	return (0xFFFFFF);
}
