/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rev_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:07:08 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/02/11 17:26:09 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_rev(t_data **stack)
{
	t_data	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last_node(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rotate_rev_b(t_data **a, bool print)
{
	rotate_rev(a);
	if (!print)
		ft_printf("rra\n");
}

void	rotate_rev_a(t_data **b, bool print)
{
	rotate_rev(b);
	if (!print)
		ft_printf("rrb\n");
}

void	rotate_rev_r(t_data **a, t_data **b, bool print)
{
	rotate_rev(a);
	rotate_rev(b);
	if (!print)
		ft_printf("rrr\n");
}
