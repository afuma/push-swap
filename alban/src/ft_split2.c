/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:56:30 by edesaint          #+#    #+#             */
/*   Updated: 2023/05/08 18:42:11 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;
	size_t				i;

	s = src;
	d = dest;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len_src;

	len_src = ft_strlen(src);
	if (!src)
		return (0);
	if (size == 0)
		return (len_src);
	if (size <= len_src)
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	else
	{
		ft_memcpy(dst, src, len_src);
		dst[len_src] = '\0';
	}
	return (len_src);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*nstr;
	int				size_nstr;
	unsigned int	len_s;

	len_s = ft_strlen(s);
	if (start > len_s + 1)
	{
		size_nstr = 0;
		start = 0;
	}
	else
		size_nstr = len_s - start;
	if (size_nstr > (int) len)
		size_nstr = len;
	nstr = malloc(sizeof(char) * (size_nstr + 1));
	if (!nstr)
		return (NULL);
	ft_strlcpy(nstr, s + start, size_nstr + 1);
	return (nstr);
}
