/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:15:03 by kpucylo           #+#    #+#             */
/*   Updated: 2022/01/19 01:21:00 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*dest;
	size_t	len;
	size_t	i;
	size_t	j;

	j = 0;
	i = -1;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	while (s1[++i] != 0)
		dest[i] = s1[i];
	while (s2[j] != 0)
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = 0;
	return (dest);
}
