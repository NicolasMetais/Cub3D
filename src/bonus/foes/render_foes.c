/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_foes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:11:27 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/21 19:16:36 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_enemy_death(t_core *core, t_foes *enemy)
{
	(void)core;
	enemy->death = 1;
	//enemy->anim_death->nb = 7;
}

void	anim_attack_foe(t_core *core)
{
	t_foes			*enemy;
	struct timeval	current;
	long			elapsed;
	
	enemy = core->foes;
	while (enemy)
	{
		if (enemy->death == 0 && enemy->atk == 1)
		{
			if (!enemy || !enemy->attack)
				return;
			gettimeofday(&current, NULL);
			elapsed = (current.tv_sec - enemy->attack->update.tv_sec) * 1000
				+ (current.tv_usec - enemy->attack->update.tv_usec) / 1000;
			enemy->activ_img = enemy->attack->img_list;
				if (elapsed > enemy->attack->speed)
				{
					if (enemy->attack->img_list && enemy->attack->img_list->next)
					{
						enemy->attack->img_list = enemy->attack->img_list->next;
						enemy->activ_img = enemy->attack->img_list;
					}
					enemy->attack->update = current;
					if (enemy->atk == 1)
						core->player->health -= 1;
				}
		}
		enemy = enemy->next;
	}
}

void	anim_walk_foe(t_core *core)
{
	t_foes			*enemy;
	struct timeval	current;
	long			elapsed;
	
	enemy = core->foes;
	while (enemy)
	{
		if (enemy->death == 0 && enemy->atk == 0)
		{
			if (!enemy || !enemy->walking)
				return;
			gettimeofday(&current, NULL);
			elapsed = (current.tv_sec - enemy->walking->update.tv_sec) * 1000
				+ (current.tv_usec - enemy->walking->update.tv_usec) / 1000;
			enemy->activ_img = enemy->walking->img_list;
				if (elapsed > enemy->walking->speed)
				{
					if (enemy->walking->img_list && enemy->walking->img_list->next)
					{
						enemy->walking->img_list = enemy->walking->img_list->next;
						enemy->activ_img = enemy->walking->img_list;
					}
					enemy->walking->update = current;
				}
		}
		enemy = enemy->next;
	}
}

void	anim_death_foe(t_core *core)
{
	t_foes			*enemy;
	struct timeval	current;
	long			elapsed;
	
	enemy = core->foes;
	while (enemy)
	{
		if (enemy->death == 1)
		{
			if (!enemy || !enemy->anim_death)
				return;
			gettimeofday(&current, NULL);
			elapsed = (current.tv_sec - enemy->anim_death->update.tv_sec) * 1000
				+ (current.tv_usec - enemy->anim_death->update.tv_usec) / 1000;
			enemy->activ_img = enemy->anim_death->img_list;
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
	srand(time(NULL));
	while (x < core->map_height)
	{
		y = 0;
		while (y < core->map_width)
		{
			if (core->map[x][y] == 'F')
			{
				res = rand() % 7;
				if (!create_foes(core, res, x, y))
					return (false);
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
			random = rand() % 32;
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

t_sprite	*copy_sprite(t_core *core, t_sprite *src, int i)
{
	t_sprite	*new_sprite;

	if (!src)
		return (NULL);
	new_sprite = gc_malloc(&core->gc, sizeof(t_sprite), STRUCT, "new_sprite_foe");
	if (!new_sprite)
		return (NULL);
	new_sprite->nb = src->nb;
	new_sprite->speed = src->speed;
	new_sprite->timer = 0;

	new_sprite->img_list = gc_malloc(&core->gc, sizeof(t_node_img), STRUCT, "copy_sprite_foe");
	if (!new_sprite->img_list)
		return (NULL);
	new_sprite->nb = i;
	new_sprite->img_list = src->img_list;
	return (new_sprite);
}

void	init_head_attack_list(t_core *core, t_foes *node)
{
	char		*atk[2];
	t_sprite	*init;

	atk[0] = "head_attack";
	atk[1] = "head_attack";
	init = hashmap_get(&core->hashmap_sprites, "head_attack");
	if (!init)
		return ;
	node->attack = copy_sprite(core, init, 0);
	node->attack->timer = 0;
	node->attack->speed = node->atk_speed;
}

void	init_head_walking_list(t_core *core, t_foes *node)
{
	char		*walk[3];
	t_sprite	*init;

	walk[0] = "head_walking";
	walk[1] = "head_walking";
	walk[2] = "head_walking";
	init = hashmap_get(&core->hashmap_sprites, "head_walking");
	if (!init)
		return ;
	node->walking = copy_sprite(core, init, 0);
	node->walking->timer = 0;
	node->walking->speed = node->walk_speed;
}

void	init_head_death_list(t_core *core, t_foes *node)
{
	char		*death[6];
	t_sprite	*init;

	death[0] = "head_frame_death";
	death[1] = "head_frame_death";
	death[2] = "head_frame_death";
	death[3] = "head_frame_death";
	death[4] = "head_frame_death";
	death[5] = "head_frame_death";
	init = hashmap_get(&core->hashmap_sprites, "head_frame_death");
	if (!init)
		return ;
	node->anim_death = copy_sprite(core, init, 6);
	node->anim_death->timer = 0;
	node->anim_death->speed = 200;
}

void	init_play_attack_list(t_core *core, t_foes *node)
{
	char		*atk[2];
	t_sprite	*init;

	atk[0] = "play_attack";
	atk[1] = "play_attack";
	init = hashmap_get(&core->hashmap_sprites, "play_attack");
	if (!init)
		return ;
	node->attack = copy_sprite(core, init, 0);
	node->attack->timer = 0;
	node->attack->speed = node->atk_speed;
}

void	init_play_walking_list(t_core *core, t_foes *node)
{
	char		*walk[4];
	t_sprite	*init;

	walk[0] = "play_walking";
	walk[1] = "play_walking";
	walk[2] = "play_walking";
	walk[3] = "play_walking";
	init = hashmap_get(&core->hashmap_sprites, "play_walking");
	if (!init)
		return ;
	node->walking = copy_sprite(core, init, 0);
	node->walking->timer = 0;
	node->walking->speed = node->walk_speed;
}

void	init_play_death_list(t_core *core, t_foes *node)
{
	char		*death[6];
	t_sprite	*init;

	death[0] = "play_frame_death";
	death[1] = "play_frame_death";
	death[2] = "play_frame_death";
	death[3] = "play_frame_death";
	death[4] = "play_frame_death";
	death[5] = "play_frame_death";
	init = hashmap_get(&core->hashmap_sprites, "play_frame_death");
	if (!init)
		return ;
	node->anim_death = copy_sprite(core, init, 6);
	node->anim_death->timer = 0;
	node->anim_death->speed = 200;
}

void	init_poss_attack_list(t_core *core, t_foes *node)
{
	char		*atk[2];
	t_sprite	*init;

	atk[0] = "poss_attack";
	atk[1] = "poss_attack";
	init = hashmap_get(&core->hashmap_sprites, "poss_attack");
	if (!init)
		return ;
	node->attack = copy_sprite(core, init, 0);
	node->attack->timer = 0;
	node->attack->speed = node->atk_speed;
}

void	init_poss_walking_list(t_core *core, t_foes *node)
{
	char		*walk[4];
	t_sprite	*init;

	walk[0] = "poss_walking";
	walk[1] = "poss_walking";
	walk[2] = "poss_walking";
	walk[3] = "poss_walking";
	init = hashmap_get(&core->hashmap_sprites, "poss_walking");
	if (!init)
		return ;
	node->walking = copy_sprite(core, init, 0);
	node->walking->timer = 0;
	node->walking->speed = node->walk_speed;
}

void	init_poss_death_list(t_core *core, t_foes *node)
{
	char		*death[7];
	t_sprite	*init;

	death[0] = "poss_frame_death";
	death[1] = "poss_frame_death";
	death[2] = "poss_frame_death";
	death[3] = "poss_frame_death";
	death[4] = "poss_frame_death";
	death[5] = "poss_frame_death";
	death[6] = "poss_frame_death";
	init = hashmap_get(&core->hashmap_sprites, "poss_frame_death");
	if (!init)
		return ;
	node->anim_death = copy_sprite(core, init, 7);
	node->anim_death->timer = 0;
	node->anim_death->speed = 200;
}

void	init_sarg_attack_list(t_core *core, t_foes *node)
{
	char		*atk[2];
	t_sprite	*init;

	atk[0] = "sarg_attack";
	atk[1] = "sarg_attack";
	init = hashmap_get(&core->hashmap_sprites, "sarg_attack");
	if (!init)
		return ;
	node->attack = copy_sprite(core, init, 0);
	node->attack->timer = 0;
	node->attack->speed = node->atk_speed;
}

void	init_sarg_walking_list(t_core *core, t_foes *node)
{
	char		*walk[4];
	t_sprite	*init;

	walk[0] = "sarg_walking";
	walk[1] = "sarg_walking";
	walk[2] = "sarg_walking";
	walk[3] = "sarg_walking";
	init = hashmap_get(&core->hashmap_sprites, "sarg_walking");
	if (!init)
		return ;
	node->walking = copy_sprite(core, init, 0);
	node->walking->timer = 0;
	node->walking->speed = node->walk_speed;
}

void	init_sarg_death_list(t_core *core, t_foes *node)
{
	char		*death[5];
	t_sprite	*init;

	death[0] = "sarg_frame_death";
	death[1] = "sarg_frame_death";
	death[2] = "sarg_frame_death";
	death[3] = "sarg_frame_death";
	death[4] = "sarg_frame_death";
	init = hashmap_get(&core->hashmap_sprites, "sarg_frame_death");
	if (!init)
		return ;
	node->anim_death = copy_sprite(core, init, 5);
	node->anim_death->timer = 0;
	node->anim_death->speed = 200;
}

void	init_skul_attack_list(t_core *core, t_foes *node)
{
	char		*atk[2];
	t_sprite	*init;

	atk[0] = "skul_attack";
	atk[1] = "skul_attack";
	init = hashmap_get(&core->hashmap_sprites, "skul_attack");
	if (!init)
		return ;
	node->attack = copy_sprite(core, init, 0);
	node->attack->timer = 0;
	node->attack->speed = node->atk_speed;
}

void	init_skul_walking_list(t_core *core, t_foes *node)
{
	char		*walk[2];
	t_sprite	*init;

	walk[0] = "skul_walking";
	walk[1] = "skul_walking";
	init = hashmap_get(&core->hashmap_sprites, "skul_walking");
	if (!init)
		return ;
	node->walking = copy_sprite(core, init, 0);
	node->walking->timer = 0;
	node->walking->speed = node->walk_speed;
}

void	init_skul_death_list(t_core *core, t_foes *node)
{
	char		*death[4];
	t_sprite	*init;

	death[0] = "skul_frame_death";
	death[1] = "skul_frame_death";
	death[2] = "skul_frame_death";
	death[3] = "skul_frame_death";
	init = hashmap_get(&core->hashmap_sprites, "skul_frame_death");
	if (!init)
		return ;
	node->anim_death = copy_sprite(core, init, 4);
	node->anim_death->timer = 0;
	node->anim_death->speed = 200;
}

void	init_cybr_attack_list(t_core *core, t_foes *node)
{
	char		*atk[2];
	t_sprite	*init;

	atk[0] = "cybr_attack";
	atk[1] = "cybr_attack";
	init = hashmap_get(&core->hashmap_sprites, "cybr_attack");
	if (!init)
		return ;
	node->attack = copy_sprite(core, init, 0);
	node->attack->timer = 0;
	node->attack->speed = node->atk_speed;
}

void	init_cybr_walking_list(t_core *core, t_foes *node)
{
	char		*walk[4];
	t_sprite	*init;

	walk[0] = "cybr_walking";
	walk[1] = "cybr_walking";
	walk[2] = "cybr_walking";
	walk[3] = "cybr_walking";
	init = hashmap_get(&core->hashmap_sprites, "cybr_walking");
	if (!init)
		return ;
	node->walking = copy_sprite(core, init, 0);
	node->walking->timer = 0;
	node->walking->speed = node->walk_speed;
}

void	init_cybr_death_list(t_core *core, t_foes *node)
{
	char		*death[8];
	t_sprite	*init;

	death[0] = "cybr_frame_death";
	death[1] = "cybr_frame_death";
	death[2] = "cybr_frame_death";
	death[3] = "cybr_frame_death";
	death[4] = "cybr_frame_death";
	death[5] = "cybr_frame_death";
	death[6] = "cybr_frame_death";
	init = hashmap_get(&core->hashmap_sprites, "cybr_frame_death");
	if (!init)
		return ;
	node->anim_death = copy_sprite(core, init, 7);
	node->anim_death->timer = 0;
	node->anim_death->speed = 200;
}

void	init_head_list(t_core *core, t_foes *node)
{
	node->life = 1;
	node->speed = 0.1;
	node->range = 12;
	node->atk_speed = 200;
	node->walk_speed = 300;
	node->damage = 15;
	init_head_walking_list(core, node);
	init_head_attack_list(core, node);
	init_head_death_list(core, node);
}

void	init_play_list(t_core *core, t_foes *node)
{
	node->life = 1;
	node->speed = 0.1;
	node->range = 24;
	node->atk_speed = 200;
	node->walk_speed = 300;
	node->damage = 1;
	init_play_walking_list(core, node);
	init_play_attack_list(core, node);
	init_play_death_list(core, node);
}

void	init_poss_list(t_core *core, t_foes *node)
{
	node->life = 1;
	node->speed = 0.1;
	node->range = 24;
	node->atk_speed = 200;
	node->walk_speed = 300;
	node->damage = 1;
	init_poss_walking_list(core, node);
	init_poss_attack_list(core, node);
	init_poss_death_list(core, node);
}

void	init_sarg_list(t_core *core, t_foes *node)
{
	node->life = 1;
	node->speed = 0.2;
	node->range = 12;
	node->atk_speed = 200;
	node->walk_speed = 300;
	node->damage = 15;
	init_sarg_walking_list(core, node);
	init_sarg_attack_list(core, node);
	init_sarg_death_list(core, node);
}

void	init_skul_list(t_core *core, t_foes *node)
{
	node->life = 1;
	node->speed = 0.3;
	node->range = 8;
	node->atk_speed = 200;
	node->walk_speed = 300;
	node->damage = 50;
	init_skul_walking_list(core, node);
	init_skul_attack_list(core, node);
	init_skul_death_list(core, node);
}

void	init_cybr_list(t_core *core, t_foes *node)
{
	node->life = 1;
	node->speed = 0.1;
	node->range = 24;
	node->atk_speed = 200;
	node->walk_speed = 300;
	node->damage = 4;
	init_cybr_walking_list(core, node);
	init_cybr_attack_list(core, node);
	init_cybr_death_list(core, node);
}

void	init_foe_img(t_core *core, t_foes *node)
{
	if (node->type == 1)
		init_cybr_list(core, node);
	else if (node->type == 2)
		init_head_list(core, node);
	else if (node->type == 3)
		init_poss_list(core, node);
	else if (node->type == 4)
		init_play_list(core, node);
	else if (node->type == 5)
		init_sarg_list(core, node);
	else
		init_skul_list(core, node);
	node->activ_img = node->walking->img_list;
}

t_foes	*create_foe_node(t_core *core, int i, int x, int y)
{
	t_foes	*node;

	node = gc_malloc(&core->gc, sizeof(t_foes), STRUCT, "foes_list");
	if (!node)
		return (NULL);
	node->type = i;
	node->id = i;
	node->death = 0;
	node->attack = 0;
	node->pos = gc_malloc(&core->gc, sizeof(t_pos), STRUCT, "foe pos");
	if (!node->pos)
		return (NULL);
	node->pos->y = x;
	node->pos->x = y;
	node->foe_x = node->pos->x * 8 + 4;
	node->foe_y = node->pos->y * 8 + 4;
	node->angle = 2 * PI;
	node->foedelt_x = cos(node->angle);
	node->foedelt_y = sin(node->angle);
	init_foe_img(core, node);
	node->next = NULL;
	return (node);
}

bool create_foes(t_core *core, int i, int x, int y)
{
	t_foes	*node;
	t_foes	*current;

	node = create_foe_node(core, i, x, y);
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


bool	can_see_player(t_core *core, float ex, float ey)
{
	float	dx;
	float	dy;
	float	dist;
	float	step_x;
	float	step_y;
	int		i;

	dx = core->rc->pl_y - ex;
	dy = core->rc->pl_x - ey;
	dist = sqrtf(dx * dx + dy * dy);
	step_x = dx / dist;
	step_y = dy / dist;
	i = 0;
	while (i < (int)dist)
	{
		int map_x = (int)(ex / 8);
		int map_y = (int)(ey / 8);
		if (seen_colision(core, map_x, map_y))
			return (false);
		ex += step_x;
		ey += step_y;
		i++;
	}
	return (true);
}

static void	handle_col(t_core *core, t_foes *enemy)
{
	int		map_x;
	int		map_y;
	t_pos	new_pos;
	float 	margin_x;
	float 	margin_y;
	int		ray;

	if (core->rc->ra == enemy->angle_to_foe)
		ray = core->rc->r;
	if (enemy->dist < enemy->range && can_see_player(core, enemy->foe_y, enemy->foe_x))
		enemy->atk = 1;
	else
		enemy->atk = 0;
	if (enemy->dist < 128 && enemy->dist > 8 && enemy->atk == 0)
	{
		new_pos.x = enemy->foe_x - cosf(enemy->angle_to_foe) * enemy->speed;
		new_pos.y = enemy->foe_y - sinf(enemy->angle_to_foe) * enemy->speed;
		margin_x = 2;
		if (enemy->foedelt_x < 0)
			margin_x = -2;
		margin_y = 2;
		if (enemy->foedelt_y < 0)
			margin_y = -2;
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
	anim_walk_foe(core);
	anim_attack_foe(core);
	anim_death_foe(core);
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
			if (enemy->dist < core->rc->dist3[screen_x] && enemy->death == 0)
				transparency_scaled(core->game_img, enemy->activ_img->image, start, sprite_size);
			else if (enemy->dist < core->rc->dist3[screen_x] && enemy->atk == 1 && enemy->death == 0)
				transparency_scaled(core->game_img, enemy->activ_img->image, start, sprite_size);
			else if (enemy->dist < core->rc->dist3[screen_x] && enemy->death == 1)
				transparency_scaled(core->game_img, enemy->activ_img->image, start, sprite_size);
		}
		enemy = enemy->next;
	}
	update_foes(core);
}
