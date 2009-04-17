// openhomm - open source clone of Heroes of Might and Magic III
// Copyright (C) 2009 openhomm developers team (see AUTHORS)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
#pragma once

#include "precompiled.hpp"

class hrSceneObject
{
    QString name;
    QRect rect;
    quint8 visitable[6];
    bool overlay;
public:
    hrSceneObject() { name = "default.def"; }
    hrSceneObject(const QString &name
                  , quint8 *visit
                  , bool overlay
                  , int x
                  , int y
                  , int width
                  , int height) : name(name), overlay(overlay)
    {
        memcpy(visitable, visit, 6);
        rect.setRect(x - width + 1, y - height + 1, width, height);
    }
    hrSceneObject(const QString &name
                  , quint8 *visit
                  , bool overlay
                  , int x
                  , int y) : name(name), overlay(overlay)
    {
        memcpy(visitable, visit, 6);
        rect.setX(x);
        rect.setY(y);
    }
    quint8* getVisitable()
    {
        return visitable;
    }
    bool isVisitable() const
    {
        for ( quint8 i = 0; i < 6; i++)
            if ( visitable[i] != 0 )
                return true;

        return false;
    }

    bool operator<(const hrSceneObject& s) const;

    bool isOverlay() const
    {
        return overlay;
    }
    QString getName() const
    {
        return name;
    }
    QPoint getPoint() const
    {
        return QPoint(x(), y());
    }
    int x() const
    {
        return rect.x();
    }
    int y() const
    {
        return rect.y();
    }
    QRect getRect() const
    {
        return rect;
    }
};
