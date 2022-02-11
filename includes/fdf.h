/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:57:40 by lyaiche           #+#    #+#             */
/*   Updated: 2022/02/10 15:15:04 by lyaiche          ###   ########.fr       */
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

typedef struct s_tab{
	int		**map;
	int		lenght;
	int		width;
}				t_tab;

void	ft_printtab(t_tab *tab);
char	*get_next_line(int fd);
char	*ft_calloc_char(size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strjoin(char *s1, char *s2);
int		check(char *s, char c);
char	*ft_strdup(char *s);
void	ft_free_char(char **ptr);
void	panic_button(int error, int fd, t_tab *tab);
size_t	ft_strlen(const char *str);
char	**ft_split(const char *s, char c);
int		ft_atoi(char *num);
void	create_tab(int fd, t_tab *tab);
void	stock_map(char *name, t_tab *tab);
void	ft_free(int **ptr);
void	free_tab(t_tab *tab);
void	ft_free(int **ptr);
size_t	row_len(char *row);

#endif