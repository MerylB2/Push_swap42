/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:36:47 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/01/31 12:45:03 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 2)
		return (0);
	init_program(&data);
	parse_args(ac, av, &data);
	if (is_sorted(data.stack_a))
	{
		free_program(&data);
		return (0);
	}
	sort_stack(&data);
	// execute_cheapest_move(&data);
	free_program(&data);
	return (0);
}