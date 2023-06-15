#include "mainwindow.h"
#include "interactive_canvas.cpp"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "NPS_Qt_Cpp_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    QMainWindow mainWindow;
    Canvas *canvas = new Canvas(&mainWindow);
    mainWindow.setCentralWidget(canvas);
    mainWindow.setGeometry(100, 100, 800, 600);
    mainWindow.show();
    return a.exec();
}
