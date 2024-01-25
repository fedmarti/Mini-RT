/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:41:40 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/24 22:03:32 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "rt_parsing.h"

void	free_token(void *tok)
{
	if (((t_token *)tok)->str)
		free(((t_token *)tok)->str);
	free(tok);
}

void	next_char(char **file, int *i, int *j)
{
	if (file[*i][*j + 1])
		(*j)++;
	else
	{
		*j = 0;
		(*i)++;
	}
}

t_list	*tokenize_file(char **file)
{
	t_list	*tokens;
	int		i;
	int		j;
	t_token	*newtok;

	tokens = NULL;
	i = 0;
	j = 0;
	while (file[i])
	{
		if (ft_isspace(file[i][j]))
			next_char(file, &i, &j);
		else
		{
			newtok = new_token(file, &i, &j);
			if (!newtok)
			{
				ft_lstclear(&tokens, free_token);
				return (NULL);
			}
			ft_lstadd_back(&tokens, ft_lstnew(newtok));
		}
	}
	return (tokens);
}
