/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:27:23 by cedmulle          #+#    #+#             */
/*   Updated: 2024/02/11 10:53:23 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	print_upper_str(char *str)
{
	int	i = -1;

	if (str)
		while (str[++i])
			std::cout << (char)toupper(str[i]);
	return ;
}

int	main(int argc, char **argv)
{
	int	i = 0;

	if (argc >= 2)
		while (argv[++i])
			print_upper_str(argv[i]);
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (0);
}
