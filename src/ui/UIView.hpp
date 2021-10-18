/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UIView.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <bpisano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:01:02 by bpisano           #+#    #+#             */
/*   Updated: 2021/09/22 14:34:59 by bpisano          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef UIVIEW_HPP
#define UIVIEW_HPP

#include "Frame.hpp"

class UIView
{
private:
    Frame frame = Frame::zero();

    void moveToOrigin();
    void clean();

protected:
    // Rendering
    void prepareForRender();
    void render();

public:
    UIView();

    // Coordinates
    Position position();
    Size size();
    void setSize(int width, int height);
    void setPosition(int x, int y);
};

#endif
