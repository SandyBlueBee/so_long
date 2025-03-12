/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:26:48 by syukna            #+#    #+#             */
/*   Updated: 2025/03/04 16:36:48 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../libft.h"

char	*ft_strnstr(const char *str, const char *str_tofind, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	tofilen;

	if (!str_tofind[0])
		return ((char *)str);
	tofilen = ft_strlen(str_tofind);
	if (tofilen > n)
		return (NULL);
	i = 0;
	while (i + tofilen <= n && str[i])
	{
		j = 0;
		while (str[i + j] == str_tofind[j] && str_tofind[j])
			j++;
		if (j == tofilen)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
