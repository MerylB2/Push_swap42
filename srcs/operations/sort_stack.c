/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:15:22 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/02/11 17:41:05 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_b_to_a(t_data **a, t_data **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	push_a(a, b, false);
}

static void	min_value_on_top(t_data **a)
{
	while ((*a)->value != find_min_nb(*a)->value)
	{
		if (find_min_nb(*a)->median)
			rotate_a(a, false);
		else
			rotate_rev_a(a, false);
	}
}

void	sort_stacks(t_data **a, t_data **b)
{
	int	length_a;

	length_a = get_stack_len(*a);
	if (length_a-- > 3 && !is_sorted(*a))
		push_b(b, a, false);
	if (length_a-- > 3 && !is_sorted(*a))
		push_b(b, a, false);
	while (length_a-- > 3 && !is_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_value_on_top(a);
}
