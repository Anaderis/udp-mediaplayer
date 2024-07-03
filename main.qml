import QtQuick 2.5
import QtQuick.Controls 1.4
import QtMultimedia 5.5

ApplicationWindow {
    visible: true
    width: 1280
    height: 720
    title: "UDP Video Player"

    MediaPlayer {
        id: mediaPlayer
        source: "file:///C:/Users/anais.kajjaj/Documents/networking/output.ts"
        autoPlay: true

        onPlaybackStateChanged: {
            console.log("Media player state:", mediaPlayer.playbackState)
        }

        onError: {
            console.error("MediaPlayer error:", errorString)
        }

        onStatusChanged: {
            console.log("Media player status:", mediaPlayer.status)
        }


    }

    VideoOutput {
        anchors.fill: parent
        source: mediaPlayer
    }

    Timer {
           interval: 5000 // 5 seconds
           repeat: true
           running: true
           onTriggered: {
               console.log("Refreshing MediaPlayer source")
               mediaPlayer.stop()
               mediaPlayer.source = ""
               mediaPlayer.source = "file:///C:/Users/anais.kajjaj/Documents/networking/output.ts"
               mediaPlayer.play()
           }
       }

}
