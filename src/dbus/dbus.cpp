/* ========================================================================
*    Copyright (C) 2013-2022 Blaze <blaze@vivaldi.net>
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

#include <QObject>
#include <QDBusConnection>

#include "bookmarkmanager.h"
#include "trayicon.h"
#include "playerinterface.h"
//MPRISv2
#include "rootobject.h"
#include "playerobject.h"

#include "dbus.h"


class DBusAdaptor : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "local.exo_player")

public:
    explicit DBusAdaptor(QObject* parent = nullptr) : QObject(parent) {}

public Q_SLOTS:
    void showLyricsWindow() {
        if(TrayIcon::self())
            TrayIcon::self()->showLyricsWindow();
    }
    void bookmarkCurrent() { BookmarkManager::bookmarkCurrent(); }
    void clearPlaylist() { PLAYER->clearPlaylist(); }
};


void DBus::init(QObject* parent) {
    QDBusConnection connection = QDBusConnection::sessionBus();
    connection.registerObject(QStringLiteral("/exo"), new DBusAdaptor(parent),
                              QDBusConnection::ExportAllContents);
    if(!connection.registerService(QStringLiteral("local.exo_player")))
        qWarning("DBus: service registration failed");
    new RootObject(parent);
    new PlayerObject(parent);
    connection.registerObject(QStringLiteral("/org/mpris/MediaPlayer2"),parent);
    if(!connection.registerService(
                QStringLiteral("org.mpris.MediaPlayer2.exo")))
        qWarning("DBus: MPRISv2 service registration failed");
}

#include "dbus.moc"
