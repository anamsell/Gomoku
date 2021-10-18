/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <bpisano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:36:21 by bpisano           #+#    #+#             */
/*   Updated: 2021/09/21 17:40:31 by bpisano          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Exception.hpp"

Exception::UI::UI(std::string reason)
{
    this->reason = reason;
}

const char *Exception::UI::what() const throw()
{
    return reason.c_str();
}
