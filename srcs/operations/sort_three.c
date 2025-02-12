/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:42:27 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/02/11 17:46:56 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_data **a)
{
	t_data	*biggest_node;

	biggest_node = find_max_nb(*a);
	if (biggest_node == *a)
		rotate_a(a, false);
	else if ((*a)->next == biggest_node)
		rotate_rev_a(a, false);
	if ((*a)->value > (*a)->next->value)
		swap_a(a, false);
}
