/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:25:27 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/01/30 21:29:47 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int value)
{
	t_node *new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return NULL;
	new_node->value = value;
	new_node->index = -1;
	new_node->pos = -1;
	new_node->target_pos = -1;
	new_node->cost_a = 0;
	new_node->cost_b = 0;
	new_node->next = NULL;
	return new_node;
}

void	add_node_back(t_stack *stack, t_node *new_node)
{
	if (!stack || !new_node)
		return ;
	if (stack->head == NULL)
	{
		stack->head = new_node;
	}
	else
	{
		t_node *current = stack->head;
		while (current->next)
		{
			current = current->next;
		}
		current->next = new_node;
	}
	stack->size++;
}
