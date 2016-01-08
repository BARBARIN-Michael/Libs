/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_v2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 11:26:49 by mbarbari          #+#    #+#             */
/*   Updated: 2016/01/08 13:11:30 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static unsigned int	count_car(char *s, char c)
{
	unsigned int i;

	i = 0;
	while (*(++s))
		if (*s == c && (s[-1] != c && s[1] != '\0'))
			++i;
	return (++i);
}
char	**ft_strsplit(char const *str, char c)
{
	char			*save;
	char			**ptr;
	unsigned int	cmp;

	cmp = -1;
	if (!str)
		return (NULL);
	save = ft_strdup(str);
	ptr = malloc(sizeof(char *) * (count_car((char *)str, c) + 1));
	ptr[(++cmp)] = &save[0];
	while (*(++save))
		if (*save == c)
		{
			*save = 0;
			if (save[1] == '\0' || save[1] == c)
				continue ;
			ptr[(++cmp)] = &save[1];
		}
	ptr[(++cmp)] = NULL;
	return (ptr);
}
