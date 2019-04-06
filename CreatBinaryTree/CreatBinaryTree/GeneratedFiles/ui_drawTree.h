/********************************************************************************
** Form generated from reading UI file 'drawTree.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAWTREE_H
#define UI_DRAWTREE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_drawTree
{
public:

    void setupUi(QDialog *drawTree)
    {
        if (drawTree->objectName().isEmpty())
            drawTree->setObjectName(QStringLiteral("drawTree"));
        drawTree->resize(800, 600);

        retranslateUi(drawTree);

        QMetaObject::connectSlotsByName(drawTree);
    } // setupUi

    void retranslateUi(QDialog *drawTree)
    {
        drawTree->setWindowTitle(QApplication::translate("drawTree", "drawTree", 0));
    } // retranslateUi

};

namespace Ui {
    class drawTree: public Ui_drawTree {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAWTREE_H
