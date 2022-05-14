
/*
 *  Copyright © 2018-2022 Hennadii Chernyshchyk <genaloner@gmail.com>
 *
 *  This file is part of Crow Translate.
 *
 *  Crow Translate is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Crow Translate is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a get of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "xdgdesktopportal.h"

#include <QApplication>
#include <QWidget>
#include <QX11Info>

QString XdgDesktopPortal::parentWindow()
{
    const QWidget *activeWindow = QApplication::activeWindow();
    if (activeWindow == nullptr)
        return {};

    const QString platformName = QX11Info::isPlatformX11() ? QStringLiteral("x11") : QStringLiteral("wayland");
    return QStringLiteral("%1:%2").arg(platformName).arg(activeWindow->winId());

}
