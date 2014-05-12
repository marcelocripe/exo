/* ========================================================================
*    Copyright (C) 2013-2014 Blaze <blaze@jabster.pl>
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

#include <QNetworkProxy>
#include <QRegExp>
#include "exo.h"

int main(int argc, char *argv[]) {
    Q_INIT_RESOURCE(exo);
    bool useGui = true;
    for(int i=1; i<argc; i++) {
        QByteArray arg = argv[i];
        if(arg == "-d" || arg == "--daemonize")
            useGui = false;
        else if(arg == "-p" || arg == "--proxy") {
            QString address = argv[++i];
            QRegExp addressRgx ("([\\w\\.]+):(\\d+)");
            addressRgx.indexIn(address);
            QNetworkProxy proxy;
            proxy.setType(QNetworkProxy::HttpProxy);
            proxy.setHostName(addressRgx.cap(1));
            proxy.setPort(addressRgx.cap(2).toInt());
            QNetworkProxy::setApplicationProxy(proxy);
        }
    }
    QString appName = "eXo";
    QString orgName = "exo";
    Exo app(argc, argv, useGui, appName, orgName);
    app.setApplicationVersion("0.2");
    app.setQuitOnLastWindowClosed(false);
    return app.exec();
}
