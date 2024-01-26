/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:29:41 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/27 00:00:09 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include "rt_parsing.h"
#include "objects.h"
#include "symbols.h"

void remove_comments(char **file);
t_scene	*parse_tokens(t_list *tokens);

/*
function was inlined in parse_rt()
static int	is_rt_file(char *filename)
{
	char	*find;

	find = ft_strrchr(filename, '.');
	return (find && !ft_strncmp(find, ".rt", 4));
} */

//A  ns nt
//C  nt nt ns
//L  nt ns nt
//pl nt nt nt
//sp nt ns nt
//cy nt nt ns ns nt

//matches token->str with the possible object type string
//initializes types_to_match accordingly

static int	get_types_to_match(enum e_token_type *ttm, t_token *token)
{
	if (!ft_strncmp(token->str, AMBIENT_LIGTHING, INT_MAX))
		ft_memcpy(ttm, (enum e_token_type[TTM_SIZE]) \
		{NumberSingleRatio, NumberTripletColor, eNull}, sizeof(*ttm) * 3);
	else if (!ft_strncmp(token->str, CAMERA, INT_MAX))
		ft_memcpy(ttm, (enum e_token_type[TTM_SIZE]){NumberTriplet, \
		NumberTripletNormal, NumberSingleFov, eNull}, sizeof(*ttm) * 4);
	else if (!ft_strncmp(token->str, LIGHT, INT_MAX))
		ft_memcpy(ttm, (enum e_token_type[TTM_SIZE]){NumberTriplet, \
		NumberSingleRatio, NumberTripletColor, eNull}, sizeof(*ttm) * 4);
	else if (!ft_strncmp(token->str, PLANE, INT_MAX))
		ft_memcpy(ttm, (enum e_token_type[TTM_SIZE]){NumberTriplet, \
		NumberTripletNormal, NumberTripletColor, eNull}, sizeof(*ttm) * 4);
	else if (!ft_strncmp(token->str, SPHERE, INT_MAX))
		ft_memcpy(ttm, (enum e_token_type[TTM_SIZE]){NumberTriplet, \
		NumberSingle, NumberTripletColor, eNull}, sizeof(*ttm) * 4);
	else if (!ft_strncmp(token->str, CYLINDER, INT_MAX))
		ft_memcpy(ttm, (enum e_token_type[TTM_SIZE]){NumberTriplet, \
		NumberTripletNormal, NumberSingle, NumberSingle, NumberTripletColor, \
		eNull}, sizeof(*ttm) * 6);
	else
		return (0);
	return (1);
}

//basically returns true if the type of the token is a subset of the type
//we're trying to match
bool	is_type_subset(t_token *tok, enum e_token_type type)
{
	if (type == NumberSingle && (tok->type == NumberSingleNormal \
	|| tok->type == NumberSingleFov || tok->type == NumberSingleRatio))
		return (true);
	else if ((type == NumberSingleNormal || type == NumberSingleFov) \
	&& tok->type == NumberSingleRatio)
		return (true);
	else if (type == NumberTriplet && (tok->type == NumberTripletRatio \
	|| tok->type == NumberTripletNormal || tok->type == NumberTripletColor))
		return (true);
	else if ((type == NumberTripletNormal || type == NumberTripletColor) \
	&& tok->type == NumberTripletRatio)
		return (true);
	return (false);
}

//checks if each object type token (A, C, L, pl, sp, cy..)
//are followed by the right tokens
static int	validate_object_tokens(t_list *tokens)
{
	enum e_token_type	types_to_match[TTM_SIZE];
	int					i;
	t_token				*current;

	if (!get_types_to_match(types_to_match, tokens->content))
		return (0);
	tokens = tokens->next;
	i = 0;
	while (tokens && types_to_match[i] != eNull)
	{
		current = tokens->content;
		if (current->type != types_to_match[i] \
		&& !is_type_subset(current, types_to_match[i]))
		{
			printf("error at token \'%s'\' of type %i\nexpected type:%i\n", \
			current->str, current->type, types_to_match[i]);
			return (0);
		}
		i++;
		tokens = tokens->next;
	}
	return (!tokens || ((t_token *)tokens->content)->type == ObjType);
}

static int	valid_file_content(t_list *tokens)
{
	int		ambient_lighting;
	int		cameras;
	t_token	*temp;

	if (((t_token *)tokens->content)->type != ObjType)
		return (0);
	ambient_lighting = 0;
	cameras = 0;
	while (tokens)
	{
		temp = tokens->content;
		if (!ft_strncmp(temp->str, AMBIENT_LIGTHING, INT_MAX))
			ambient_lighting++;
		else if (!ft_strncmp(temp->str, CAMERA, INT_MAX))
			cameras++;
		if (!validate_object_tokens(tokens))
			return (0);
		tokens = tokens->next;
		while (tokens && ((t_token *)tokens->content)->type != ObjType)
			tokens = tokens->next;
	}
	return (ambient_lighting == 1 && cameras == 1);
}

//checks if the name of the file ends in .rt
//reads the file, tokenizes it, checks if it's formatted correctly
//and uses its content to initialize a t_scene structure
t_scene	*parse_rt(char *filename)
{
	char	**file;
	t_list	*tokens;
	t_scene	*scene;

	if (!ft_strrchr(filename, '.') \
	|| ft_strncmp(ft_strrchr(filename, '.'), ".rt", 4))
	{
		write (2, "This isn't a .rt file!\n", 23);
		return (NULL);
	}
	file = ft_read_file(filename);
	if (!file)
		return (NULL);
	remove_comments(file);
	tokens = tokenize_file(file);
	ft_free_matrix((void ***)&file, INT_MAX);
	if (!tokens || !valid_file_content(tokens))
	{
		ft_lstclear(&tokens, free_token);
		return (NULL);
	}
	scene = parse_tokens(tokens);
	ft_lstclear(&tokens, free_token);
	return (scene);
}
