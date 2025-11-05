/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mari-cruz <mari-cruz@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:35:44 by mari-cruz         #+#    #+#             */
/*   Updated: 2025/11/05 12:57:15 by mari-cruz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

std::string truncate10(std::string str)
{

	if (str.length() > 10)
	{
		return (str.substr(0, 9 ) + ".");
	}
	else
		return (str);
}

void addHeader()
{
	std::cout << std::setw(10) << "INDEX";
	std::cout << "|" << std::setw(10) << "NAME";
	std::cout << "|" << std::setw(10) << "LAST";
	std::cout << "|" << std::setw(10) << "NICK";
	std::cout << "|" << std::setw(10) << "PHONE";
	std::cout << "|" << std::setw(10) << "EMAIL";
	std::cout << "|";
	std::cout << std::endl;
}

void PhoneBook :: searchContact()
{
	int i = 0;

	std::cout << std::right;
	addHeader();
	std::cout << std::string(67, '-') << std::endl;
	while (i < contactCount)
	{
		std::cout << std::setw(10) << i;
		std::cout << "|" << std::setw(10) << truncate10(contacts[i].firstName);
		std::cout << "|" << std::setw(10) << truncate10(contacts[i].lastName);
		std::cout << "|" << std::setw(10) << truncate10(contacts[i].nickname);
		std::cout << "|" << std::setw(10) << truncate10(contacts[i].phoneNumber);
		std::cout << "|" << std::setw(10) << truncate10(contacts[i].email);
		std::cout << "|";
		std::cout << std::endl;
		i++;
	}
}

void Contact :: data()
{
	std::cout << "First Name: ";
	std::getline(std::cin, firstName);
	std::cout << "Last Name: ";
	std::getline(std::cin, lastName);
	std::cout << "Nickname: ";
	std::getline(std::cin, nickname);
	std::cout << "Phone Number: ";
	std::getline(std::cin, phoneNumber);
	std::cout << "Email: ";
	std::getline(std::cin, email);
}

void PhoneBook :: addContact()
{
	contacts[lastIndex].data();
	lastIndex = (lastIndex + 1) % 8;
	if (contactCount < 8)
		contactCount++;
}

Contact :: Contact() : firstName(""), lastName(""), nickname(""),
	phoneNumber(""), email(""){}

PhoneBook :: PhoneBook() : contactCount(0), lastIndex(0){}

int	main()
{
	PhoneBook	phonebook;
	Contact		contact;
	std::string command;
	
	while (1)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.searchContact();
		else if (command == "EXIT")
			break ;
	}
}
