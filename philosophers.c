/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:27:43 by rtavabil          #+#    #+#             */
/*   Updated: 2024/03/13 15:17:29 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	test_print(t_args args)
{
	printf("num_of_philosophers = %ld\n", args.number_of_philosophers);
	printf("time_to_die = %ld us\n", args.time_to_die);
	printf("time_to_eat = %ld us\n", args.time_to_eat);
	printf("time_to_sleep = %ld us\n", args.time_to_sleep);
	printf("must_eat = %ld\n",
		args.must_eat);
	for (int i = 0; i < args.number_of_philosophers; i++)
	{
		printf("philo=%d fork1=%ld fork2=%ld\n", args.philos[i].index, args.philos[i].first->fork_id, args.philos[i].second->fork_id);
	}
}

int	main(int argc, char **argv)
{
	t_args	args;

	if (argc == 5 || argc == 6)
	{
		set_args(argv, &args);
		printf("args are set\n");
		init(&args);
		printf("init\n");
		//test_print(args);
		algorithm(&args);
		printf("algorithm\n");
	}
	else
		write(2, "Invalid number of arguments\n", 29);
}
