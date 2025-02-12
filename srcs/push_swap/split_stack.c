/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:21:50 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/02/11 16:35:55 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *s, char c)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*s)
	{
		inside_word = false;
		while (*s == c)
			++s;
		while (*s != c && *s)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++s;
		}
	}
	return (count);
}

static char	*find_next_word(char *s, char c)
{
	static int	search;
	char		*n_word;
	int			len;
	int			i;

	search = 0;
	len = 0;
	i = 0;
	while (s[search] == c)
		++search;
	while ((s[search + len] != c) && s[search + len])
		++len;
	n_word = malloc((size_t)len * sizeof(char) + 1);
	if (!n_word)
		return (NULL);
	while ((s[search] != c) && s[search])
		n_word[i++] = s[search++];
	n_word[i] = '\0';
	return (n_word);
}

char	**ft_split_stack(char *s, char c)
{
	int		i;
	int		words_cnt;
	char	**res_array;

	i = 0;
	words_cnt = count_words(s, c);
	if (!words_cnt)
		exit(1);
	res_array = malloc(sizeof(char *) * (size_t)(words_cnt + 2));
	if (!res_array)
		return (NULL);
	while (words_cnt-- >= 0)
	{
		if (i == 0)
		{
			res_array[i] = malloc(sizeof(char));
			if (!res_array[i])
				return (NULL);
			res_array[i++][0] = '\0';
			continue ;
		}
		res_array[i++] = find_next_word(s, c);
	}
	res_array[i] = NULL;
	return (res_array);
}
