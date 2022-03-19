/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:38:30 by lyaiche           #+#    #+#             */
/*   Updated: 2022/03/19 17:50:38 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_tab(int fd, t_data *data)
{
	char	*line;

	line = get_next_line(fd);
	data->length = row_len(line, data);
	data->width = 0;
	while (line)
	{
		data->width++;
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	data->map = malloc(sizeof(int *) * data->width);
	if (!data->map)
		panic_button(2, -1, data);
}
