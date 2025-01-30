/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utlis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:29:36 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/01/30 21:00:04 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*current;
	
	current = stack->head;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1); 
}

int	get_distance(t_stack *stack, int index)
{
    t_node	*current;
    int		distance;

	distance = 0;
	current = stack->head;
    while (current)
    {
        if (current->index == index)
            return distance;
        distance++;
        current = current->next;
    }
    return -1;
}

void	print_stacks(t_data *data)
{
    t_node	*current_a; 
    t_node	*current_b;

	current_a = data->stack_a->head;
	current_b = data->stack_b->head;
    ft_printf("Pile A: ");
    while (current_a)
    {
        ft_printf("%d", current_a->value);
        current_a = current_a->next;
    }
    ft_printf("\n");
    ft_printf("Pile B: ");
    while (current_b)
    {
        ft_printf("%d", current_b->value);
        current_b = current_b->next;
    }
    ft_printf("\n");
}

int	get_min_index_position(t_stack *stack)
{
    t_node	*current;
    int		min_index;
    int		min_pos;
    int		pos;

	current = stack->head;
	min_index = current->index;
	min_pos = 0;
	pos = 0;
    while (current)
    {
        if (current->index < min_index)
        {
            min_index = current->index;
            min_pos = pos;
        }
        pos++;
        current = current->next;
    }
    return min_pos;
}

