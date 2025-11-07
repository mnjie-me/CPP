/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mari-cruz <mari-cruz@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:35:44 by mari-cruz         #+#    #+#             */
/*   Updated: 2025/11/07 12:58:54 by mari-cruz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void validateIndex(int &index)
{
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Invalid input. Insert contact index: ";
		std::cin >> index;
	}
}

std::string truncate10(std::string str)
{
	size_t visualLen = str.length();
	size_t i = 0;
	
	while (i < str.length())
	{
		if ((str[i] & 0xC0) == 0x80)
			visualLen--;
		i++;
	}
	if (visualLen > 10)
    {
        size_t bytesToCut = 9 + (str.length() - visualLen);
        return (str.substr(0, bytesToCut) + ".");
    }
    else
    {
        std::string padding(10 - visualLen, ' ');
        return (padding + str);
    }
}

void addHeader()
{
	std::cout << std::endl;
	std::cout << std::setw(10) << "INDEX";
	std::cout << "|" << std::setw(10) << "NAME";
	std::cout << "|" << std::setw(10) << "LAST NAME";
	std::cout << "|" << std::setw(10) << "NICKNAME";
	std::cout << "|";
	std::cout << std::endl;
}

void PhoneBook :: searchContact()
{
	int i = 0;
	int index;

	std::cout << std::right;
	addHeader();
	std::cout << std::string(50, '-') << std::endl;
	while (i < contactCount)
	{
		std::cout << std::setw(10) << i;
		std::cout << "|" << std::setw(10) << truncate10(contacts[i].firstName);
		std::cout << "|" << std::setw(10) << truncate10(contacts[i].lastName);
		std::cout << "|" << std::setw(10) << truncate10(contacts[i].nickname);
		std::cout << "|";
		std::cout << std::endl;
		i++;
	}
	std::cout << std::endl;
	std::cout << "Insert contact index: ";
	std::cin >> index;
	validateIndex(index);
	std::cin.ignore();
	if (index >= 0 && index < contactCount)
		contacts[index].contactInfo();
	else
		std::cout << "Index out of range" << std::endl;
}

void PhoneBook :: addContact()
{
	contacts[lastIndex].data();
	lastIndex = (lastIndex + 1) % 8;
	if (contactCount < 8)
		contactCount++;
}

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
