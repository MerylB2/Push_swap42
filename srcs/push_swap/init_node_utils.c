/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:23:11 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/02/11 18:10:42 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost_analysis_a(t_data *a, t_data *b)
{
	int	len_a;
	int	len_b;

	len_a = get_stack_len(a);
	len_b = get_stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->median))
			a->push_cost = len_a - (a->index);
		if (a->target_node->median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

void	set_cheapest(t_data *stack)
{
	long	cheapest_value;
	t_data	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	current_index(t_data *stack)
{
	int	i;
	int	l_median;

	i = 0;
	if (!stack)
		return ;
	l_median = get_stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= l_median)
			stack->median = true;
		else
			stack->median = false;
		stack = stack->next;
		++i;
	}
}
