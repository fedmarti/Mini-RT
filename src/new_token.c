/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 22:12:52 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/23 00:16:53 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parsing.h"

void	next_char(char **file, int *i, int *j);

static int	tok_len(char **file, int i, int j)
{
	int len;

	len = 0;
	while (file && !ft_isspace(file[i][j]))
	{
		len++;
		next_char(file, &i, &j);
	}
	return (len);
}

static inline void remove_type(enum e_token_type *arr, enum e_token_type type)
{
	int	i;
	int j;

	if (type == eNull)
		return ;
	i = 0;
	while (arr[i] != eNull)
	{
		if (type == type)
		{
			j = i + 1;
			arr[i] = arr[j];
			while (arr[j] != eNull)
			{
				j = i + 1;
				arr[i] = arr[j];
			}
		}
		i++;
	}
}

enum e_token_type	parse_type(t_token *new)
{
	enum e_token_type	possible_types[eNull];
	int					i;
	int					comma_count;

	i = 0;
	comma_count = 0;
	ft_memcpy(possible_types, (enum e_token_type[eNull]){NumberSingle, \
	NumberTriplet, ObjType, Garbage, eNull}, sizeof(possible_types));
	while (new->str[i] && possible_types[0] != Garbage)
	{
		if (ft_isalpha(new->str[i]))
		{
			remove_type(possible_types, NumberSingle);
			remove_type(possible_types, NumberTriplet);
		}
		if (ft_isdigit(new->str[i]))
			remove_type(possible_types, ObjType);
		if (new->str[i] == ',')
		{
			if (i == 0 || comma_count > 3)
				return (Garbage);
			if (possible_types[0] == NumberSingle)
				remove_type(possible_types, NumberSingle);
			comma_count++;
		}
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
