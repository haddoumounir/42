#include  "fract_ol.h"
void destroy(windo_info *data , int code)
{
    if(code == 1)
    {
        mlx_destroy_window(data->mlx,data->mlx_win);
        ft_free(data->mlx_win);
        data->mlx_win = NULL;
        if(data->fractol_name)
            ft_free(data->fractol_name);
    }
    if(code == 2)
    {
        mlx_destroy_window(data->mlx,data->mlx_win);
        mlx_destroy_display(data->mlx);
        // ft_free(data->mlx_win);
        // data->mlx_win = NULL;
        ft_free(data->mlx);
        // data->mlx = NULL;
        if(data->fractol_name)
            ft_free(data->fractol_name);
    }
    exit(1);
}
int handle_hook(int XK, windo_info *data)
{
    if(XK == XK_Escape)
        destroy(data,2);
        //"ida 3adk up etc ... dir chi hajat 5arin"
    // if(XK == XK_Up)
    // if(XK == XK_Down)
    // if(XK == XK_Right)
    // if(XK == XK_Left)



    return 0;
}

int pre_mlx(char *fractal_name)
{
    windo_info data;
    img_s img;
	data.mlx =mlx_init();
    data.fractol_name = ft_strjoin("fractol:  ",fractal_name);
    if(!data.mlx)
        return(free(data.fractol_name),1);
    if (!data.fractol_name)
        return(free(data.mlx),1);
    data.mlx_win = mlx_new_window(data.mlx, WIDTH, HEIGHT, data.fractol_name);
    if(!data.mlx_win)
        return (free(data.mlx),free(data.fractol_name),1);
    mlx_key_hook(data.mlx_win, handle_hook, &data);
    mlx_loop(data.mlx);
    img.img_ptr = mlx_new_image(data.mlx,WIDTH,HEIGHT);
    if(!img.img_ptr)
        return (destroy(&data,3),1);
    return(0);
}
