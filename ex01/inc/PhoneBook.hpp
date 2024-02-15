/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvi <xvi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:07:58 by cedmulle          #+#    #+#             */
/*   Updated: 2024/02/13 09:31:42 by xvi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "tools.hpp"
# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void	createContact(int index, string firstName, string lastName,
							string nickName, string phoneNumber, string secret);
		void	copyContact(Contact *src, Contact *dst);
		Contact	getContact(int index);
		string	getValue(int index, int value);
	private:
		Contact	book[8];
};

#endif
