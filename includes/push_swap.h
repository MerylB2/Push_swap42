/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:54:34 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/02/11 18:04:45 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdbool.h>
# include "operations.h"

/*
** Gestion des erreurs
*/
int		error_syntax(char *s);
int		error_duplicate(t_data *a, int nb);
void	free_stack(t_data **stack);
void	free_errors(t_data **a);
/*
** Fonctions d'initialisation de la stack
*/
void	init_stack_a(t_data **data, char **av);
char	**ft_split_stack(char *s, char c);
long	ft_atol(const char *str);

/*
** Fonctions d'initialisation des noeuds
*/

void	init_nodes_a(t_data *a, t_data *b);
void	init_nodes_b(t_data *a, t_data *b);
void	current_index(t_data *stack);
void	set_cheapest(t_data *stack);
t_data	*get_cheapest(t_data *stack);
void	prep_for_push(t_data **s, t_data *nb, char c);

/*
** Fonctions pour l'algorithme de tri
*/
void	sort_stacks(t_data **a, t_data **b);
void	sort_three(t_data **a);

/*
** Fonctions de calcul des positions et coûts
*/
void	cost_analysis_a(t_data *a, t_data *b);
void	set_cheapest(t_data *stack);

/*
** Fonctions utilitaires
*/
bool	is_sorted(t_data *stack);
void	append_node(t_data **stack, int nb);
int		get_stack_len(t_data *stack);
t_data	*find_last_node(t_data *stack);
t_data	*find_min_nb(t_data *stack);
t_data	*find_max_nb(t_data *stack);
void	move_a_to_b(t_data **a, t_data **b);
void	rotate_both(t_data **a, t_data **b, t_data *cheapest_node);
void	rotate_rev_both(t_data **a, t_data **b, t_data *cheapest_node);

#endif
