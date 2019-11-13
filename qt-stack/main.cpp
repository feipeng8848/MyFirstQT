#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <user.h>


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    const QUrl url(QStringLiteral("qrc:/main.qml"));

    //连接信号和槽
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    //设置context
    User u("王正坤",80);
    engine.rootContext()->setContextProperty("context", &u);


    //载入UI文件
    engine.load(url);

    return app.exec();
}
