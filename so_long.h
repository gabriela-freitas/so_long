/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:54:16 by gafreita          #+#    #+#             */
/*   Updated: 2022/07/25 19:41:25 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# define PX 32

typedef struct s_player
{
	int		x;
	int		y;
	int		move;
}	t_player;

typedef struct s_so_long
{
	char		**map;
	int			width;
	int			height;
	void		*mlx;
	void		*win_mlx;
	int			keys[255];
	t_player	player;
}	t_so_long;

typedef struct s_images
{
	void	*collect;
	void	*empty;
	void	*exit;
	void	*player;
	void	*wall;
}	t_images;


enum e_keys{
	key_W = 119,
	key_S = 115,
	key_A = 97,
	key_D = 100,
	key_ESC = 65307
};

t_so_long	*infos(void);
t_images	*img(void);
void		exit_message(char *error);
void		parse_map(char *file_name);
void		game_over(char *message);
int			move_player(int keycode);

#endif
