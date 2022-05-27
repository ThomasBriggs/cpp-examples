// Include header files for application components.
// ...

#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget window;
    window.resize(320, 240);
    window.show();
    window.setWindowTitle(
        QApplication::translate("toplevel", "Top-level widget"));

    window.show();

    QPushButton button = QPushButton(
        QApplication::translate("childwidget", "press me!"), &window);

    button.move(100, 100);
    button.show();
    return app.exec();
}