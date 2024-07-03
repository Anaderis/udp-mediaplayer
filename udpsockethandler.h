#ifndef UDPSOCKETHANDLER_H
#define UDPSOCKETHANDLER_H

#include <QObject>
#include <QUdpSocket>

class UdpSocketHandler : public QObject {
    Q_OBJECT

public:
    explicit UdpSocketHandler(QObject *parent = nullptr);

private slots:
    void readPendingDatagrams();

private:
    QUdpSocket *udpSocketGet;
};

#endif // UDPSOCKETHANDLER_H
