#include "../includes/header.h"

static int	mouse_events(int key, int x, int y, t_utils *utils)
{
	(void) key,
	(void) x;
	(void) y;
	(void) utils;

	printf("key = [%d]\n", key);
	change_camera_direction(utils, x, y);
	return (1);
}

int	key_events(int key, t_utils *utils)
{	
    printf("Key = [%d]\n", key);
    if (key == 65307)
	{
        exit(0);
	}
	change_camera_position(key, utils);
	return (0);
}

static int main_loop(t_utils *utils)
{
	clock_t start;
	char	*render_time;


	
	(void) utils,
	start = clock();
	render_image(utils);
	render_time = ft_itoa(roundf(clock() - start) / 1000);
	mlx_put_image_to_window(utils->vars->mlx_ptr, utils->vars->win_ptr, utils->img->img_ptr, 0, 0);
	mlx_string_put(utils->vars->mlx_ptr, utils->vars->win_ptr, 1, 10, 0xFF0000, "Render time ");
	mlx_string_put(utils->vars->mlx_ptr, utils->vars->win_ptr, 75, 10, 0xFF0000, render_time);
	free(render_time);
	return (0);
}

int	close_window(int keycode, t_utils *u)
{
	(void) keycode;
	t_utils *utils = u;
	mlx_destroy_window(utils->vars->mlx_ptr, utils->vars->win_ptr);
	return (0);
}


void	event_handler(t_utils *utils)
{
	//mlx_mouse_hook(utils->vars->win_ptr, mouse_events, utils);
    //mlx_key_hook(utils->vars->win_ptr, key_events, utils);
	//mlx_hook(utils->vars->win_ptr, 2, 1L<<0, close_window, utils);
	mlx_hook(utils->vars->win_ptr, ON_MOUSEDOWN, 1L<<2, mouse_events, utils);
	mlx_hook(utils->vars->win_ptr, ON_KEYDOWN, 1L<<0, key_events, utils);
	mlx_loop_hook(utils->vars->mlx_ptr, main_loop, utils);
	mlx_loop(utils->vars->mlx_ptr);
}