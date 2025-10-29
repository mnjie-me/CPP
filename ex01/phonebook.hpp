/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mari-cruz <mari-cruz@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:23:36 by mari-cruz         #+#    #+#             */
/*   Updated: 2025/10/29 21:09:34 by mari-cruz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK
# define PHONEBOOK

# include <iostream>
# include <string>
#include <iomanip>
#include <string>
# include "contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int		contactCount;
		int		lastIndex;
	public:
		PhoneBook();
		void addContact();
		void searchContact();
};

#endif