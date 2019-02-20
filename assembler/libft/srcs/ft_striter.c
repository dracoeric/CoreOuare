/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 09:51:28 by erli              #+#    #+#             */
/*   Updated: 2018/11/09 13:31:58 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_striter(char *str, void (*f)(char *))
{
	if (str != NULL && f != NULL)
	{
		while (*str != '\0')
		{
			f(str);
			str++;
		}
	}
}