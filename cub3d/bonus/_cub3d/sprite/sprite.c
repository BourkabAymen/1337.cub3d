/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 11:02:22 by mbel-bas          #+#    #+#             */
/*   Updated: 2022/06/01 13:04:34 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	set_tex_to_sprite(t_prog *p)
{
	t_sprite	**s;

	s = p->sprites;
	while (*s)
	{
		if ((*s)->k == 'e')
			enemy_e(p, *s);
		else if ((*s)->k == 'm')
			enemy_m(p, *s);
		else if ((*s)->k == 'h')
			heal_sprite(p, *s);
		else if ((*s)->k == 'b')
			bullet_sprite(p, *s);
		else
			normal_sprite(p, *s);
		s++;
	}
}

int	tr_c(int c, int h, int k, int f)
{
	int	r;
	int	g;
	int	b;

	if (h > 0 && (k == 'e' || k == 'm') && f % 4 == 0)
	{
		r = ((c >> 16) & 255) * 0.6 + 255 * 0.4;
		g = ((c >> 8) & 255) * 0.6 + 255 * 0.4;
		b = (c & 255) * 0.6 + 255 * 0.4;
		return (r << 16 | g << 8 | b);
	}
	return (c);
}

void sprite(t_prog *prog, double *ZBuffer)
{
	t_player	*p;
	int			i;
	t_sprite	**sprites;
	double		spriteX;
	double		spriteY;
	double		invDet;
	double		transformX;
	double		transformY;
	int			spriteScreenX;
	int			spriteHeight;
	int			drawStartY;
	int			drawEndY;
	int			spriteWidth;
	int			drawStartX;
	int			drawEndX;
	int			stripe;
	int			texX;
	int			texY;
	int			y;
	int			d;
	int			color;
	float		health_bar;

	p = &prog->player;
	sort_sprites(prog->sprites, &prog->player);
	set_tex_to_sprite(prog);
	sprites = prog->sprites;
	
	i = -1;
	while (sprites[++i])
	{
		if (sprites[i]->k == 'h' && sprites[i]->health <= 0)
			continue ;
		spriteX = sprites[i]->x - p->x;
		spriteY = sprites[i]->y - p->y;
		invDet = 1.0 / (p->plane_x * p->dir_y - p->dir_x * p->plane_y);
		transformX = invDet * (p->dir_y * spriteX - p->dir_x * spriteY);
		transformY = invDet * (-p->plane_y * spriteX + p->plane_x * spriteY);
		int vMoveScreen = (int)((0) / transformY);

		spriteScreenX = (int)((WIDTH / 2) * (1 + transformX / transformY));
		spriteHeight = abs((int)((HEIGHT) / transformY));
		drawStartY = -spriteHeight / 2  + HEIGHT / 2 + vMoveScreen;
		if (drawStartY < 0)
			drawStartY = 0;
		drawEndY = spriteHeight / 2 + HEIGHT / 2 + vMoveScreen;
		if(drawEndY >= HEIGHT)
			drawEndY = HEIGHT -1;
		spriteWidth = abs((int)(HEIGHT / (transformY)));
		drawStartX = -spriteWidth / 2 + spriteScreenX;
		if(drawStartX < 0)
		 	drawStartX = 0;
		drawEndX = spriteWidth / 2 + spriteScreenX;
		if(drawEndX >= WIDTH)
			drawEndX = WIDTH - 1;
		stripe = drawStartX;

		if ((sprites[i]->k == 'e' || sprites[i]->k == 'm') && sprites[i]->health > 0)
		{
			if (sprites[i]->k == 'e')
				health_bar = sprites[i]->health / E_HEALTH;
			if (sprites[i]->k == 'm')
				health_bar = sprites[i]->health / M_HEALTH;
			while (stripe < drawEndX)
			{
				if (transformY > 0 && stripe > 0 && stripe < WIDTH && transformY < ZBuffer[stripe])
				{
					ft_put_pixel(stripe, drawStartY + HEIGHT / 2 - prog->m_y + 2, 0xff0000);
					ft_put_pixel(stripe, drawStartY + HEIGHT / 2 - prog->m_y + 1, 0xff0000);
					if ((1.0 * stripe - drawStartX) / (drawEndX - drawStartX) > health_bar)
						break ;
				}
				stripe++;
			}
		}

		stripe = drawStartX;
		
		while (stripe < drawEndX)
		{
			texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * sprites[i]->tex->width / spriteWidth) / 256;
			if(transformY > 0 && stripe > 0 && stripe < WIDTH && transformY < ZBuffer[stripe])
			{
				y = drawStartY;
				while (y < drawEndY)
				{
					d = (y) * 256 - (HEIGHT) * 128 + spriteHeight * 128;
					texY = ((d * sprites[i]->tex->height) / spriteHeight) / 256;
					color = get_tex_color(sprites[i]->tex, texX, texY);
					if((color & 0x00FFFFFF) != 0)
						ft_put_pixel(stripe, y + HEIGHT / 2 - prog->m_y, tr_c(color, sprites[i]->hit, sprites[i]->k, prog->frame));
					y++;
				}
			}
			stripe++;	
		}
		sprites[i]->hit--;
	}
}
