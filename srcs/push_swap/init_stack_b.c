/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:05:15 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/02/11 18:37:09 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_b(t_data *a, t_data *b)
{
	t_data	*current_a;
	t_data	*target_node;
	long	best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target_node = find_max_nb(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	init_nodes_b(t_data *a, t_data *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}
