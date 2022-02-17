/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:57:40 by lyaiche           #+#    #+#             */
/*   Updated: 2022/02/17 19:34:59 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_data{
	int		**map;
	int		lenght;
	int		width;
	char	*name;
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_bytes;
	int		endian;
	void	*mlx;
	void	*win;
	int		middle;
	int		start;
	int		init_x;
	int		init_y;
}				t_data;

void	ft_printtab(t_data *data);
char	*get_next_line(int fd);
char	*ft_calloc_char(size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strjoin(char *s1, char *s2);
int		check(char *s, char c);
char	*ft_strdup(char *s);
void	ft_free_char(char **ptr);
void	panic_button(int error, int fd, t_data *data);
size_t	ft_strlen(const char *str);
char	**ft_split(const char *s, char c);
int		ft_atoi(char *num);
void	create_tab(int fd, t_data *data);
void	stock_map(t_data *data);
void	ft_free(int **ptr);
void	free_tab(t_data *data);
void	ft_free(int **ptr);
size_t	row_len(char *row);
void	initiate_window(t_data *tab);
void	end(t_data *data);
int		key_hook(int keycode, t_data *data);
void	draw_tab(t_data *data);

#endif