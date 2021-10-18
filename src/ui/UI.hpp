/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UI.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <bpisano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:49:22 by bpisano           #+#    #+#             */
/*   Updated: 2021/09/22 12:35:31 by bpisano          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_HPP
#define UI_HPP

class UI
{
private:
    static UI *_shared;
    UI();

public:
    UI(UI &other) = delete;
    void operator=(const UI &) = delete;

    static UI *shared();

    void showWindow();
};

#endif
