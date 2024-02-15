/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvi <xvi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:32:08 by cedmulle          #+#    #+#             */
/*   Updated: 2024/02/13 13:08:13 by xvi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/tools.hpp"

Contact::Contact(void)
{
	// std::cout << "Constructor: Contact" << std::endl;
}

Contact::~Contact(void)
{
	// std::cout << "Destructor: Contact" << std::endl;
}

void	Contact::setValue(int value, string content)
{
	if (value == FIRST_NAME)
		this->_firstName = content;
	else if (value == LAST_NAME)
		this->_lastName = content;
	else if (value == NICK_NAME)
		this->_nickName = content;
	else if (value == PHONE_NBR)
		this->_phoneNumber = content;
	else if (value == SECRET)
		this->_darkestSecret = content;
	else
		std::cout << YEL "Error: setValue (cpp)" RST << std::endl;
	return ;
}

string	Contact::getValue(int value)
{
	if (value == FIRST_NAME)
		return (this->_firstName);
	else if (value == LAST_NAME)
		return (this->_lastName);
	else if (value == NICK_NAME)
		return (this->_nickName);
	else if (value == PHONE_NBR)
		return (this->_phoneNumber);
	else if (value == SECRET)
		return (this->_darkestSecret);
	std::cout << YEL "Error: getValue (cpp)" RST << std::endl;
	return (NULL);
}
