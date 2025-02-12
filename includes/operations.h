/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:42:35 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/02/11 17:55:34 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "push_swap.h"
# include "operations.h"

/*
** Structure de la pile et du nœud de la pile (data)
*/
typedef struct s_data
{
	int				value;
	int				index;
	int				push_cost;
	bool			median;
	bool			cheapest;
	struct s_data	*target_node;
	struct s_data	*next;
	struct s_data	*prev;
}				t_data;

/*
** --- SWAP OPERATIONS ---
** Échange les 2 premiers éléments au sommet de la pile
** Ne fait rien s'il n'y en *a qu'un ou aucun
*/
void	swap_a(t_data **a, bool print);
void	swap_b(t_data **b, bool print);
void	swap_s(t_data **a, t_data **b, bool print);

/*
** --- PUSH OPERATIONS ---
** Prend le premier élément au sommet d'une pile et le met sur l'autre pile
** Ne fait rien si la pile d'origine est vide
*/
void	push_a(t_data **a, t_data **b, bool print);
void	push_b(t_data **b, t_data **a, bool print);

/*
** --- ROTATE OPERATIONS ---
** Décale d'une position vers le haut tous les éléments de la pile
** Le premier élément devient le dernier
*/
void	rotate_a(t_data **a, bool print);
void	rotate_b(t_data **b, bool print);
void	rotate_r(t_data **a, t_data **b, bool print);

/*
** --- REVERSE ROTATE OPERATIONS ---
** Décale d'une position vers le bas tous les éléments de la pile
** Le dernier élément devient le premier
*/
void	rotate_rev_a(t_data **a, bool print);
void	rotate_rev_b(t_data **b, bool print);
void	rotate_rev_r(t_data **a, t_data **b, bool print);


/*
** --- BONUS OPERATIONS ---
** Versions silencieuses des opérations pour le checker
** Ces fonctions font la même chose mais n'affichent pas l'opération
*/

#endif