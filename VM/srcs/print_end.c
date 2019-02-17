/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 18:22:50 by dfinnis           #+#    #+#             */
/*   Updated: 2019/02/17 18:22:51 by dfinnis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	who_won(t_game *game)
{
	int	champ;
	int	i;

	i = game->champ_total;
	champ = game->champ_total;
	while (i > 0)
	{
		if (game->champ[i].last_alive >= game->champ[champ].last_alive)
			champ = i;
		i--;
	}
	return (champ);
}

static void	print_winner_color(t_game *game, short winner)
{
	if (winner == 1)
		ft_printf("\t%sPlayer %d (%s) won%s\n", RED, game->champ[winner].nbr,
		game->champ[winner].header.prog_name, RESET);
	else if (winner == 2)
		ft_printf("\t%sPlayer %d (%s) won%s\n", GREEN, game->champ[winner].nbr,
		game->champ[winner].header.prog_name, RESET);
	else if (winner == 3)
		ft_printf("\t%sPlayer %d (%s) won%s\n", BLUE, game->champ[winner].nbr,
		game->champ[winner].header.prog_name, RESET);
	else if (winner == 4)
		ft_printf("\t%sPlayer %d (%s) won%s\n", YELLOW, game->champ[winner].nbr,
		game->champ[winner].header.prog_name, RESET);
}

void		print_winner(t_game *game)
{
	short	winner;

	winner = who_won(game);
	if (!game->dump_set)
	{
		if (!game->champ[winner].last_alive)
			ft_printf("No player won, no player lived\n");
		else
		{
			if (game->flag_v)
				print_winner_color(game, winner);
			else
				ft_printf("%sPlayer %d (%s) won%s\n", BRIGHT,
				game->champ[winner].nbr, game->champ[winner].header.prog_name,
				RESET);
		}
	}
	if (game->flag_e)
		ft_printf("\tGame ended at cycle count: %d\n", game->cycle_count);
}