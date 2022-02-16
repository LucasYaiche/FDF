/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:38:30 by lyaiche           #+#    #+#             */
/*   Updated: 2022/02/14 17:37:48 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_tab(int fd, t_data *data)
{
	char	*line;

	line = "";
	while (line != NULL)
	{
		data->width = row_len(line);
		line = get_next_line(fd);
		if (line)
			data->lenght++;
	}
	close(fd);
	data->map = malloc(sizeof(int *) * data->lenght + 1);
	if (!data->map)
		panic_button(2, -1, data);
}
