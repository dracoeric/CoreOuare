/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:53:43 by dfinnis           #+#    #+#             */
/*   Updated: 2019/02/13 11:53:44 by dfinnis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	find_args(unsigned char *ptr, t_arg_type arg[])
{
	unsigned char	mask;

	mask = 192;
	arg[0] = (mask & *ptr) >> 6;
	// ft_printf("arg1 - %i\n", arg[0]);
	arg[1] = ((mask >> 2) & *ptr) >> 4;
	// ft_printf("arg2 - %i\n", arg[1]);
	arg[2] = ((mask >> 4) & *ptr) >> 2;
	// ft_printf("arg3 - %i\n", arg[2]);
	arg[3] = (mask >> 6) & *ptr;
	// ft_printf("arg4 - %i\n", arg[3]);
}

void	ft_get_size(unsigned int *size, t_arg_type args, int i)
{
	if (args == REG_CODE)
		*size = 1;
	else if (args == IND_CODE)
		*size = IND_SIZE;
	else if (args == DIR_CODE)
		*size = DIR_SIZE / i;
	else
		*size = 0;
}