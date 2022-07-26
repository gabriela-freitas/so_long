/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:54:16 by gafreita          #+#    #+#             */
/*   Updated: 2022/07/26 20:12:27 by gafreita         ###   ########.fr       */
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
}	t_player;
typedef struct s_so_long
{
	char		**map;
	int			width;
	int			height;
	void		*mlx;
	void		*win_mlx;
	int			pec[3];
}	t_so_long;

typedef struct s_game
{
	t_player	player;
	int			collects;
	int			steps;
}	t_game;

typedef struct s_player_mv
{
	void	*player_w[2];
	void	*player_s[2];
	void	*player_a[2];
	void	*player_d[2];
}	t_player_mv;

typedef struct s_images
{
	void		*collect;
	void		*empty;
	void		*exit;
	t_player_mv	play_mv;
	void		*player;
	void		*wall;
	void		*enemy;
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
t_game		*game(void);
void		exit_message(char *error);
void		parse_map(char *file_name);
void		game_over(char *message);
int			move_player(int keycode);
void		print_collectables(void);
void		save_collectables(void);
void		open_players(void);

#endif
