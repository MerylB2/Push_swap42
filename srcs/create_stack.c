/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:48:35 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/02/03 18:08:21 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_a(t_data **a, char **av)
{
	long	n;
	int		i;

	while (av[i])
	{
		if (error_syntax(av[i]))
			free_errors(a);
		n = ft_atoll(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_erros(a);
		if (error_duplicate(*a, (int)n))
			free_errors(a);
		append_node(a, (int)n);
		i++;
	}
}

t_data	*get_cheapest(t_data *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_data **stack,
						t_data *top_node,
						char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->median)
				rotate_a(stack, false);
			else
				rotate_rev_a(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->median)
				rotate_b(stack, false);
			else
				rotate_rev_b(stack, false);
		}	
	}
}
