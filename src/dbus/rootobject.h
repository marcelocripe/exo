/* ========================================================================
*    Copyright (C) 2013-2016 Blaze <blaze@vivaldi.net>
*
*    This file is part of eXo.
*
*    eXo is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    eXo is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with eXo.  If not, see <http://www.gnu.org/licenses/>.
* ======================================================================== */

#ifndef ROOTOBJECT_H
#define ROOTOBJECT_H

#include <QObject>

#include <QDBusAbstractAdaptor>
#include <QObject>

class RootObject : public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.mpris.MediaPlayer2")
    Q_PROPERTY(bool CanQuit READ canQuit)
    Q_PROPERTY(bool CanRaise READ canRaise)
    Q_PROPERTY(QString DesktopEntry READ desktopEntry)
    Q_PROPERTY(bool HasTrackList READ hasTrackList)
    Q_PROPERTY(QString Identity READ identity)

public:
    explicit RootObject(QObject *parent = 0);
    virtual ~RootObject();
    bool canQuit() const;
    bool canRaise() const;
    QString desktopEntry() const;
    bool hasTrackList() const;
    QString identity() const;

signals:

public slots:
    void Quit();
    void Raise();
};

#endif // ROOTOBJECT_H