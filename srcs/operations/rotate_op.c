/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:07:13 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/02/12 14:28:30 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_op(t_data **stack)
{
	t_data	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	rotate_a(t_data **a, bool print)
{
	rotate_op(a);
	if (!print)
		ft_printf("ra\n");
}

void	rotate_b(t_data **b, bool print)
{
	rotate_op(b);
	if (!print)
		ft_printf("rb\n");
}

void	rotate_r(t_data **a, t_data **b, bool print)
{
	rotate_op(a);
	rotate_op(b);
	if (!print)
		ft_printf("rr\n");
}
