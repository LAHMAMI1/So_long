/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:54:09 by olahmami          #+#    #+#             */
/*   Updated: 2023/01/11 17:12:09 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include "Libft/libft.h"
#include <stdio.h>

typedef struct s_show
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	int		w;
	int		h;
}	t_show;

typedef struct s_player
{
	int	pos_x;
	int	pos_y;
	int m_x;
	int m_y;
}	t_player;

typedef struct s_map
{
	char		*str;
	char		**split_map;
	int			y;
	int			x;
	int			lines;
	int			len;
	char		**dup_map;
	int			count[4];
	int			check_c;
	int			keycode;
	int			mov;
	t_show		*show;
	t_player	*player;
}	t_map;

/*So_long*/
char	**read_map(int fd, t_map *map);
int		composed_map(t_map *map);
int		onechar_map(t_map *map, t_player *player);
int		rectangular_map(t_map *map);
int		no_line(t_map *map);
int		wall_map(t_map *map);
void	flood_fill_p(int pos_x, int pos_y, char **map);
void	flood_fill_e(int pos_x, int pos_y, char **map);
int		check_path(t_map *map, char c);
int		name_map(char *name);
void	all_check(t_map *map, t_player *player);
void	put_img(t_map *map, char *path_img, char c);
void	showmap(t_map *map);
int		move_map(int keycode, t_map *map);
int		count_line(t_map *map);
char	**map_dup(t_map *map);
int		ft_strchr_wm(char *split_map, int c);
void	move_patrol(int m_x, int m_y, t_map *map);
int move_m(t_map *map);

#endif