#include "udpSocketHandler.h"
#include <QDebug>
#include <QFile>

UdpSocketHandler::UdpSocketHandler(QObject *parent)
    : QObject(parent),
      udpSocketGet(new QUdpSocket(this))
{
    qDebug() << "Attempting to bind UDP socket to localhost on port 12345...";
    bool bindResult = udpSocketGet->bind(QHostAddress::AnyIPv4, 12345);
    if (!bindResult) {
        qDebug() << "Failed to bind UDP socket:" << udpSocketGet->errorString();
    } else {
        qDebug() << "UDP socket bound successfully to port 12345.";
    }
    while (udpSocketGet->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocketGet->pendingDatagramSize());
        udpSocketGet->readDatagram(datagram.data(), datagram.size());

        //qDebug() << "Received datagram:" << datagram;
    }

    connect(udpSocketGet, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));

}


void UdpSocketHandler::readPendingDatagrams() {
    //qDebug() << "Checking for pending datagrams...";

    while (udpSocketGet->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocketGet->pendingDatagramSize());
        udpSocketGet->readDatagram(datagram.data(), datagram.size());

        // Write the datagram to a file
        QFile file("C:/Users/anais.kajjaj/Documents/networking/output.ts");
        if (file.open(QIODevice::Append)) {
            file.write(datagram);
            file.close();
        } else {
            qDebug() << "Unable to open file for writing";
        }
        //qDebug() << "Received datagram:" << datagram;
    }
}




