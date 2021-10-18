/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Size.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <bpisano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:23:33 by bpisano           #+#    #+#             */
/*   Updated: 2021/09/22 14:21:30 by bpisano          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIZE_HPP
#define SIZE_HPP

struct Size
{
    int width;
    int height;

    Size(int width, int height);

    static Size zero();
};

#endif
