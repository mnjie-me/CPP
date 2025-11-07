/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mari-cruz <mari-cruz@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:27:50 by mari-cruz         #+#    #+#             */
/*   Updated: 2025/11/07 12:36:52 by mari-cruz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void Contact::contactInfo()
{
	std::cout << "First name: " << firstName << std::endl;
	std::cout << "Last name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phoneNumber << std::endl;
	std::cout << "Darkest secret: " << darkestSecret << std::endl;
}

std::string fillField(const std::string &prompt)
{
	std::string input;
	
	while (input.empty())
	{
		std::cout << prompt;
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "Please fill in field!" << std::endl;
	}
	return (input);
}

void Contact :: data()
{
	firstName = fillField("First Name: ");
	lastName = fillField("Last Name: ");
	nickname = fillField("Nickname: ");
	phoneNumber = fillField("Phone Number: ");
	darkestSecret = fillField("Darkest Secret: ");
}

Contact :: Contact() : firstName(""), lastName(""), nickname(""),
	phoneNumber(""), darkestSecret(""){}
