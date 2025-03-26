#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h> 
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define BUFFER_SIZE 10

typedef struct s_data
{
	void	*mlx;
	void	*window;
	char	*filename;
	char	**map;
	int		columns;
	int		rows;
	int		collectible;
	int		exit;
	int		player;
	int		player_x;
	int		player_y;
	int		width;
	int		height;
	void	*player_up[2];
	void	*player_down[2];
	void	*player_left[2];
	void	*player_right[2];
	void	*enemy_img[2];
	void	*floor_img;
	void	*coin_img;
	void	*wall_img;
	void	*exit_img;
	int		moves_count;
	int		player_dir;
	int		player_frame;
	int		enemy_frame;
}			t_data;

void	print_map(char **map);
char	*get_next_line(int fd);
int		ft_contain(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
int		ft_strlen(char *s);
int		ft_strcmp(const char *s1, const char *s2);
int		name_check(char *filename);
int		close_window(t_data *vars);
int		close_x_window(void *ptr);
char	**read_map(t_data *data);
void	ft_putstr(char *str);
int		is_rectangle(t_data *data);
int		surrounded_by_walls(t_data *data);
int		has_required_element(t_data *data);
int		has_valid_path(t_data *data);
void	free_map(char **map, int rows);
void	exit_error(char *msg);
void	free_error(char *msg, t_data *data);
void	render_image(t_data *data);
void	load_image(t_data *data);
int		movement(int keycode, t_data *data);
void	free_image(t_data *data);
char	*ft_itoa(int n);
void	put_moves(t_data *data);
void	ft_victory(t_data *data);
void	ft_lose(t_data *data);

#endif
