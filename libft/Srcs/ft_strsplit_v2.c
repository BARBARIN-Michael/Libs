/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_v2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 11:26:49 by mbarbari          #+#    #+#             */
/*   Updated: 2016/01/08 11:59:01 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static unsigned int	count_car(char const *str, char c)
{
	unsigned int i;
	char const	*s;

	i = 0;
	s = str;
	while (dprintf(2, "count_car\n"), ++s)
		if (*s == c)
			++i;
	return (++i);
}
char	**ft_strsplit_v2(char const *str, char c)
{
	char			*save;
	char			**ptr;
	unsigned int	cmp;

	dprintf(2, "debut de fonction\n");
	cmp = -1;
	if (!str)
		return (NULL);
	save = ft_strdup(str);
	ptr = malloc(sizeof(char *) * (count_car(str, c) + 1));
	ptr[(++cmp)] = &save[0];
	while (dprintf(2, "split\n"), ++save)
		if (*save == c && save[1] != '\0' && (*save = '\0'))
			ptr[(++cmp)] = &save[1];
	ptr[(++cmp)] = NULL;
	return (ptr);
}
