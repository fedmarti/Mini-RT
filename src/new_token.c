/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 22:12:52 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/25 21:54:09 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parsing.h"

void	next_char(char **file, int *i, int *j);
void	token_char_check(enum e_token_type *possible_types, t_pdata *data);

static int	tok_len(char **file, int i, int j)
{
	int	len;

	len = 0;
	while (file[i] && !ft_isspace(file[i][j]))
	{
		len++;
		next_char(file, &i, &j);
	}
	return (len);
}

enum e_token_type	parse_type(t_token *new)
{
	enum e_token_type	possible_types[E_NULL + 1];
	int					i;
	t_pdata				data;

	i = 0;
	ft_bzero(&data, sizeof(data));
	possible_types[0] = NumberSingle;
	possible_types[1] = NumberTriplet;
	possible_types[2] = ObjType;
	possible_types[3] = Garbage;
	possible_types[E_NULL] = E_NULL;
	while (new->str[i] && possible_types[0] != Garbage)
	{
		data.c = new->str[i];
		token_char_check(possible_types, &data);
		i++;
	}
	return (possible_types[0]);
}

	//if all numeric NumberSingle
	//if three numbers NumberTriplet
	//if only characters type
	//else garbage

t_token	*new_token(char **file, int *i, int *j)
{
	int		len;
	t_token	*new;
	int		pos;

	len = tok_len(file, *i, *j);
	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->str = malloc(len + 1);
	if (!new->str)
	{
		free(new);
		return (NULL);
	}
	pos = 0;
	while (pos < len)
	{
		new->str[pos] = file[*i][*j];
		next_char(file, i, j);
		pos++;
	}
	new->str[pos] = '\0';
	new->type = parse_type(new);
	return (new);
}
