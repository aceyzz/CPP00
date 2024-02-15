/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvi <xvi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:47:52 by cedmulle          #+#    #+#             */
/*   Updated: 2024/02/13 13:33:02 by xvi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_HPP
# define TOOLS_HPP

# include <iostream>
# include <string>
# include <cctype>
# include <iomanip>

# define string std::string
# define FIRST_NAME 1
# define LAST_NAME 2
# define NICK_NAME 3
# define PHONE_NBR 4
# define SECRET 5

# define RST "\033[0m"
# define GRY "\033[1;30m"
# define RED "\033[1;31m"
# define GRE "\033[1;32m"
# define YEL "\033[1;33m"
# define BLU "\033[1;34m"
# define MAG "\033[1;35m"
# define CYA "\033[1;36m"
# define WHI "\033[1;37m"
# define D_GRY "\033[0;30m"
# define D_RED "\033[0;31m"
# define D_GRE "\033[0;32m"
# define D_YEL "\033[0;33m"
# define D_BLU "\033[0;34m"
# define D_MAG "\033[0;35m"
# define D_CYA "\033[0;36m"
# define D_WHI "\033[0;37m"

# include "PhoneBook.hpp"
# include "Contact.hpp"

#endif
