/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mari-cruz <mari-cruz@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:32:03 by mari-cruz         #+#    #+#             */
/*   Updated: 2025/11/18 12:46:30 by mari-cruz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT
# define CONTACT

# include <iostream>
# include <string>

class Contact
{
	public:
		std::string getFirstName();
		std::string getLastName();
		std::string getNickname();
		
		Contact();
		void getData();
		void getContactInfo();
		
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
	

		void data();
		void contactInfo();
};

#endif