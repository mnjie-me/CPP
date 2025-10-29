/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mari-cruz <mari-cruz@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:35:44 by mari-cruz         #+#    #+#             */
/*   Updated: 2025/10/29 21:12:02 by mari-cruz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void 

void PhoneBook :: searchContact()
{
	while (contacts)
	{
		std::cout << std::setw(10) << std::truncate10(firstName)
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
	std::cout << "email: ";
	std::getline(std::cin, email);
}

void PhoneBook :: addContact()
{
	contacts[lastIndex].data();
	lastIndex = (contactCount + 1) % 8;
	if (contactCount < 8)
		contactCount++;
}

Contact :: Contact() : firstName(""), lastName(""), nickname(""),
	phoneNumber(""), email(""){}

PhoneBook :: PhoneBook() : contactCount(0){}

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
