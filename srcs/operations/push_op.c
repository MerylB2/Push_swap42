/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:07:21 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/02/11 17:53:43 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_op(t_data **dst, t_data **src)
{
	t_data	*push;

	if (!src)
		return ;
	push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push->prev = NULL;
	if (!*dst)
	{
		*dst = push;
		push->next = NULL;
	}
	else
	{
		push->next = *dst;
		push->next->prev = push;
		*dst = push;
	}
}

void	push_a(t_data **a, t_data **b, bool print)
{
	push_op(a, b);
	if (!print)
		ft_printf("pa\n");
}

void	push_b(t_data **b, t_data **a, bool print)
{
	push_op(b, a);
	if (!print)
		ft_printf("pb\n");
}
