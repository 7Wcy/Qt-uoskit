#ifndef UOSKITGUI_H
#define UOSKITGUI_H

#include <QWidget>
#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QFileDialog>
#include <QProcess>
#include <QProcessEnvironment>
#include <QDebug>
#include <QProgressDialog>

namespace Ui {
class UoskitGui;
}

class UoskitGui : public QWidget
{
    Q_OBJECT

public:
    explicit UoskitGui(QWidget *parent = nullptr);
    ~UoskitGui();

signals:

public slots:
    void onCloneProject();
    void onInstallSoftware();

private:
    Ui::UoskitGui *ui;
};

#endif // UOSKITGUI_H
