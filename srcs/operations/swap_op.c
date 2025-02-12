/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:03:42 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/02/11 17:50:27 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_op(t_data **head)
{
	if (!(*head) || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	swap_a(t_data **a, bool print)
{
	swap_op(a);
	if (!print)
		ft_printf("sa\n");
}

void	swap_b(t_data **b, bool print)
{
	swap_op(b);
	if (!print)
		ft_printf("sb\n");
}

void	swap_s(t_data **a, t_data **b, bool print)
{
	swap_op(a);
	swap_op(b);
	if (!print)
		ft_printf("ss\n");
}
