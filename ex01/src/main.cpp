/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvi <xvi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:45:51 by cedmulle          #+#    #+#             */
/*   Updated: 2024/02/13 14:03:33 by xvi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/tools.hpp"

void	cleanInput(string& input)
{
	size_t start = input.find_first_not_of(" \t");
	if (start != string::npos)
		input.erase(0, start);
	
	size_t end = input.find_last_not_of(" \t");
	if (end != string::npos && end < input.length())
		input.erase(end + 1);
}

bool	is_digit(string input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]) && input[i] != '0')
			return (false);
	}
	return (true);
}

bool	isEmptyLine(string input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (input[i] != ' ' && input[i] != '\t' && input[i] != '\n' && input[i] != '\r' && input[i] != '\v' && input[i] != '\f')
			return (false);
	}
	return (true);
}

void	validateInput(const string& prompt, string& input, const string& errMsg)
{
	while (1 && !std::cin.eof())
	{
		std::cout << GRY << prompt << RST;
		std::getline(std::cin, input);
		cleanInput(input);
		if (input.length() > 0 && !isEmptyLine(input))
				break;
		else
			std::cout << D_YEL << errMsg << RST << std::endl;
	}
}

void	validateInputNbr(const string& prompt, string& input, const string& errMsg)
{
	while (1 && !std::cin.eof())
	{
		std::cout << GRY << prompt << RST;
		std::getline(std::cin, input);
		cleanInput(input);
		if (input.length() > 0 && is_digit(input))
			break;
		else
			std::cout << D_YEL << errMsg << RST << std::endl;
	}
}

void	shiftContact(PhoneBook *phonebook, int index)
{
	if (index > 7)
		index = 7;
	for (int i = index; i > 0; i--)
	{
		string	first = phonebook->getValue(i - 1, FIRST_NAME);
		string	last = phonebook->getValue(i - 1, LAST_NAME);
		string	nick = phonebook->getValue(i - 1, NICK_NAME);
		string	phone = phonebook->getValue(i - 1, PHONE_NBR);
		string	secret = phonebook->getValue(i - 1, SECRET);
		phonebook->createContact(i, first, last, nick, phone, secret);
	}
}

void	addContact(PhoneBook* phonebook, int index)
{
	string	first;
	string	last;
	string	nick;
	string	phone;
	string	secret;

	validateInput("First Name: ", first, "Invalid First Name");
	validateInput("Last Name: ", last, "Invalid Last Name");
	validateInput("Nick Name: ", nick, "Invalid Nick Name");
	validateInputNbr("Phone Number: ", phone, "Invalid Phone Number");
	validateInput("Darkest Secret: ", secret, "Invalid Darkest Secret");
	if (index > 0)
		shiftContact(phonebook, index);
	phonebook->createContact(0, first, last, nick, phone, secret);
}

void	drawHeader()
{
	std::cout << GRY " ";
	for (int i = 0; i < 58; i++)
		std::cout << "-";
	std::cout << " " << std::endl;
	std::cout << "|" << std::left << std::setw(11) << " Index n°" << "|";
	std::cout << std::setw(11) << " 1st Name" << "|";
	std::cout << std::setw(11) << " Last Name" << "|";
	std::cout << std::setw(11) << " Nick Name" << "|";
	std::cout << std::setw(11) << " Phone n°" << "|" << std::endl;
	std::cout << " ";
	for (int i = 0; i < 58; i++)
		std::cout << "-";
	std::cout << " " << std::endl;
}

void	printContacts(PhoneBook* phonebook)
{
	Contact contact;
	string value;

	drawHeader();
	for (int i = 0; i < 8; i++)
	{
		contact = phonebook->getContact(i);
		std::cout << "|" RST << std::right << std::setw(10) << i + 1 << GRY "|";
		for (int j = 1; j < 5; j++)
		{
			value = phonebook->getValue(i, j);
			if (value.length() > 10)
			{
				value.resize(9);
				value += ".";
			}
			std::cout << " " RST;
			std::cout << std::setw(10) << value << GRY "|";
		}
		std::cout << std::endl;
	}
	std::cout << " ";
	for (int i = 0; i < 58; i++)
		std::cout << "-";
	std::cout << RST " " << std::endl;
}

void	searchContact(PhoneBook *phonebook);

void	askIndex(PhoneBook *phonebook, string input)
{
	int index = std::stoi(input);
	if (index > 0 && index < 9)
	{
		Contact contact = phonebook->getContact(index - 1);
		if (contact.getValue(FIRST_NAME).empty() || contact.getValue(LAST_NAME).empty()
			|| contact.getValue(NICK_NAME).empty() || contact.getValue(PHONE_NBR).empty()
			|| contact.getValue(SECRET).empty())
			std::cout << D_YEL "No contact at this index" RST << std::endl;
		else
		{
			std::cout << std::endl << GRY "First Name:\t" RST << contact.getValue(FIRST_NAME) << std::endl;
			std::cout << GRY "Last Name:\t" RST << contact.getValue(LAST_NAME) << std::endl;
			std::cout << GRY "Nick Name:\t" RST << contact.getValue(NICK_NAME) << std::endl;
			std::cout << GRY "Phone Number:\t" RST << contact.getValue(PHONE_NBR) << std::endl;
			std::cout << GRY "Dark Secret:\t" RST << contact.getValue(SECRET) << std::endl << std::endl;
		}
	}
	else
		std::cout << D_YEL "Invalid index" RST << std::endl;
}

void	searchContact(PhoneBook *phonebook)
{
	string input;

	printContacts(phonebook);
	while (!std::cin.eof())
	{
		std::cout << GRY "Enter the contact's index to search: " RST;
		std::getline(std::cin, input);
		cleanInput(input);
		if (isEmptyLine(input) || !is_digit(input))
		{
			std::cout << D_YEL "Enter a valid index to search" RST << std::endl;
			continue ;
		}
		else
			break ;
	}
	try {
		askIndex(phonebook, input);
	}
	catch (std::exception &e) {
		;
	}
}

int	main(void)
{
	PhoneBook	phonebook;
	string		input;
	int			index = 0;

	std::cout << "\033[2J\033[3J\033[H";
	while (!std::cin.eof())
	{
		std::cout << GRY "Type you command (ADD/SEARCH/EXIT)..." RST << std::endl;
		std::getline(std::cin, input);
		cleanInput(input);
		if (input == "EXIT")
			break ;
		else if (input == "ADD")
			addContact(&phonebook, index++);
		else if (input == "SEARCH")
		{
			std::cout << "\033[2J\033[3J\033[H";
			searchContact(&phonebook);
		}
		else if (!std::cin.eof())
			std::cout << D_YEL "Invalid Command (waring: case sensitive)" RST << std::endl;
	}
	std::cout << MAG "Bye bye ♥" RST << std::endl;
	return (0);
}
