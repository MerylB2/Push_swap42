/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:29:53 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/02/11 17:30:46 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_data **a, t_data **b, t_data *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rotate_r(a, b, false);
	current_index(*a);
	current_index(*b);
}

void	rotate_rev_both(t_data **a, t_data **b, t_data *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rotate_rev_r(a, b, false);
	current_index(*a);
	current_index(*b);
}

void	move_a_to_b(t_data **a, t_data **b)
{
	t_data	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->median && cheapest_node->target_node->median)
		rotate_both(a, b, cheapest_node);
	else if ((!cheapest_node->median) && !(cheapest_node->target_node->median))
		rotate_rev_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	push_b(b, a, false);
}
