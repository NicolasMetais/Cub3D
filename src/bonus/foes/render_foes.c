/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_foes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:11:27 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/17 17:11:39 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_enemy_death(t_core *core, t_foes *enemy)
{
	(void)core;
	enemy->death = 1;
	enemy->anim_death->nb = 7;
}

void	anim_death_foe(t_core *core)
{
	t_foes			*enemy;
	struct timeval	current;
	long			elapsed;
	int sprite_size;
	t_pos start;
	int screen_x;
	
	enemy = core->foes;
	while (enemy)
	{
		if (enemy->death == 1)
		{
			screen_x = (enemy->rel_angle / (core->fov * RAD)) * S_LENGHT + (S_LENGHT / 2);
			sprite_size = (int)(S_HEIGHT / enemy->dist) * 8;
			start.x = screen_x - sprite_size / 2;
			start.y = (S_HEIGHT / 2) - (sprite_size / 4);
			if (!enemy || !enemy->anim_death)
				return;
			gettimeofday(&current, NULL);
			elapsed = (current.tv_sec - enemy->anim_death->update.tv_sec) * 1000
				+ (current.tv_usec - enemy->anim_death->update.tv_usec) / 1000;
			enemy->activ_img = enemy->anim_death->img_list;
				if (enemy->dist < core->rc->dist3[screen_x])
					transparency_scaled(core->game_img, enemy->activ_img->image, start, sprite_size);
				if (elapsed > enemy->anim_death->speed && enemy->anim_death->nb > 0)
				{
					if (enemy->anim_death->img_list && enemy->anim_death->img_list->next)
					{
						enemy->anim_death->img_list = enemy->anim_death->img_list->next;
						enemy->activ_img = enemy->anim_death->img_list;
					}
					enemy->anim_death->update = current;
					enemy->anim_death->nb--;
				}
				if (enemy->anim_death->nb == 0)
					enemy->death = 2;
		}
		enemy = enemy->next;
	}
}

void	bump_enemy_enemy(t_core *core, t_foes *current)
{
	t_foes	*enemy;
	double dx;
	double dy;
	double dist;
	double knockback_strength;

	enemy = core->foes;
	while (enemy)
	{
		dx = current->foe_x - enemy->foe_x;
		dy = current->foe_y - enemy->foe_y;
		dist = sqrt(dx * dx + dy * dy);

		if (dist < 6.0 && dist > 0.001 && enemy->death == 0)
		{
			knockback_strength = 2;
			current->foe_x += (dx / dist) * knockback_strength;
			current->foe_y += (dy / dist) * knockback_strength;
		}
		enemy = enemy->next;
	}
}

void	bump_player_enemy(t_core *core)
{
	t_foes	*enemy;
	double dx;
	double dy;
	double dist;
	double knockback_strength;

	enemy = core->foes;
	while (enemy)
	{
		dx = core->rc->pl_x - enemy->foe_x;
		dy = core->rc->pl_y - enemy->foe_y;
		dist = sqrt(dx * dx + dy * dy);

		if (dist < 6.0 && dist > 0.001 && enemy->death == 0)
		{
			knockback_strength = 2;
			core->rc->pl_x += (dx / dist) * knockback_strength;
			core->rc->pl_y += (dy / dist) * knockback_strength;
		}
		enemy = enemy->next;
	}
}

bool	is_enemy(t_core *core, float x, float y)
{
	t_foes	*enemy;

	(void)y;
	enemy = core->foes;
	while (enemy)
	{
		if ((x > enemy->foe_x - 2 && x < enemy->foe_x + 2) \
			&& (y > enemy->foe_y - 2 && y < enemy->foe_y + 2))
		{
			enemy->life -= core->player->weapon[core->player->curr_wpn].damage.max;
			if (enemy->life <= 0 && enemy->death == 0)
				handle_enemy_death(core, enemy);
			return (true);
		}
		enemy = enemy->next;
	}
	return (false);
}

bool	get_number_of_foes(t_core *core)
{
	int	x;
	int	y;
	int	res;

	x = 0;
	res = 0;
	while (x < core->map_height)
	{
		y = 0;
		while (y < core->map_width)
		{
			if (core->map[x][y] == 'F')
			{
				if (!create_foes(core, res, x, y))
					return (false);
				res++;
			}
			y++;
		}
		x++;
	}
	return (true);	
}

int	foes_to_create(t_core *core)
{
	int	x;
	int	y;
	int	res;

	x = 0;
	res = 0;
	while (x < core->map_height)
	{
		y = 0;
		while (y < core->map_width)
		{
			if (core->map[x][y] == '0')
				res++;
			y++;
		}
		x++;
	}
	return (res / 40);
}

void	randomized_spawns(t_core *core)
{
	int	x;
	int	y;
	int	i;
	int	foes;
	int	random;

	x = 0;
	i = 0;
	srand(time(NULL));
	foes = foes_to_create(core);
	while (x < core->map_height)
	{
		y = 0;
		while (y < core->map_width)
		{
			random = rand() % 28;
			if (core->map[x][y] == '0' && (random == 1))
			{
				core->map[x][y] = 'F';
				i++;
				if (i == foes)
					return ;
			}
			y++;
		}
		x++;
	}
}

void	init_foe_img(t_core *core, t_foes *node)
{
	int			i;
	char		*death[8];
	//t_sprite	*init;

	node->img_foe = (t_img *)hashmap_get(&core->hashmap, "Foe");
	if (!node->img_foe)
		return ;
	i = -1;
	death[0] = "frame_death";
	death[1] = "frame_death";
	death[2] = "frame_death";
	death[3] = "frame_death";
	death[4] = "frame_death";
	death[5] = "frame_death";
	death[6] = "frame_death";
	while (++i < 8)
	{
		node->anim_death = hashmap_get(&core->hashmap_sprites, "frame_death");
		if (!node->anim_death)
			return ;
		//node->anim_death = init;
		node->anim_death->nb = 7;
		node->anim_death->timer = 0;
		node->anim_death->speed = 200;
	}
}

t_foes	*create_foe_node(t_core *core, int i, int x, int y)
{
	t_foes	*node;

	node = gc_malloc(&core->gc, sizeof(t_foes), STRUCT, "foes_list");
	if (!node)
		return (NULL);
	node->id = i;
	node->type = 0;
	node->life = 1;
	node->death = 0;
	node->pos = gc_malloc(&core->gc, sizeof(t_pos), STRUCT, "foe pos");
	if (!node->pos)
		return (NULL);
	node->pos->y = x;
	node->pos->x = y;
	node->foe_x = node->pos->x * 8 + 4;
	node->foe_y = node->pos->y * 8 + 4;
	node->angle = 2 * PI;
	node->speed = 0.1;
	node->foedelt_x = cos(node->angle);
	node->foedelt_y = sin(node->angle);
	init_foe_img(core, node);
	node->next = NULL;
	return (node);
}

bool create_foes(t_core *core, int i, int x, int y)
{
	t_foes	*node = create_foe_node(core, i, x, y);
	t_foes	*current;

	if (!node)
		return (false);
	if (!core->foes)
		core->foes = node;
	else
	{
		current = core->foes;
		while (current->next)
			current = current->next;
		current->next = node;
	}
	return (true);
}


bool	init_foes(t_core *core)
{
	randomized_spawns(core);
	get_number_of_foes(core);
	return (true);
}

static void	handle_col(t_core *core, t_foes *enemy)
{
	int		map_x;
	int		map_y;
	t_pos	new_pos;
	float 	margin_x;
	float 	margin_y;

	if (enemy->dist > 8)
	{
		new_pos.x = enemy->foe_x - cosf(enemy->angle_to_foe) * enemy->speed;
		new_pos.y = enemy->foe_y - sinf(enemy->angle_to_foe) * enemy->speed;
		margin_x = 5;
		if (enemy->foedelt_x < 0)
			margin_x = -5;
		margin_y = 5;
		if (enemy->foedelt_y < 0)
			margin_y = -5;
		map_x = (int)((new_pos.x + margin_x) / 8);
		map_y = (int)(enemy->foe_y / 8);
		if (is_map_colision(core, map_y, map_x))
			enemy->foe_x = new_pos.x;
		map_x = (int)(enemy->foe_x / 8);
		map_y = (int)((new_pos.y + margin_y) / 8);
		if (is_map_colision(core, map_y, map_x))
			enemy->foe_y = new_pos.y;
		bump_enemy_enemy(core, enemy);
	}
}

void	update_foes(t_core *core)
{
	t_foes		*enemy;

	enemy = core->foes;
	while (enemy)
	{
		if (enemy->death ==  0)
			handle_col(core, enemy);
		enemy = enemy->next;
	}
}

static void	swap_adjacent(t_foes **head, t_foes *prev, t_foes *a, t_foes *b)
{
	a->next = b->next;
	b->next = a;
	if (prev)
		prev->next = b;
	else
		*head = b;
}

void	sort_enemies_by_distance(t_foes **head)
{
	t_foes	*ptr;
	t_foes	*prev;
	t_foes	*next;
	bool	swapped;

	if (!head || !*head || !(*head)->next)
		return;
	swapped = true;
	while (swapped)
	{
		swapped = false;
		prev = NULL;
		ptr = *head;
		while (ptr && ptr->next)
		{
			if (ptr->dist < ptr->next->dist)
			{
				next = ptr->next;
				swap_adjacent(head, prev, ptr, next);
				swapped = true;
				prev = next;
			}
			else
			{
				prev = ptr;
				ptr = ptr->next;
			}
		}
	}
}


void render_foes(t_core *core)
{
	int screen_x;
	int sprite_size;
	t_pos start;
	t_foes *enemy;

	enemy = core->foes;
	while (enemy)
	{
		enemy->dx = enemy->foe_x - core->rc->pl_x;
		enemy->dy = enemy->foe_y - core->rc->pl_y;
		enemy->dist = sqrt(enemy->dx * enemy->dx + enemy->dy * enemy->dy);
		enemy = enemy->next;
	}
	sort_enemies_by_distance(&core->foes);
	enemy = core->foes;
	while (enemy)
	{
		enemy->angle_to_foe = atan2(enemy->dy, enemy->dx);
		if (enemy->angle_to_foe < -PI)
			enemy->angle_to_foe += 2 * PI;
		if (enemy->angle_to_foe > PI)
			enemy->angle_to_foe -= 2 * PI;
		enemy->rel_angle = enemy->angle_to_foe - core->rc->pl_angle;
		if (enemy->rel_angle < -PI)
			enemy->rel_angle += 2 * PI;
		if (enemy->rel_angle > PI)
			enemy->rel_angle -= 2 * PI;
		enemy->dist -= cos(enemy->rel_angle);
		screen_x = (enemy->rel_angle / (core->fov * RAD)) * S_LENGHT + (S_LENGHT / 2);
		sprite_size = (int)(S_HEIGHT / enemy->dist) * 8;
		start.x = screen_x - sprite_size / 2;
		start.y = (S_HEIGHT / 2) - (sprite_size / 4);
		if (screen_x >= 0 && screen_x < S_LENGHT)
		{
			if (enemy->dist < core->rc->dist3[screen_x] && enemy->death == false)
				transparency_scaled(core->game_img, enemy->img_foe, start, sprite_size);
		}
		enemy = enemy->next;
	}
	update_foes(core);
}
