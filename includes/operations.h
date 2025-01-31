/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:42:35 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/01/31 15:50:16 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "push_swap.h"
# include "operations.h"

/*
** Structure du nœud de la pile
*/
typedef struct s_node
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct  s_node 	*next;
}	t_node;

/*
** Structure de la pile
*/
typedef struct s_stack
{
	t_node	*head;
	char	name;
	int		size;
}	t_stack;

/*
** Structure principale
*/
typedef struct s_data
{
	t_stack *stack_a;
	t_stack	*stack_b;
	int		total_size;
	int		min_value;
	int		max_value;
}	t_data;

/*
** --- SWAP OPERATIONS ---
** Échange les 2 premiers éléments au sommet de la pile
** Ne fait rien s'il n'y en a qu'un ou aucun
*/
void	swap_a(t_stack *a);
void	swap_b(t_stack *b);
void	swap_s(t_stack *a, t_stack *b);

/*
** --- PUSH OPERATIONS ---
** Prend le premier élément au sommet d'une pile et le met sur l'autre pile
** Ne fait rien si la pile d'origine est vide
*/
void	push_a(t_stack *a, t_stack *b);
void	push_b(t_stack *a, t_stack *b);

/*
** --- ROTATE OPERATIONS ---
** Décale d'une position vers le haut tous les éléments de la pile
** Le premier élément devient le dernier
*/
void	rotate_a(t_stack *a);
void	rotate_b(t_stack *b);
void	rotate_r(t_stack *a, t_stack *b);

/*
** --- REVERSE ROTATE OPERATIONS ---
** Décale d'une position vers le bas tous les éléments de la pile
** Le dernier élément devient le premier
*/
void	rotate_rev_a(t_stack *a);
void	rotate_rev_b(t_stack *b);
void	rotate_rev_r(t_stack *a, t_stack *b);

/*
** --- UTILS ---
** Fonctions utilitaires pour les opérations
*/
void	print_operation(char *op);
int		is_valid_operation(char *op);
void	execute_op(t_stack *a, t_stack *b, char *op);

/*
** --- BONUS OPERATIONS ---
** Versions silencieuses des opérations pour le checker
** Ces fonctions font la même chose mais n'affichent pas l'opération
*/

#endif