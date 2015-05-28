#include"settings.h"
#include "myclass.h"


#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QTranslator>
#include <QDebug>
#include <QQuickView>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<GAMEPLAY>("CppToQml", 2, 0, "GamePlay");


    /********************************************************************/

    Settings settings(0, "Peter", "2048-Qt");
   // settings.setVersion(QString(APP_VERSION));

    // Localization
    QString locale;
    if (settings.contains("language")) {
        locale = settings.value("language").toString();
    } else {
        locale = QLocale::system().name();
        settings.setValue("language", locale);
    }

    QTranslator translator;
    if (! locale.startsWith("en")) {
        QString tsFile = locale;

        if (translator.load(":/ts"))
        {
            qDebug() << "Successfully loaded " + tsFile;
            app.installTranslator(&translator);
        } else {
            qDebug() << "Failed to load " + tsFile;
        }
    }

    QQmlApplicationEngine engine;


    // Access C++ object "GamePLay" from QML as "GamePLay"
    GAMEPLAY GamePlay;
    engine.rootContext()->setContextProperty("GamePlay", &GamePlay);



    // Access C++ object "settings" from QML as "settings"
    engine.rootContext()->setContextProperty("settings", &settings);

    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));



    return app.exec();
}
