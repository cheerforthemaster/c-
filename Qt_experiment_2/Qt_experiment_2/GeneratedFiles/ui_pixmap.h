/********************************************************************************
** Form generated from reading UI file 'pixmap.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PIXMAP_H
#define UI_PIXMAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_pixmap
{
public:

    void setupUi(QDialog *pixmap)
    {
        if (pixmap->objectName().isEmpty())
            pixmap->setObjectName(QStringLiteral("pixmap"));
        pixmap->resize(400, 300);

        retranslateUi(pixmap);

        QMetaObject::connectSlotsByName(pixmap);
    } // setupUi

    void retranslateUi(QDialog *pixmap)
    {
        pixmap->setWindowTitle(QApplication::translate("pixmap", "pixmap", 0));
    } // retranslateUi

};

namespace Ui {
    class pixmap: public Ui_pixmap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PIXMAP_H
