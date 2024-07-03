#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QUdpSocket>
#include "udpSocketHandler.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    UdpSocketHandler handler;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("udpSocketHandler", &handler);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
