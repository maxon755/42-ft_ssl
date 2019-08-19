/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:43:54 by maks              #+#    #+#             */
/*   Updated: 2019/08/17 15:09:16 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"

void	process_missed_arg(t_flag *flag, const char *opstr, const char *pname)
{
	flag->symbol = opstr[0] == ':' ? ':' : '?';
	if (opterr != 0 && opstr[0] != ':')
	{
		ft_printf("%&%s: option requires an argument -- %c\n",
			2, pname, optopt);
	}
}

void	process_multi_flag(t_flag *flag, char *const *argv, const char *opstr)
{
	optopt = flag->symbol;
	if (flag->has_arg)
	{
		optarg = flag->is_last_symbol ?
			argv[++optind] :
			ft_strchr(argv[optind], flag->symbol) + 1;
		if (optarg == NULL)
			process_missed_arg(flag, opstr, argv[0]);
		set_global_vars(1, 0);
	}
	else if (flag->is_last_symbol)
	{
		set_global_vars(1, 0);
	}
}

void	process_single_flag(t_flag *flag, char *const *argv, const char *opstr)
{
	optopt = flag->symbol;
	if (flag->has_arg)
	{
		optarg = argv[++optind];
		if (optarg == NULL)
			process_missed_arg(flag, opstr, argv[0]);
	}
	set_global_vars(1, 0);
}

void	process_invalid_flag(t_flag *flag, const char *opstr, const char *pname)
{
	optopt = flag->symbol;
	optind++;
	if (opterr != 0 && opstr[0] != ':')
	{
		ft_printf("%&%s: illegal option -- %c\n", 2, pname, optopt);
	}
	flag->symbol = ('?');
}

int		ft_getopt(
	int __attribute__((unused)) argc,
	char *const *argv,
	const char *opstr)
{
	int		flag_symbol;
	t_flag	*flag;

	if (!is_flag(argv[optind]))
		return (-1);
	flag = parse_flag(argv[optind], opstr);
	if (!flag->valid)
	{
		process_invalid_flag(flag, opstr, argv[0]);
	}
	else
	{
		flag->is_multi_symbol
			? process_multi_flag(flag, argv, opstr)
			: process_single_flag(flag, argv, opstr);
	}
	flag_symbol = flag->symbol;
	free(flag);
	return (flag_symbol);
}
