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

#ifndef SCROBBLER_H
#define SCROBBLER_H

#include <QObject>

namespace lastfm {
    class Audioscrobbler;
}

class Scrobbler : public QObject
{
    Q_OBJECT

    lastfm::Audioscrobbler* as;

public:
    Scrobbler(QObject *parent = 0);
    ~Scrobbler();
    static const char* apiKey;
    static const char* secret;

private slots:
    void init(QString, QString, int);
    void submit(QString, QString, QString, int);
};

#endif // SCROBBLER_H
