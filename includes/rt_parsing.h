/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:43:52 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/23 00:11:12 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PARSING_H
# define RT_PARSING_H

# include "libft.h"

enum	e_token_type
{
	NumberSingle,
	NumberTriplet,
	ObjType,
	Garbage,
	eNull
};

typedef struct s_token
{
	char 				*str;
	enum e_token_type	type;
}	t_token;

t_list	*tokenize_file(char **file);
t_token	*new_token(char **file, int *i, int *j);

#endif