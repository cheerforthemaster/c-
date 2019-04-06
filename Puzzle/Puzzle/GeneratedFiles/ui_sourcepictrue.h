/********************************************************************************
** Form generated from reading UI file 'sourcepictrue.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOURCEPICTRUE_H
#define UI_SOURCEPICTRUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_sourcePictrue
{
public:

    void setupUi(QDialog *sourcePictrue)
    {
        if (sourcePictrue->objectName().isEmpty())
            sourcePictrue->setObjectName(QStringLiteral("sourcePictrue"));
        sourcePictrue->resize(550, 733);

        retranslateUi(sourcePictrue);

        QMetaObject::connectSlotsByName(sourcePictrue);
    } // setupUi

    void retranslateUi(QDialog *sourcePictrue)
    {
        sourcePictrue->setWindowTitle(QApplication::translate("sourcePictrue", "sourcePictrue", 0));
    } // retranslateUi

};

namespace Ui {
    class sourcePictrue: public Ui_sourcePictrue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOURCEPICTRUE_H
