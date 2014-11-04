/*
 * Copyright (C) 2014 Canonical, Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

import QtQuick 2.0
import QtMultimedia 5.0
import ScreenGrabber 0.1

Rectangle {
    id: root
    enabled: true
    visible: false
    color: "white"
    anchors.fill: parent
    opacity: 0.0

    ScreenGrabber {
        id: screenGrabber
        objectName: "screenGrabber"
    }

    Audio {
        id: shutterSound
        audioRole: MediaPlayer.alert
        source: "/system/media/audio/ui/camera_click.ogg"
    }

    function capture() {
        if (!enabled)
            return;

        visible = true;
        shutterSound.stop();
        shutterSound.play();
        fadeIn.start();
    }

    NumberAnimation on opacity {
        id: fadeIn
        from: 0.0
        to: 1.0
        onStopped: {
            if (visible) {
                fadeOut.start();
            }
        }
    }

    NumberAnimation on opacity {
        id: fadeOut
        from: 1.0
        to: 0.0
        onStopped: {
            if (visible) {
                screenGrabber.captureAndSave();
                visible = false;
            }
        }
    }
}