/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcrocq <fcrocq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 09:07:58 by fcrocq            #+#    #+#             */
/*   Updated: 2024/11/12 13:59:50 by fcrocq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WIN_HEIGHT (100 * data->map_height)
# define WIN_WIDTH (100 * data->map_width)
# define WALL '1'
# define FLOOR '0'
# define START 'P'
# define EXIT 'E'
# define ENEMY 'S'
# define COLLECT 'C'
# define SIZE 50
# include "minilibx-linux/mlx.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <X11/Xlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>

/* Structure for the game. */

typedef struct s_point {
    int x;
    int y;
} t_point;

typedef struct s_data {
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;
	void	*img_wall;
	void	*img_floor;
	void	*img_collect;
	void	*img_player_left;
	void	*img_player_right;
	void	*img_player_face;
	void	*img_player_back;
	void	*img_exit;
	void	*img_enemy;
	char	**map;
	char	*map_path;
	int		exit_access;
	int		collect_access;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		collect_x;
	int		collect_y;
	int		enemy_x;
	int		enemy_y;
	int		items;
	int		count;
	int		map_width;
	int		map_height;
	int		moves;
	void	*player_current_image;
}	t_data;

/* Structure for the map. */

typedef struct s_map
{
	char	*path;
	size_t	height;
	size_t	width;
	int		x;
	int		y;
	char	**grid;
}	t_map;


typedef	struct s_collect
{
	int	x;
	int	y;
} t_collect;


/* Initialize images. */

void	init_images(t_data *data);
void	player_enemy_to_window(t_data *data, int height, int width);
void	images_to_window(t_data *data, int height, int width);
void	put_image(t_data *data);
void	put_floor(t_data *data, int width, int height);

/* Window management. */

int		open_window(t_data *data);
int		handle_close(t_data *data);
int		close_win(int keycode, t_data *data);
void	check_exit(t_data *data);

/* Input. */

void	up(t_data *data);
void	down(t_data *data);
void	left(t_data *data);
void	right(t_data *data);
int		handle_input(int keycode, t_data *data);

/* Grid management. */

void	map_filling(t_map *grid);
void	allocate_line(t_data *data, t_map pos);
int		read_line_grid(int fd, t_data *data);
int		grid_init(t_data *data);

/* Map allocation. */

int		open_and_allocate_map(t_data *data);
int		allocate_and_copy_line(t_data *data, char *line, t_map *grid);
void	till_filling(t_data *data, int fd);


/* Map parsing. */

int		open_map_file(t_map *map);
int		check_first_line(int fd, t_map *map);
int		check_other_lines(int fd, t_map *map);
int		is_valide(t_map *map);
int		map_parsing(t_map *map);

/* Map validity. */

int		check_wall(char *map_line);
int		check_map_symbols(int fd);

/* Symbols ans screen management. */

int		check_items(t_data *data);
void	congrats_end(t_data *data);
void	display_moves(t_data *data);

/* Enemies. */

void	init_enemy(t_data *data);
int		check_collision(t_data *data);
void	hit_by_enemy(t_data *data);

/* Error display. */

void	allocation_error(t_data *data);
void	free_images(t_data *data);
void	print_error(void);

/* Error map. */

int		walls_error_i(t_data *data);
int		walls_error_j(t_data *data);
void	map_error(t_data *data, int fd);
int		close_file(int fd);

int 	handle_empty_file(int fd);
void 	check_path(t_data *data, t_point p);
int		validate_path(t_data *data);
int		check_map_requirements(int p_count, int e_count, int c_count);
int		process_line(char *line, int *p_count, int *e_count, int *c_count);
int		valid_symbol(char c);
void	update_counts(char c, int *p_count, int *e_count, int *c_count);
void	init_visited_path(int **visited, int width, int height);
int		within_boundaries(t_data *data, t_point p);
void	update_access(t_data *data, t_point p);
void	flood_fill_check(t_data *data, t_point p);
int		read_and_validate_first_line(int fd, t_map *map);
int		map_size(t_data *data);
int		check_extension(char *filename);
int 	ft_strcmp(char *s1, char *s2);
void	check_arguments(int ac, char **av);
void	init_map_path(t_map *map, char *path);
void	parse_map(t_map *map);
void	init_data_map(t_data *data, t_map *map);
void	find_player_position(t_data *data);
void	verify_paths(t_data *data);
void	init_window_and_run(t_data *data);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
void	cleanup(t_data *data);
char	*ft_strdup(const char *s);

#endif