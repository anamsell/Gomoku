/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <bpisano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:30:23 by bpisano           #+#    #+#             */
/*   Updated: 2021/09/21 17:37:09 by bpisano          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>
#include <string>

class Exception
{
public:
    class UI : public std::exception
    {
    private:
        std::string reason;

    public:
        UI(std::string reason);
        virtual const char *what() const throw();
    };
};

#endif
