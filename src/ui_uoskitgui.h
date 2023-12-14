/********************************************************************************
** Form generated from reading UI file 'uoskitgui.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UOSKITGUI_H
#define UI_UOSKITGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UoskitGui
{
public:
    QGridLayout *gridLayout_3;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLineEdit *path_line;
    QFrame *frame;
    QGridLayout *gridLayout;
    QPushButton *software_btn;
    QPushButton *clone_btn;

    void setupUi(QWidget *UoskitGui)
    {
        if (UoskitGui->objectName().isEmpty())
            UoskitGui->setObjectName(QStringLiteral("UoskitGui"));
        UoskitGui->resize(399, 512);
        gridLayout_3 = new QGridLayout(UoskitGui);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        widget = new QWidget(UoskitGui);
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        path_line = new QLineEdit(widget);
        path_line->setObjectName(QStringLiteral("path_line"));

        gridLayout_2->addWidget(path_line, 0, 0, 1, 1);

        frame = new QFrame(widget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        software_btn = new QPushButton(frame);
        software_btn->setObjectName(QStringLiteral("software_btn"));

        gridLayout->addWidget(software_btn, 0, 1, 1, 1);

        clone_btn = new QPushButton(frame);
        clone_btn->setObjectName(QStringLiteral("clone_btn"));

        gridLayout->addWidget(clone_btn, 0, 0, 1, 1);


        gridLayout_2->addWidget(frame, 1, 0, 1, 1);


        gridLayout_3->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(UoskitGui);

        QMetaObject::connectSlotsByName(UoskitGui);
    } // setupUi

    void retranslateUi(QWidget *UoskitGui)
    {
        UoskitGui->setWindowTitle(QApplication::translate("UoskitGui", "UoskitGui", nullptr));
        software_btn->setText(QApplication::translate("UoskitGui", "\345\256\211\350\243\205\350\275\257\344\273\266", nullptr));
        clone_btn->setText(QApplication::translate("UoskitGui", "\345\205\213\351\232\206\351\241\271\347\233\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UoskitGui: public Ui_UoskitGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UOSKITGUI_H
